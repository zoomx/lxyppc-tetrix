class "BLDCViewer"(QFrame)

function BLDCViewer:__init()
    QFrame.__init(self)
    self.windowTitle = "BLDC Viewer"
    self.portList = QComboBox();
    ports = QSerialPort.enumPort()
    table.foreach(ports, function (k,v) 
            if string.match(v.portName,"tty") then
                if string.match(v.portName,"USB") then
                    self.portList:addItem(v.portName, v)  
                end
            else
                self.portList:addItem(v.portName, v)  
            end
    end)
    self.serial = QSerialPort(self)
    self.serial.flowControl = QSerialPort.FLOW_OFF 
    self.serial.baudRate = QSerialPort.BAUD115200
    self.btnOpen = QPushButton("Open")
    self.btnSend = QPushButton("Send")
    self.btnClear = QPushButton("Clear")
    self.btnRawSend = QPushButton("Raw Send")

    -- LED setup
    self.spinLed1 = QSpinBox{min = 0, max = 100}
    self.spinLed2 = QSpinBox{min = 0, max = 100}
    self.btnLed = QPushButton("Setup"){
        clicked = function()
            local d = { 0xaa, self.spinLed1.value, self.spinLed2.value }
            self.serial:write( pack_data(d) )
        end
    }
    self.groupLed = QGroupBox("LED Setup"){
        layout = QFormLayout{
            {"Led1", self.spinLed1,},
            {"Led2", self.spinLed2,},
            self.btnLed,
        }
    }

    -- I2C address get
    self.editI2CAddr = QLineEdit("00"){ readonly = true, maxw = 50 }
    self.btnI2CAddr = QPushButton("Get"){
        maxw = 40,
        clicked = function()
            local d = { 0xbb }
            
            self.onSerialData = function(data)
                local add = data[2]
                local cmd = data[1]
                add = (add >= 0) and (add) or (add + 256)
                cmd = (cmd >= 0) and (cmd) or (cmd + 256)
                if cmd == 0xbb then    
                    self.editI2CAddr.text = string.format("0x%02X",add)
                end
            end
            self.serial:write( pack_data(d) )
        end
    }

    self.groupI2CAddr = QGroupBox("I2C Address"){
        layout = QFormLayout{
            {"I2C Addr:", QHBoxLayout{self.editI2CAddr,self.btnI2CAddr,}},
        }
    }

    -- ADC value get
    self.editRefCal = QLineEdit("00") { readonly = true }
    self.editTempCal30 = QLineEdit("00") { readonly = true }
    self.editTempCal110 = QLineEdit("00") { readonly = true }
    self.btnADCCal = QPushButton("Get Cal"){
            clicked = function()
            local d = { 0xdd }
            self.onSerialData = function(data)
                local len = data[2]
                local cmd = data[1]
                len = 3
                cmd = (cmd >= 0) and (cmd) or (cmd + 256)
                self.adcCal = {}
                if cmd == 0xdd then
                    for i=1,len do
                        local d1 = data[i*2 + 1]
                        local d2 = data[i*2 + 2]
                        d1 = d1>=0 and d1 or d1 + 256
                        d2 = d2>=0 and d2 or d2 + 256
                        d1 = d1 + d2*256
                        self.adcCal[i] = d1
                    end
                end
                self.editRefCal.text = string.format("%04X",self.adcCal[1])
                self.editTempCal30.text = string.format("%04X",self.adcCal[2])
                self.editTempCal110.text = string.format("%04X",self.adcCal[3])
            end
            self.serial:write( pack_data(d) )
        end
    }
    
    self.adcData = {
        {"Ref:", QLineEdit("00") { readonly = true }},
        {"I Temp:", QLineEdit("00") { readonly = true }},
        {"O Temp:", QLineEdit("00") { readonly = true }},
        {"C:", QLineEdit("00") { readonly = true }},
        {"B:", QLineEdit("00") { readonly = true }},
        {"Mid:", QLineEdit("00") { readonly = true }},
        {"A:", QLineEdit("00") { readonly = true }},
        {"IRef:", QLineEdit("00") { readonly = true }},
        {"VBat:", QLineEdit("00") { readonly = true }},
    }

    self.btnADC = QPushButton("Sample"){
        clicked = function()
            local d = { 0xcc }
            self.onSerialData = function(data)
                local len = data[2]
                local cmd = data[1]
                len = (len >= 0) and (len) or (len + 256)
                cmd = (cmd >= 0) and (cmd) or (cmd + 256)
                if cmd == 0xcc then
                    for i=1,len do
                        local d1 = data[i*2 + 1]
                        local d2 = data[i*2 + 2]
                        d1 = d1>=0 and d1 or d1 + 256
                        d2 = d2>=0 and d2 or d2 + 256
                        d1 = d1 + d2*256
                        self.adcData[i][2].text = string.format("%04x",d1)
                        if i == 1 and self.adcCal[1] then
                            -- calc volts
                            local v = self.adcCal[1] * 3.3 / d1
                            self.volt = v
                            self.adcData[i][2].text = string.format("%.2f(%04X)",v,d1)
                        end
                        if i == 2 and self.adcCal[2] and self.volt then
                            local dt = 80/(self.adcCal[3] - self.adcCal[2])
                            local t = (d1*self.volt/3.3 - self.adcCal[2])*dt + 30
                            self.adcData[i][2].text = string.format("%.2fC(%04X)",t,d1)
                        end
                        if i == 9 and self.volt then
                            -- get power supply volt
                            local vp = d1*self.volt / 4095
                            vp = vp * (10*1000 + 680) / 680
                            self.adcData[i][2].text = string.format("%.2f(%04X)",vp,d1)
                        end
                    end
                end
            end
            self.serial:write( pack_data(d) )
        end
    }

    self.groupADC = QGroupBox("ADC Results"){
        layout =
            QHBoxLayout{ 
            QFormLayout{
                self.adcData[1],
                self.adcData[2],
                self.adcData[3],
                self.adcData[4],
                self.adcData[5],
            },
            QFormLayout{
                self.adcData[6],
                self.adcData[7],
                self.adcData[8],
                self.adcData[9],
                self.btnADC,
            },
            QFormLayout{
                {"Ref Cal", self.editRefCal},
                {"Temp 30", self.editTempCal30},
                {"Temp 110", self.editTempCal110},
                self.btnADCCal,
            }
            }
    }

    -- PWM setting
    self.pwmSets = {
        {"A+:",  QComboBox{ {"PWM","ON","OFF"} }},
        {"B+:",  QComboBox{ {"PWM","ON","OFF"} }},
        {"C+:",  QComboBox{ {"PWM","ON","OFF"} }},
        {"A-:",  QComboBox{ {"PWM","ON","OFF"} }},
        {"B-:",  QComboBox{ {"PWM","ON","OFF"} }},
        {"C-:",  QComboBox{ {"PWM","ON","OFF"} }},
    }
    self.pwmDuty = QSpinBox{ min = 0, max = 1200}
    for i=1,6 do self.pwmSets[i][2].currentIndex = 2 end
    self.pwmSets[1][2].currentIndexChanged = function(idx)
        if idx ~= 2 then
            self.pwmSets[4][2].currentIndex = 2
        end
    end
    self.pwmSets[4][2].currentIndexChanged = function(idx)
        if idx ~= 2 then
            self.pwmSets[1][2].currentIndex = 2
        end
    end

    self.pwmSets[2][2].currentIndexChanged = function(idx)
        if idx ~= 2 then
            self.pwmSets[5][2].currentIndex = 2
        end
    end
    self.pwmSets[5][2].currentIndexChanged = function(idx)
        if idx ~= 2 then
            self.pwmSets[2][2].currentIndex = 2
        end
    end

    self.pwmSets[3][2].currentIndexChanged = function(idx)
        if idx ~= 2 then
            self.pwmSets[6][2].currentIndex = 2
        end
    end
    self.pwmSets[6][2].currentIndexChanged = function(idx)
        if idx ~= 2 then
            self.pwmSets[3][2].currentIndex = 2
        end
    end


    self.btnSetPwm = QPushButton("Setup"){
        clicked = function()
            local d = {0xee}
            for i=1,3 do
                d[i+1] = self.pwmSets[i][2].currentIndex + self.pwmSets[i+3][2].currentIndex*16
            end
            d[5] = math.modf(self.pwmDuty.value/256)
            d[6] = self.pwmDuty.value - d[5]*256
            d[5],d[6] = d[6],d[5]
            self.serial:write( pack_data(d) )
        end
    }
    self.groupPWM = QGroupBox("PWM Setup"){
        layout =
            QHBoxLayout{
            QFormLayout{
                self.pwmSets[1],
                self.pwmSets[2],
                self.pwmSets[3],
                {"Duty:", self.pwmDuty},
            },
            QFormLayout{
                self.pwmSets[4],
                self.pwmSets[5],
                self.pwmSets[6],
                self.btnSetPwm,
            },
            
            }
    }

    self.sendText = QHexEdit{
        overwriteMode = false,
        readOnly = false,
    }

    self.recvText = QHexEdit()
    self.recvText.overwriteMode = false
    self.recvText.readOnly = true

    self.layout = QVBoxLayout{
        QHBoxLayout{
            self.portList,
            self.btnOpen,
        },
        QHBoxLayout{
            self.groupLed,
            self.groupI2CAddr,
            self.groupADC,
        },
        QHBoxLayout{
            self.groupPWM,
            QLabel(""),
            strech = "0,1",
        },
        QHBoxLayout{QLabel("Send:"),self.btnSend,self.btnRawSend},
        self.sendText,
        QHBoxLayout{QLabel("Recv:"),self.btnClear},
        self.recvText,
    }

    self.btnSend.clicked = function()
        --log("send data")
        local d = pack_data(self.sendText.data)
        --for k,v in pairs(d) do
        --    log( k .. ":" .. v)
        --end
        self.serial:write(d)
    end
    
    self.btnRawSend.clicked = function()
        self.serial:write(self.sendText.data)
        local t = self.sendText.data
        t[1] = t[1] + 1
        self.sendText.data = t
    end
    
    self.btnClear.clicked = function ()
        self.recvText:clear()
    end

    self.serial.readyRead = function()
        local len = self.serial:bytesAvailable()
        local x = self.serial:readAll()
        self.recvText:append(x)
        self.recvText:scrollToEnd()
        if self.onSerialData then
            self.onSerialData( x )
        end
        --ls = self.serial.lineStatus
        --logEdit:append(string.format("%x",ls))
    end

    self.btnOpen.clicked = 
    function ()
        if self.serial.isOpen then
            self.serial:close()
            logEdit:append("Close success...")
            self.btnOpen.text = "Open"
        else
            i = self.portList.currentIndex
            portInfo = self.portList:itemData(i)
            local name = portInfo.portName
            logEdit:append("open: " .. name .. " with setting: " .. self.serial.settingString)
            self.serial.portName = name
            res = self.serial:open()
            if res then
                self.btnOpen.text = "Close"
                logEdit:append("Success ...")
            else
                logEdit:append("Fail:  " .. self.serial.errorString)
            end
        end
    end

    self.serial.connected = function(info)
        logEdit:append(info.portName .. "   connected")
    end

    self.serial.disconnected = function(info)
        logEdit:append(info.portName .. "   disconnected")
    end
end

class "BLDCDlg"(QDialog)
function BLDCDlg:__init()
    QDialog.__init(self)
    self.windowTitle = "BLDC Viewer"
    self.layout = QVBoxLayout {BLDCViewer()}
end


function pack_data(data)
    local len = #data
    local a = math.modf(len/256)
    local b = len - 256*a
    local r = {0x55,0xaa,a,b}
    local chk = 0x55+0xaa+a+b
    for k,v in pairs(data) do
        if v < 0 then
            v = v + 256
        end
        chk = chk + v
        r[k+4] = v
    end
    while chk > 65535 do
        chk = chk - 65536
    end
    a = math.modf(chk/256)
    b = chk - 256*a
    r[#r+1] = a
    r[#r+1] = b
    --log(#r)
    return r
end