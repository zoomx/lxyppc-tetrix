-- Quad Flight Monitor
dofile("control.lua")
dofile("quadviewer.lua")
dofile("language.lua")
dofile("waveviewer.lua")
dofile("quadsetting.lua")
dofile("rcviewer.lua")
dofile("serial_parser.lua")
class "QuadMonitor"(QFrame)

PI = 3.1415926535
function ang2rad(ang)
    return ang*PI/180
end
function rad2ang(rad)
    return rad*180/PI
end

--- USB Device VID and PID
QuadMonitor.vid = 0x250
QuadMonitor.pid = 0x250
QuadMonitor.SET_ATT = 0x01
QuadMonitor.SET_MOTOR = 0x02
QuadMonitor.SET_MODE = 0x03

function QuadMonitor:__init()
    QFrame.__init(self)
    self.windowTitle = loadStr("Title")
    self.devList = QComboBox() {minw = 150}
    self.devPath = QLineEdit() { readonly = true}
    local usb_devs = QUsbHid.enumDevices(self.vid,self.pid)
    local serial_devs = QSerialPort.enumPort()

    self:add_devs(usb_devs, serial_devs)

    self.hid = QUsbHid(self)
    self.hid.isOpen = false
    self.serial = QSerialPort(self)
    self.serial.flowControl = QSerialPort.FLOW_OFF 
    self.serial.baudRate = QSerialPort.BAUD115200
    self.serialParser = SerialParser()
    self.serialParser.get_data = {self, self.incomingData}

    self.btnOpen = QPushButton(loadStr("Open"))
    self.btnSend = QPushButton(loadStr("Send"))
    self.recvEdit = QHexEdit(){ readonly = true, overwriteMode = false }
    self.btnClear = QPushButton(loadStr("Clear")){
        clicked = function() self.recvEdit:clear() end
    }
    self.btnRefresh = QPushButton(loadStr("Refresh")){
        clicked = function()
            local devs = QUsbHid.enumDevices(self.vid,self.pid)
            local serial_devs = QSerialPort.enumPort()
            self:add_devs(devs, serial_devs)
        end
    }

    self.quadview = QuadViewer()

    self.waveSensor = WaveViewer()
    self.waveSensor:addData("GyroX")
    self.waveSensor:addData("GyroY")
    self.waveSensor:addData("GyroZ")
    self.waveSensor:addData("AccX")
    self.waveSensor:addData("AccY")
    self.waveSensor:addData("AccZ")
    self.waveSensor:addData("MagX")
    self.waveSensor:addData("MagY")
    self.waveSensor:addData("MagZ")

    self.quadSetup = QuadSetting()
    self.quadSetup.valueChanged = function(r,reason)
        local data = {self.DT_ATT,3}
        local v = 0
        for i=1,3 do
            v = r.angle[i]/1000.0*360.0
            v = ang2rad(v)
            data = QUtil.fromFloat(data, v)
        end
        v = r.thro
        data = QUtil.fromFloat(data, v)
        
        for i=1,4 do
            v = r.motor[i]
            data = QUtil.fromFloat(data, v)
        end
        local res = self:parse_data(data)
        update_quad_viewer(res)
    end

    self.rcview = RCViewer()

    self.states = QTabWidget()
    self.states:addTab(self.quadview, loadStr("Attitude Data"))
    self.states:addTab(self.waveSensor, loadStr("Sensor Data"))
    self.states:addTab(self.rcview, loadStr("RC Data"))
    --self.states:addTab(self.quadSetup, loadStr("Settings"))

    
    self.states.currentChanged = function(idx)
        if idx == 0 then
            self:changeMode(self.DT_ATT)
        elseif idx == 1 then
            self:changeMode(self.DT_SENSOR)
        elseif idx == 2 then
            self:changeMode(self.DT_RCDATA)
        end
    end

    self.layout = QVBoxLayout{
        --self.devPath,
        QHBoxLayout{
            self.devList, self.btnOpen, self.btnRefresh,QLabel(""), strech = "0,0,0,1"
        },
        self.states,
        self.quadSetup,
        strech = "0,1,0",
    }

    self.btnOpen.clicked = function()
        local path = self.devList:itemData(self.devList.currentIndex).path
        local isSerial = false
        if path == nil then
            path = self.devList:itemData(self.devList.currentIndex).portName
            isSerial = true
            if path == nil then
                return
            end
        end
        if self.hid.isOpen or self.serial.isOpen then
            if self.hid.isOpen then
                self.hid:close()
                self.hid.isOpen = false
                log("USB closed")
            else
                self.serial:close()
                log("Serial closed")
            end
            self.btnOpen.text = loadStr("Open")            

        else
            if isSerial then
            self.serial.portName = path
            res = self.serial:open()
            if res then
                self.btnOpen.text = loadStr("Close")
                log("Opne:" .. path .. "  success")
            else
                log(self.serial.errorString)
                log("Opne:" .. path .. "  fail")
            end
            else
            self.hid.path = path
            self.hid.isOpen = self.hid:open()
            if self.hid.isOpen then
                self.btnOpen.text = loadStr("Close")
                log("Opne:" .. path .. "  success")
            else
                log(self.hid.errorString)
                log("Opne:" .. path .. "  fail")
            end
            end
        end
        
    end
    
    self.devList.currentIndexChanged = function()
        local path = self.devList:itemData(self.devList.currentIndex).path
        self.devPath.text = path or ""
    end

    function update_quad_viewer(v)
        if v.angle and v.motorSpeed then 
            self.quadview:updateAngle(v.angle)
            self.quadview:updateHeight(v.throttle / 2000 * 0.8)
            self.quadview:updateMotor(v.motorSpeed)
        end
    end

    self.serial.readyRead = function()
        self.serialParser:parse_data(self.serial:readAll())
    end

    self.hid.readyRead = function()
        local data = self.hid:readAll()
        --log(#data)
        self:incomingData(data)
        --self.recvEdit.data = data
    end

    function update_sensors(v)
        if v.gyro and v.acc and v.mag then
            for i=1,3 do
                local val = v.gyro[i]
                local name = self.waveSensor.nameList[i]
                --self.sensorsCtrl[i][2].text = "" .. val-- .. "," .. val
                --self.sensorsData[i][#self.sensorsData[i]+1] = val
                self.waveSensor.elements[name].edit.text = ""..val
                self.waveSensor.elements[name].data[#self.waveSensor.elements[name].data + 1] = val
            end
            for i=1,3 do
                local val = v.acc[i]
                --self.sensorsCtrl[i+3][2].text = "" .. val-- .. "," .. val
                --self.sensorsData[i+3][#self.sensorsData[i+3]+1] = val
                local name = self.waveSensor.nameList[i+3]
                self.waveSensor.elements[name].edit.text = ""..val
                self.waveSensor.elements[name].data[#self.waveSensor.elements[name].data + 1] = val
            end
            for i=1,3 do
                local val = v.mag[i]
                --self.sensorsCtrl[i+6][2].text = "" .. val-- .. "," .. val
                --self.sensorsData[i+6][#self.sensorsData[i+6]+1] = val
                local name = self.waveSensor.nameList[i+6]
                self.waveSensor.elements[name].edit.text = ""..val
                self.waveSensor.elements[name].data[#self.waveSensor.elements[name].data + 1] = val
            end
        end
    end

--[[ test code begin 
    self.testDataP = 0
    self.eventFilter = QTimerEvent.filter(
    function(obj,evt)
        local v = {}
        local phase = 20
        local range = 1000
        v.gryo = {
            math.sin( (self.testDataP + 1*phase)/50)*range,
            math.sin( (self.testDataP + 2*phase)/50)*range,
            math.sin( (self.testDataP + 3*phase)/50)*range,
        }
        v.acc = {
            math.sin( (self.testDataP + 4*phase)/50)*range,
            math.sin( (self.testDataP + 5*phase)/50)*range,
            math.sin( (self.testDataP + 6*phase)/50)*range,
        }
        v.mag = {
            math.sin( (self.testDataP + 7*phase)/50)*range,
            math.sin( (self.testDataP + 8*phase)/50)*range,
            math.sin( (self.testDataP + 9*phase)/50)*range,
        }
        update_sensors(v)
        --for i=1,9 do
        --    local idx = #self.sensorsData[i] + 1
        --    self.sensorsData[i][idx] = math.sin( (self.testDataP + i*5)/50)*800
        --end
        self.testDataP = self.testDataP + 1
    end)
    self.testTimerID = self:startTimer(10)
--]] -- test code end
end
--[[ Parse recieved data to structure
struct {
    float     angle[3];       // Pitch, roll, yaw
    float     motorSpeed[4];  //
    uint32_t  exeTime;        // code execute time
}

]]

function QuadMonitor:changeMode(mode)
    local data = {self.SET_MODE, mode}
    if self.hid.isOpen then
        local r = self.hid:writeData(0, data)
        log("Write: " .. r .. " bytes mode data, change mode to " .. mode)
        log(self.hid.errorString)
    end
    if self.serial.isOpen then
        local r = self.serial:write( self.serialParser:pack_data(data))
        log("Write: " .. r .. " bytes mode data, change mode to " .. mode)
        log(self.serial.errorString)
    end
end

function QuadMonitor:incomingData(data)
    local r = self:parse_data(data)
    if r.angle then
        -- got attitude data
        update_quad_viewer(r)
    elseif r.gyro then
        -- got sensor data
        update_sensors(r)
    elseif r.rc then
        -- got RC data
        self.rcview:setChannel(r.rc)
    end
end

function QuadMonitor:add_devs(usb_devs, serial_devs)
    self.devList:clear()
    table.foreach(usb_devs, function (k,v)
        if k == 1 then
            self.devPath.text = v.path
        end
        self.devList:addItem(v.friendName, v)  
    end)
    
    table.foreach(serial_devs, function (k,v)
        if k == 1 then
            self.devPath.text = v.portName
        end
        self.devList:addItem(v.portName, v)  
    end)
end



QuadMonitor.DT_ATT = 1
QuadMonitor.DT_SENSOR = 2
QuadMonitor.DT_RCDATA = 3
function QuadMonitor:parse_data(data)
    local r = {}
    if data[1] == QuadMonitor.DT_ATT then
        --log("Got attitude data")
        local att_count = data[2]
        r.angle = {}
        r.angle[QuadView.PITCH] = att_count > 0 and rad2ang( QUtil.toFloat(data,3) ) or 0
        r.angle[QuadView.ROLL] = att_count > 1 and rad2ang( QUtil.toFloat(data,7) ) or 0
        r.angle[QuadView.YAW] = att_count > 2 and rad2ang( QUtil.toFloat(data,11) ) or 0
        r.throttle = att_count > 3 and QUtil.toFloat(data,15) or 0
        r.motorSpeed = {}
        r.motorSpeed[1] = att_count > 4 and QUtil.toFloat(data,19) or 0
        r.motorSpeed[2] = att_count > 5 and QUtil.toFloat(data,23) or 0
        r.motorSpeed[3] = att_count > 6 and QUtil.toFloat(data,27) or 0
        r.motorSpeed[4] = att_count > 7 and QUtil.toFloat(data,31) or 0

    elseif data[1] == QuadMonitor.DT_SENSOR then
        --log("Got sensor data")
        local sensor_count = data[2]
        r.gyro = {}
        r.gyro[1] = sensor_count > 0 and QUtil.toInt16(data,3) or 0
        r.gyro[2] = sensor_count > 1 and QUtil.toInt16(data,5) or 0
        r.gyro[3] = sensor_count > 2 and QUtil.toInt16(data,7) or 0
        r.acc = {}
        r.acc[1] = sensor_count > 3 and QUtil.toInt16(data,9) or 0
        r.acc[2] = sensor_count > 4 and QUtil.toInt16(data,11) or 0
        r.acc[3] = sensor_count > 5 and QUtil.toInt16(data,13) or 0
        r.mag = {}
        r.mag[1] = sensor_count > 6 and QUtil.toInt16(data,15) or 0
        r.mag[2] = sensor_count > 7 and QUtil.toInt16(data,17) or 0
        r.mag[3] = sensor_count > 8 and QUtil.toInt16(data,19) or 0
        --log(QUtil.showBytes(r.gryo))
    elseif data[1] == QuadMonitor.DT_RCDATA then
        --log("Got remote control data")
        local channel = data[2]
        r.rc = {}
        for i=1,channel do
            r.rc[#r.rc + 1] = QUtil.toUint16(data,1 + i*2)
        end
    end
    return r
end

-- Dialog wrapper
class "QuadMonitorDlg"(QDialog)
function QuadMonitorDlg:__init()
    QDialog.__init(self)
    self.windowTitle = "Quad Flight Monitor"
    self.layout = QVBoxLayout {QuadMonitor()}
end
