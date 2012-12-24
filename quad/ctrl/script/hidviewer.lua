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
    self.quadview = get_quad_view(self)

    self.sensors = {
        {QLabel("ROLL"), QLineEdit("0"){readonly=true}},
        {QLabel("PITCH"), QLineEdit("0"){readonly=true}},
        {QLabel("YAW"), QLineEdit("0"){readonly=true}},
        {QLabel("tick"), QLineEdit("0"){readonly=true}},
        {QLabel("Motor1"), QLineEdit("0"){readonly=true}},
        {QLabel("Motor2"), QLineEdit("0"){readonly=true}},
        {QLabel("Motor3"), QLineEdit("0"){readonly=true}},
        {QLabel("Motor4"), QLineEdit("0"){readonly=true}},
        {QLabel("magZ"), QLineEdit("0"){readonly=true}},

    }
    self.commands = {
        {QLabel("Roll:-1000"),  QSlider(1){min=2000, max=4000}},
        {QLabel("Pitch:-1000"), QSlider(1){min=2000, max=4000}},
        {QLabel("Yaw:-1000"),   QSlider(1){min=2000, max=4000}},
        {QLabel("Thro:2000"),  QSlider(1){min=2000, max=4000}},
    }

    self.commands[1][2].valueChanged = function()
        self.commands[1][1].text = "Roll:" .. (self.commands[1][2].value - 3000)
    end
    self.commands[2][2].valueChanged = function()
        self.commands[2][1].text = "Pitch:" .. (self.commands[2][2].value - 3000)
    end
    self.commands[3][2].valueChanged = function()
        self.commands[3][1].text = "Yaw:" .. (self.commands[3][2].value - 3000)
    end
    self.commands[4][2].valueChanged = function()
        self.commands[4][1].text = "Thro" .. (self.commands[4][2].value)
    end

    self.layout = QVBoxLayout{
        self.devPath,
        QHBoxLayout{
            self.devList, self.btnOpen, self.btnRefresh,self.btnSend,
        },
        QHBoxLayout{
            QFormLayout{self.sensors[1],self.sensors[2],self.sensors[3]},
            QFormLayout{self.sensors[4],self.sensors[5],self.sensors[6]},
            QFormLayout{self.sensors[7],self.sensors[8],self.sensors[9]},
            QFormLayout(self.commands),
            QLabel(""),
            strech = "0,0,0,0,1",
        },
        QHBoxLayout{self.i2cGroup,self.ppmGroup,strech="0,1"},
        QHBoxLayout{QLabel("Recv:"),QLabel(""),self.btnClear,strech="0,1,0"},
        QHBoxLayout{self.quadview,self.recvEdit,strech="0,1"},
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
                log(self.hid.errorString)
                log("Opne:" .. path .. "  fail")
            end
        end
        
    end
    
    self.btnSend.clicked = function()
        local reportID = 0
        local data = QUtil.fromFloat(self.commands[1][2].value)
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

    self.hid.readyRead = function()
        local data = self.hid:readAll()
        --log(#data)
        self.recvEdit.data = data
        local ang = {0,0,0}
        for i=1,3 do
            ang[i] = QUtil.toFloat(data,i*4-3)
            self.sensors[i][2].text = "" .. ang[i]
            self.quadview.quadAngle[i] = ang[i]*180.0/3.1415926535
        end
        self.sensors[4][2].text = "" .. QUtil.toUint32(data,4*4-3)
        for i=5,8 do
            self.sensors[i][2].text = "" .. QUtil.toFloat(data, i*4-3)
        end
    end
end

class "HIDDlg"(QDialog)
function HIDDlg:__init()
    QDialog.__init(self)
    self.windowTitle = "HID Viewer"
    self.layout = QVBoxLayout {HidViewer()}
end
