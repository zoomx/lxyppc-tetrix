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

    self.sensors = {
        {QLabel("accX"), QLineEdit("0"){readonly=true}},
        {QLabel("accY"), QLineEdit("0"){readonly=true}},
        {QLabel("accZ"), QLineEdit("0"){readonly=true}},
        {QLabel("gyroX"), QLineEdit("0"){readonly=true}},
        {QLabel("gyroY"), QLineEdit("0"){readonly=true}},
        {QLabel("gyroZ"), QLineEdit("0"){readonly=true}},
    }

    self.layout = QVBoxLayout{
        self.devPath,
        QHBoxLayout{
            self.devList, self.btnOpen, self.btnRefresh,self.btnSend,
        },
        QHBoxLayout{
            QFormLayout(self.sensors),
            QLabel(""),
            strech = "0,1",
        },
        QHBoxLayout{self.i2cGroup,self.ppmGroup,strech="0,1"},
        QHBoxLayout{QLabel("Recv:"),QLabel(""),self.btnClear,strech="0,1,0"},
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
    
    function get_signed_32(idx, buf)
        if #buf < idx + 3 then return 0 end
        local r = 0
        local p = 1
        for i=1,4 do
            local v = buf[idx+i-1]
            v = v<0 and v+256 or v
            r = r + v*p
            p = p * 256
        end
--[[
        v1 = buf[idx]
        v2 = buf[idx+1]
        v3 = buf[idx+2]
        v4 = buf[idx+3]
        v1 = v1<0 and v1+256 or v1
        v2 = v2<0 and v2+256 or v2
        v3 = v3<0 and v3+256 or v3
        v4 = v4<0 and v4+256 or v4
        local r = v1 + v2*256 + v3*256*256 + v4*256*256*256
--]]
        if r > 256*256*256*128 then
            r = r - 256*256*256*256
        end
        return r
    end

    self.hid.readyRead = function()
        local data = self.hid:readAll()
        --log(#data)
        --self.recvEdit.data = data
        for i=1,6 do
            self.sensors[i][2].text = "" .. get_signed_32(i*4-3,data)/10
        end
    end

end

class "HIDDlg"(QDialog)
function HIDDlg:__init()
    QDialog.__init(self)
    self.windowTitle = "HID Viewer"
    self.layout = QVBoxLayout {HidViewer()}
end
