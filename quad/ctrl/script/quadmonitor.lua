-- Quad Flight Monitor
dofile("quadviewer.lua")
class "QuadMonitor"(QFrame)

PI = 3.1415926535
function ang2rad(ang)
    return ang*PI/180
end
function rad2ang(rad)
    return rad*180/PI
end
Lang = { Eng = 1, Chn = 2}
Lang[Lang.Eng] = {
    ["Title"] = "Quad Flight Monitor",
}
Lang[Lang.Chn] = {
    ["Title"] = "四轴监控器",
    ["Open"] = "打开",
    ["Send"] = "发送",
    ["Close"] = "关闭",
    ["Clear"] = "清除",
    ["Refresh"] = "刷新",
    ["Pitch"] = "俯仰",
    ["Roll"] = "横滚",
    ["Yaw"] = "偏航",
    ["Motor"] = "电机",
    ["exeTime"] = "执行时间",
    ["Thro"] = "油门",
    ["Preview"] = "预览",
    ["Angle"] = "角度",
    ["Attitude Data"] = "姿态数据",
    ["Parame Set"] = "参数设置",
    ["Quad Set"] = "四轴设置",
    ["Motor Set"] = "电机设置",
    ["Set"] = "设置",
    ["Gyro"] = "角速度",
    ["Acc"] = "加速度",
    ["Mag"] = "磁场",
    ["Sensor"] = "传感器",
    ["Sensor Data"] = "传感器数据",
}

Lang.current = Lang.Chn
function loadStr(id)
    return Lang[Lang.current][id] or id
end

--- USB Device VID and PID
QuadMonitor.vid = 0x250
QuadMonitor.pid = 0x250
QuadMonitor.SET_ATT = 0x01
QuadMonitor.SET_MOTOR = 0x02
QuadMonitor.SET_MODE = 0x03

-- implement a slider with value display ---------
class "QValueSlider"(QFrame)
function QValueSlider:__init(v)
    QFrame.__init(self)
    self.slider = QSlider(v)
    self.label = QLabel()-- { minw=40,maxw=40}
    self.offset = 0
    self.ratio = 1
    self.unit = ""
    self.slider.valueChanged = {self, self.valueSliderChanged}
    self.layout = QHBoxLayout{
        self.slider, self.label
    }
    self.maxh = 20
    self:valueSliderChanged()
    self.valueChanged = nil
end

function QValueSlider:__call(v)
    if v.max then self.slider.max = v.max end
    if v.min then self.slider.min = v.min end
    if v.minw then self.minw = v.minw end
    if v.maxw then self.maxw = v.maxw end
    if v.offset then self.offset = v.offset end
    if v.ratio then self.ratio = v.ratio end
    if v.unit then self.unit = v.unit end
    if v.valueChanged then self.valueChanged = v.valueChanged end
    self:valueSliderChanged()
    return self
end

function QValueSlider:valueSliderChanged()
    self.label.text = (self.slider.value + self.offset)*self.ratio .. self.unit
    local t = self.valueChanged and self.valueChanged()
end
-- implement a slider with value display end ----------

-- implement color selection button -----------
class "QColorButton" (QToolButton)
function QColorButton:__init(color)
    QToolButton.__init(self)
    self.color = QColor(color) or QColor("gray")
    self.styleSheet = "background:"..self.color.name
    self.clicked = {self,self.changeColor}
end

function QColorButton:changeColor()
    local color = QCommonDlg.getColor(self.color)
    if color.isValid then
        self.color = color
    end
    self.styleSheet = "background:"..self.color.name
    local t = self.colorChanged and self.colorChanged()
end
-- implement color selection button end -------

function QuadMonitor:__init()
    QFrame.__init(self)
    self.windowTitle = loadStr("Title")
    self.devList = QComboBox()
    self.devPath = QLineEdit() { readonly = true}
    local usb_devs = QUsbHid.enumDevices(self.vid,self.pid)

    function add_devs(devs)
        self.devList:clear()
        table.foreach(devs, function (k,v)
            if k == 1 then
                self.devPath.text = v.path
            end
            self.devList:addItem(v.friendName, v)  
        end)
    end

    add_devs(usb_devs)

    self.hid = QUsbHid(self)
    self.hid.isOpen = false
    self.btnOpen = QPushButton(loadStr("Open"))
    self.btnSend = QPushButton(loadStr("Send"))
    self.recvEdit = QHexEdit(){ readonly = true, overwriteMode = false }
    self.btnClear = QPushButton(loadStr("Clear")){
        clicked = function() self.recvEdit:clear() end
    }
    self.btnRefresh = QPushButton(loadStr("Refresh")){
        clicked = function()
            local devs = QUsbHid.enumDevices(self.vid,self.pid)
            add_devs(devs)
        end
    }
    self.quadview = get_quad_view(self)
    self.quadpreview = QGroupBox(loadStr("Preview")){
        layout = QVBoxLayout{self.quadview}
    }

    self.status = {
        {loadStr("Pitch"), QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Roll"), QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Yaw"), QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Motor").."1", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Motor").."2", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Motor").."3", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Motor").."4", QLineEdit("0"){readonly=true, minw = 60}},
    }
    self.motorColor = {
        QColorButton("#00ff00"),
        QColorButton("#00ff00"),
        QColorButton("#00ff00"),
        QColorButton("#00ff00"),
    }
    
    function motor_color_changed()
        for i=1,4 do
            self.quadview.motorColor[i] = self.motorColor[i].color
        end
    end
    
    for i=1,4 do
        self.motorColor[i].colorChanged = motor_color_changed
    end

    self.angleParams = QGroupBox(loadStr("Angle")){
        layout = QFormLayout{self.status[1],self.status[2],self.status[3]}
    }
    self.motorParams = QGroupBox(loadStr("Motor")){
        layout = QFormLayout{
            {self.status[4][1], QHBoxLayout{self.status[4][2], self.motorColor[1]} },
            {self.status[5][1], QHBoxLayout{self.status[5][2], self.motorColor[2]} },
            {self.status[6][1], QHBoxLayout{self.status[6][2], self.motorColor[3]} },
            {self.status[7][1], QHBoxLayout{self.status[7][2], self.motorColor[4]} },
        }
    }

    self.sensors = {
        {loadStr("Gyro").."X", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Gyro").."Y", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Gyro").."Z", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Acc").."X", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Acc").."Y", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Acc").."Z", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Mag").."X", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Mag").."Y", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Mag").."Z", QLineEdit("0"){readonly=true, minw = 60}},
    }
    self.sensorParams = QGroupBox(loadStr("Sensor")){
        layout = QFormLayout( self.sensors )
    }

    self.currentState = QGroupBox(loadStr("Attitude Data")){
        layout = QHBoxLayout{    
            QVBoxLayout{ self.angleParams, self.motorParams },
            self.quadpreview,
            strech = "0,1",
        },
    }

    self.states = QTabWidget()
    self.states:addTab(self.currentState, loadStr("Attitude Data"))
    self.states:addTab(self.sensorParams, loadStr("Sensor Data"))
    self.states.currentChanged = function(idx)
        log(idx)
        local data = {0, self.SET_MODE}
        if idx == 0 then
            data[3] = self.DT_ATT
        elseif idx == 1 then
            data[3] = self.DT_SENSOR
        end
        local r = self.hid:writeData(data)
        log("Write: " .. r .. " bytes mode data")
        log(self.hid.errorString)
    end

    function update_quad_params()
        -- here send data to the quad copter
        local data = {self.DT_ATT}
        local v = 0
        for i=1,3 do
            v = ((self.quadparams[i].slider.value+self.quadparams[i].offset)/1000.0*360.0)
            v = ang2rad(v)
            data = QUtil.fromFloat(data, v)
        end
        v = self.quadparams[4].slider.value+self.quadparams[4].offset
        data = QUtil.fromFloat(data, v)
        
        for i=1,4 do
            v = self.motorparams[i].slider.value + self.motorparams[i].offset
            data = QUtil.fromFloat(data, v)
        end
        local r = self:parse_data(data)
        update_quad_viewer(r)
    end
    
    function update_motor_params()
        update_quad_params()
    end

    self.btnSetQuad = QPushButton(loadStr("Set")){maxw=40}
    
    self.quadcommands = {
        {loadStr("Roll"),  QValueSlider(1){min=2000, max=4000, minw = 60, offset = -3000, ratio = 720/2000}},
        {loadStr("Pitch"), QValueSlider(1){min=2000, max=4000, minw = 60, offset = -3000, ratio = 720/2000}},
        {loadStr("Yaw"),   QValueSlider(1){min=2000, max=4000, minw = 60, offset = -3000, ratio = 720/2000}},
        {loadStr("Thro"),  QValueSlider(1){min=2000, max=4000, minw = 60, offset = -2000}},
        {self.btnSetQuad,QLabel("")},
    }

    self.quadparams = {}
    for i=1,4 do
        self.quadparams[i] = self.quadcommands[i][2]
        self.quadparams[i].valueChanged = update_quad_params
        self.quadcommands[i][2] = QHBoxLayout{self.quadcommands[i][2].slider,self.quadcommands[i][2].label}        
    end

    self.quadSet = QGroupBox(loadStr("Quad Set")){
        layout = QFormLayout(self.quadcommands),
    }

    self.btnSetMotor = QPushButton(loadStr("Set")){maxw=40}

    self.motorparams = {}
    self.motorcommands = {
        {loadStr("Motor").."1", QValueSlider(1){min=0, max=2000} },
        {loadStr("Motor").."2", QValueSlider(1){min=0, max=2000} },
        {loadStr("Motor").."3", QValueSlider(1){min=0, max=2000} },
        {loadStr("Motor").."4", QValueSlider(1){min=0, max=2000} },
        {self.btnSetMotor,QLabel("")},
    }
    for i=1,4 do
        self.motorparams[i] = self.motorcommands[i][2]
        self.motorparams[i].valueChanged = update_motor_params
        self.motorcommands[i][2] = QHBoxLayout{self.motorcommands[i][2].slider,self.motorcommands[i][2].label}
    end
    
    self.motorSet = QGroupBox(loadStr("Motor Set")){
        layout = QFormLayout(self.motorcommands),
    }

    self.paramSet = QGroupBox(loadStr("Parame Set")){
        layout = QHBoxLayout{self.quadSet, self.motorSet},
    }

    self.layout = QVBoxLayout{
        self.devPath,
        QHBoxLayout{
            self.devList, self.btnOpen, self.btnRefresh,QLabel(""), strech = "0,0,0,1"
        },
        self.states,
        self.paramSet,
        strech = "0,1,0",
    }

    self.btnOpen.clicked = function()
        local path = self.devList:itemData(self.devList.currentIndex).path
        if path == nil then
            return
        end
        if self.hid.isOpen then
            self.hid:close()
            self.btnOpen.text = loadStr("Open")
            self.hid.isOpen = false
            log("Closed")
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
    
    self.btnSetQuad.clicked = function()
        -- here send data to the quad copter
        local data = {}
        local v = 0
        for i=1,3 do
            v = ((self.quadparams[i].slider.value+self.quadparams[i].offset)/1000.0*360.0)
            v = ang2rad(v)
            data = QUtil.fromFloat(data, v)
        end
        v = self.quadparams[4].slider.value+self.quadparams[4].offset
        data = QUtil.fromFloat(data, v)
        
        for i=1,4 do
            v = self.motorparams[i].slider.value + self.motorparams[i].offset
            data = QUtil.fromFloat(data, v)
        end
        local r = self:parse_data(data)
        update_quad_viewer(r)
    end

    self.btnSetQuad.clicked = function()
        -- here send data to the quad copter
        local reportID = 0
        local data = {reportID, self.SET_ATT}
        local v = 0
        for i=1,3 do
            v = ((self.quadparams[i].slider.value+self.quadparams[i].offset)/1000.0*360.0)
            v = ang2rad(v)
            data = QUtil.fromFloat(data, v)
        end
        v = self.quadparams[4].slider.value+self.quadparams[4].offset
        data = QUtil.fromFloat(data, v)
        local r = self.hid:writeData(data)
        log("Write: " .. r .. " bytes attitude data")
        log(self.hid.errorString)
    end

    self.btnSetMotor.clicked = function()
        local reportID = 0
        local data = {reportID, self.SET_MOTOR}
        for i=1,4 do
            v = self.motorparams[i].slider.value + self.motorparams[i].offset
            data = QUtil.fromFloat(data, v)
        end
        local r = self.hid:writeData(data)
        log("Write: " .. r .. " bytes motor data")
        log(self.hid.errorString)
    end
    
    self.btnSend.clicked = function()
        local reportID = 0
        local data = {reportID}
        data = QUtil.fromFloat(data,self.commands[1][2].value)
        data = QUtil.fromFloat(data,self.commands[2][2].value)
        data = QUtil.fromFloat(data,self.commands[3][2].value)
        data = QUtil.fromFloat(data,self.commands[4][2].value)

        local r = self.hid:writeData(data)
        log("outputReportLength: " .. self.hid.caps.outputReportLength)
        log("inputReportLength: " .. self.hid.caps.inputReportLength)
        log("Write: " .. r .. " bytes")


        log(self.hid.errorString)
    end

    self.devList.currentIndexChanged = function()
        local path = self.devList:itemData(self.devList.currentIndex).path
        self.devPath.text = path or ""
    end

    function update_quad_viewer(v)
        if v.angle and v.motorSpeed then 
            for i=1,3 do
                self.status[i][2].text = "" .. v.angle[i]
                self.quadview.quadAngle[i] = v.angle[i]
            end
            -- update the Z position
            self.quadview.quadPos[3] = v.throttle / 2000 * 0.8
        
            for i=1,4 do
                self.status[i+3][2].text = "" .. v.motorSpeed[i]
                local t = v.motorSpeed[i]*(50/2000)
            
                self.quadview.fanSpeed[i] = t
            end
        end
    end

    self.hid.readyRead = function()
        local data = self.hid:readAll()
        --log(#data)
        local r = self:parse_data(data)
        if r.angle then
            -- got attitude data
            update_quad_viewer(r)
        elseif r.gryo then
            -- got sensor data
            update_sensors(r)
        end
        --self.recvEdit.data = data
    end

    function update_sensors(v)
        if v.gryo and v.acc and v.mag then
            for i=1,3 do
                local val = v.gryo[i]
                self.sensors[i][2].text = "" .. val .. "," .. val
            end
            for i=1,3 do
                local val = v.acc[i]
                self.sensors[i+3][2].text = "" .. val .. "," .. val
            end
            for i=1,3 do
                local val = v.mag[i]
                self.sensors[i+6][2].text = "" .. val .. "," .. val
            end
        end
    end
end
--[[ Parse recieved data to structure
struct {
    float     angle[3];       // Pitch, roll, yaw
    float     motorSpeed[4];  //
    uint32_t  exeTime;        // code execute time
}

]]

QuadMonitor.DT_ATT = 1
QuadMonitor.DT_SENSOR = 2
function QuadMonitor:parse_data(data)
    local r = {}
    if data[1] == QuadMonitor.DT_ATT then
        --log("Got attitude data")
        r.angle = {}
        r.angle[QuadViewer.PITCH] = rad2ang( QUtil.toFloat(data,2) )
        r.angle[QuadViewer.ROLL] = rad2ang( QUtil.toFloat(data,6) )
        r.angle[QuadViewer.YAW] = rad2ang( QUtil.toFloat(data,10) )
        r.throttle =  QUtil.toFloat(data,14)
        r.motorSpeed = {
            QUtil.toFloat(data,18),
            QUtil.toFloat(data,22),
            QUtil.toFloat(data,26),
            QUtil.toFloat(data,30),
        }
    elseif data[1] == QuadMonitor.DT_SENSOR then
        --log("Got sensor data")
        r.gryo = {QUtil.toInt16(data,2), QUtil.toInt16(data,4),QUtil.toInt16(data,6)}
        r.acc =  {QUtil.toInt16(data,8), QUtil.toInt16(data,10),QUtil.toInt16(data,12)}
        r.mag =  {QUtil.toInt16(data,14), QUtil.toInt16(data,16),QUtil.toInt16(data,18)}
        --log(QUtil.showBytes(r.gryo))
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
