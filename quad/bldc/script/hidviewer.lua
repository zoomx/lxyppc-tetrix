class "HidViewer"(QFrame)
dofile("util.lua")
HidViewer.vid = 0x250
HidViewer.pid = 0x250

function HidViewer:__init()
    QFrame.__init(self)
    self.windowTitle = "HID Viewer"
    self.devList = QComboBox()
    self.devPath = QLineEdit()
    local devs = QUsbHid.enumDevices(self.vid,self.pid)

    function add_devs(devs)
        self.devList:clear()
        table.foreach(devs, function (k,v)
            if k == 1 then
                self.devPath.text = v.path
            end
            self.devList:addItem(v.friendName, v)  
        end)
    end
    add_devs(devs)

    self.hid = QUsbHid(self)
    self.hid.isOpen = false
    self.btnOpen = QPushButton("Open")
    self.btnSend = QPushButton("Send")
    self.recvEdit = QHexEdit(){ readonly = true, overwriteMode = false }
    self.btnClear = QPushButton("Clear"){
        clicked = function() self.recvEdit:clear() end
    }
    self.btnRefresh = QPushButton("Refresh"){
        clicked = function()
            local devs = QUsbHid.enumDevices(self.vid,self.pid)
            add_devs(devs)
        end
    }

    self.i2cData = {
        {QLineEdit("50"){ maxw = 20, inputMask = "HH"} ,
         QLineEdit("AA"){ maxw = 20, inputMask = "HH"} ,
         QLineEdit("BB"){ maxw = 20, inputMask = "HH"} ,
         QPushButton("Set") { maxh = 20, maxw = 30},
        },
        {QLineEdit("51"){ maxw = 20, inputMask = "HH"} ,
         QLineEdit("AA"){ maxw = 20, inputMask = "HH"} ,
         QLineEdit("BB"){ maxw = 20, inputMask = "HH"} ,
         QPushButton("Set") { maxh = 20, maxw = 30},
        },
        {QLineEdit("52"){ maxw = 20, inputMask = "HH"} ,
         QLineEdit("AA"){ maxw = 20, inputMask = "HH"} ,
         QLineEdit("BB"){ maxw = 20, inputMask = "HH"} ,
         QPushButton("Set") { maxh = 20, maxw = 30},
        },
        {QLineEdit("53"){ maxw = 20, inputMask = "HH"} ,
         QLineEdit("AA"){ maxw = 20, inputMask = "HH"} ,
         QLineEdit("BB"){ maxw = 20, inputMask = "HH"} ,
         QPushButton("Set") { maxh = 20, maxw = 30},
        },
    }
    function appendi2cdata(data,idx)
        data[#data+1] = tonumber("0x" .. self.i2cData[idx][1].text)
        data[#data+1] = tonumber("0x" .. self.i2cData[idx][2].text)
        data[#data+1] = tonumber("0x" .. self.i2cData[idx][3].text)
        return data
    end
    function updatei2cdata(idx,value)
        local d1,d2 = to_lsb_b(value,2)
        self.i2cData[idx][2].text = string.format("%02X",d1)
        self.i2cData[idx][3].text = string.format("%02X",d2)
    end
    function sendi2cdata(idx)
        local d = {} 
        d[1] = 0
        d[2] = 0x01
        d[3] = idx - 1
        d[4] = tonumber("0x" .. self.i2cData[idx][1].text)
        d[5] = tonumber("0x" .. self.i2cData[idx][2].text)
        d[6] = tonumber("0x" .. self.i2cData[idx][3].text)
        local r = self.hid:writeData(d)
        if r then
            log("Send data success")
        else
            log(self.hid.errorString)
        end
    end
    self.i2cData[1][4].clicked = function() sendi2cdata(1) end
    self.i2cData[2][4].clicked = function() sendi2cdata(2) end
    self.i2cData[3][4].clicked = function() sendi2cdata(3) end
    self.i2cData[4][4].clicked = function() sendi2cdata(4) end
    self.i2cPeriodSend = QCheckBox("Repeat")
    self.btni2c = QPushButton("Send All"){
        clicked = function()
            local d = {} 
            d[1] = 0       -- set report ID
            d[2] = 0x02    -- set cmd, send all i2c data
            d[3] = 0       -- data packet count
            appendi2cdata(d,1)
            appendi2cdata(d,2)
            appendi2cdata(d,3)
            appendi2cdata(d,4)
            d[3] = 4
            d[#d+1] = self.i2cPeriodSend.checked and 1 or 0
            local r = self.hid:writeData(d)
            if r then
                log("Send data success")
            else
                log(self.hid.errorString)
            end
        end
    }
    self.i2ctitle = {
        QLabel("Addr"){maxw = 25},
        QLabel("D1"){maxw = 20},
        QLabel("d2"){maxw = 20},
        QLabel(""){},
    }
    self.i2cGroup = QGroupBox("Send I2C data"){
        layout = QFormLayout{
            {"",QHBoxLayout(self.i2ctitle)},
            {"Addr1", QHBoxLayout(self.i2cData[1])},
            {"Addr2", QHBoxLayout(self.i2cData[2])},
            {"Addr3", QHBoxLayout(self.i2cData[3])},
            {"Addr4", QHBoxLayout(self.i2cData[4])},
            {self.i2cPeriodSend,self.btni2c},
        }
    }

    self.ppm1 = QSlider(1){ min = 0, max = 2000, maxh = 21}
    self.ppm2 = QSlider(1){ min = 0, max = 2000, maxh = 21}
    self.ppm3 = QSlider(1){ min = 0, max = 2000, maxh = 21}
    self.ppm4 = QSlider(1){ min = 0, max = 2000, maxh = 21}
    self.ppm1.value = 500
    self.ppm2.value = 1000
    self.ppm3.value = 1500
    self.ppm4.value = 2000
    self.ppm1t = QLineEdit(string.format("%04X",self.ppm1.value)){maxw=40}
    self.ppm2t = QLineEdit(string.format("%04X",self.ppm2.value)){maxw=40}
    self.ppm3t = QLineEdit(string.format("%04X",self.ppm3.value)){maxw=40}
    self.ppm4t = QLineEdit(string.format("%04X",self.ppm4.value)){maxw=40}
    self.ppm1s = QLineEdit(string.format("%dus",self.ppm1.value)){maxw=45}
    self.ppm2s = QLineEdit(string.format("%dus",self.ppm2.value)){maxw=45}
    self.ppm3s = QLineEdit(string.format("%dus",self.ppm3.value)){maxw=45}
    self.ppm4s = QLineEdit(string.format("%dus",self.ppm4.value)){maxw=45}
    
    function updatevalue(idx)
        self["ppm"..idx.."t" ].text = string.format("%04X",self["ppm"..idx].value)
        self["ppm"..idx.."s" ].text = string.format("%dus",self["ppm"..idx].value)
        updatei2cdata(idx,self["ppm"..idx].value)
    end
    updatevalue(1)   
    updatevalue(2)
    updatevalue(3)
    updatevalue(4)

    self.ppm1.valueChanged = function()updatevalue(1) end
    self.ppm2.valueChanged = function()updatevalue(2) end
    self.ppm3.valueChanged = function()updatevalue(3) end
    self.ppm4.valueChanged = function()updatevalue(4) end
    self.btnppm = QPushButton("Setup"){
        clicked = function()
            local d = {} 
            d[1] = 0       -- set report ID
            d[2] = 0x03    -- set cmd, send ppm data
            d[3] = 0x04    -- ppm cnt
            d[4],d[5] = to_lsb_b(self.ppm1.value,2)
            d[6],d[7] = to_lsb_b(self.ppm2.value,2)
            d[8],d[9] = to_lsb_b(self.ppm3.value,2)
            d[10],d[11] = to_lsb_b(self.ppm4.value,2)
            local r = self.hid:writeData(d)
            if r then
                log("Send data success")
            else
                log(self.hid.errorString)
            end
        end
    }
    self.ppmGroup = QGroupBox("Send PPM data"){
        layout = QFormLayout{
            {"PPM1", QHBoxLayout{self.ppm1,self.ppm1s}},
            {"PPM2", QHBoxLayout{self.ppm2,self.ppm2s}},
            {"PPM3", QHBoxLayout{self.ppm3,self.ppm3s}},
            {"PPM4", QHBoxLayout{self.ppm4,self.ppm4s}},
            self.btnppm,
        }
    }

    self.editData = QHexEdit(){
        minw = 200,
        overwritemode = false,
    }
    self.editAddr = QLineEdit("57"){ inputMask = "HH" }
    self.editCmd = QLineEdit("01"){ inputMask = "HH" }
    self.editLen = QLineEdit("2"){ inputMask = "99" }
    
    self.btnRecvData = QPushButton("Get"){
        clicked = function()
        local d = {0x00,0x05}
        d[3] = tonumber("0x" .. self.editAddr.text)
        d[4] = tonumber("0x" .. self.editCmd.text)
        d[5] = tonumber(self.editLen.text)
        local r = self.hid:writeData(d)
        log( r and "Send data success" or self.hid.errorString )
        --self.recvEdit.data = d
        end
    }
    self.btnSendData = QPushButton("Set"){
        clicked = function()
        local d = {0x00,0x04}
        local x = self.editData.data
        d[3] = tonumber("0x" .. self.editAddr.text)
        d[4] = tonumber("0x" .. self.editCmd.text)
        d[5] = tonumber(self.editLen.text)
        for i=1,#x do
            d[5+i] = x[i]
        end
        local r = self.hid:writeData(d)
        log( r and "Send data success" or self.hid.errorString )
        --self.recvEdit.data = d
        end
    }

    self.comGroup = QGroupBox("Test"){
        layout = QHBoxLayout{
            self.editData,
            QGridLayout{
            {
                QLabel("Cmd"),
                QLabel("Addr"),
                QLabel("Len"),
            },
            {
            self.editCmd,
            self.editAddr,
            self.editLen,
            },
            {
            self.btnSendData,
            self.btnRecvData,
            },
            }
        }
    }

    self.layout = QVBoxLayout{
        self.devPath,
        QHBoxLayout{
            self.devList, self.btnOpen, self.btnRefresh,
        },
        QHBoxLayout{self.i2cGroup,self.ppmGroup,strech="0,1"},
        QHBoxLayout{QLabel("Recv:"),QLabel(""),self.btnClear,strech="0,1,0"},
        self.comGroup,
        self.recvEdit,
    }
    
    self.btnOpen.clicked = function()
        local path = self.devList:itemData(self.devList.currentIndex).path
        if self.hid.isOpen then
            self.hid:close()
            self.btnOpen.text = "Open"
            self.hid.isOpen = false
            log("Closed")
        else
            self.hid.path = path
            self.hid.isOpen = self.hid:open()
            if self.hid.isOpen then
                self.btnOpen.text = "Close"
                log("Opne:" .. path .. "  success")
            else
                log("Opne:" .. path .. "  fail")
            end
        end
        
    end
    
    self.btnSend.clicked = function()
        local reportID = 0
        local r = self.hid:writeData({reportID,0xaa,0xbb,0xcc,0xdd})
        log("outputReportLength: " .. self.hid.caps.outputReportLength)
        log("inputReportLength: " .. self.hid.caps.inputReportLength)
        log("Write: " .. r .. " bytes")
        log(self.hid.errorString)
    end

    self.devList.currentIndexChanged = function()
        local path = self.devList:itemData(self.devList.currentIndex).path
        self.devPath.text = path or ""
    end

    self.hid.readyRead = function()
        local data = self.hid:readAll()
        log(#data)
        self.recvEdit.data = data
    end

end

class "HIDDlg"(QDialog)
function HIDDlg:__init()
    QDialog.__init(self)
    self.windowTitle = "HID Viewer"
    self.layout = QVBoxLayout {HidViewer()}
end
