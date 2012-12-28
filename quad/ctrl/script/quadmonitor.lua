-- Quad Flight Monitor
dofile("quadviewer.lua")
class "QuadMonitor"(QFrame)


Lang = { Eng = 1, Chn = 2}
Lang[Lang.Eng] = {
    ["Title"] = "Quad Flight Monitor",
    --["Open"] = "Open",
    --["Send"] = "Send",
    --["Close"] = "Close",
    --["Clear"] = "Clear",
    --["Refresh"] = "Refresh",
    --["Pitch"] = "Pitch",
    --["Roll"] = "Roll",
    --["Yaw"] = "Yaw",
    --["Motor"] = "Motor",
    --["exeTime"] = "exeTime",
    --["Thro"] = "Thro",
    --["Preview"] = "Preview"
}
Lang[Lang.Chn] = {
    ["Title"] = "四轴监控器",
    ["Open"] = "打开",
    ["Send"] = "发送",
    ["Close"] = "关闭",
    ["Clear"] = "清空",
    ["Refresh"] = "刷新",
    ["Pitch"] = "俯仰",
    ["Roll"] = "横滚",
    ["Yaw"] = "偏航",
    ["Motor"] = "电机",
    ["exeTime"] = "执行时间",
    ["Thro"] = "油门",
    ["Preview"] = "预览",
    ["Angle"] = "角度",
    ["Current State"] = "当前状态",
    ["Parame Set"] = "参数设置",
    ["Quad Set"] = "四轴设置",
    ["Motor Set"] = "电机设置",
    ["Set"] = "设置",
}

Lang.current = Lang.Chn
function loadStr(id)
    return Lang[Lang.current][id] or id
end

--- USB Device VID and PID
QuadMonitor.vid = 0x250
QuadMonitor.pid = 0x250

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
end

function QValueSlider:__call(v)
    if v.max then self.slider.max = v.max end
    if v.min then self.slider.min = v.min end
    if v.minw then self.minw = v.minw end
    if v.maxw then self.maxw = v.maxw end
    if v.offset then self.offset = v.offset end
    if v.ratio then self.ratio = v.ratio end
    if v.unit then self.unit = v.unit end
    self:valueSliderChanged()
    return self
end

function QValueSlider:valueSliderChanged()
    self.label.text = (self.slider.value + self.offset)*self.ratio .. self.unit
end

function QuadMonitor:__init()
    QFrame.__init(self)
    self.windowTitle = loadStr("Title")
    self.devList = QComboBox()
    self.devPath = QLineEdit()
    local usb_devs = QUsbHid.enumDevices(self.vid,self.pid)

    function add_devs(devs)
        self.devList:clear()
        table.foreach(usb_devs, function (k,v)
            if k == 1 then
                self.devPath.text = v.path
            end
            self.devList:addItem(v.friendName, v)  
        end)
    end


    add_devs(devs)

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

    self.sensors = {
        {loadStr("Pitch"), QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Roll"), QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Yaw"), QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Motor").."1", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Motor").."2", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Motor").."3", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Motor").."4", QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("exeTime"), QLineEdit("0"){readonly=true, minw = 60}},
        {"magZ", QLineEdit("0"){readonly=true, minw = 60}},
    }

    self.angleParams = QGroupBox(loadStr("Angle")){
        layout = QFormLayout{self.sensors[1],self.sensors[2],self.sensors[3]}
    }
    self.motorParams = QGroupBox(loadStr("Motor")){
        layout = QFormLayout{self.sensors[4],self.sensors[5],self.sensors[6],self.sensors[7]}
    }
    self.currentState = QGroupBox(loadStr("Current State")){
        layout = QHBoxLayout{self.angleParams, self.motorParams, self.quadpreview}
    }


    self.btnSetQuad = QPushButton(loadStr("Set")){maxw=40}
    
    self.quadcommands = {
        {loadStr("Roll"),  QValueSlider(1){min=2000, max=4000, minw = 60, offset = -3000, }},
        {loadStr("Pitch"), QValueSlider(1){min=2000, max=4000, minw = 60, offset = -3000, }},
        {loadStr("Yaw"),   QValueSlider(1){min=2000, max=4000, minw = 60, offset = -3000, }},
        {loadStr("Thro"),  QValueSlider(1){min=2000, max=4000, minw = 60, offset = 0}},
        {self.btnSetQuad,QLabel("")},
    }

    self.quadparams = {}
    for i=1,4 do
        self.quadparams[i] = self.quadcommands[i][2].slider
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
        self.motorparams[i] = self.motorcommands[i][2].slider
        self.motorcommands[i][2] = QHBoxLayout{self.motorcommands[i][2].slider,self.motorcommands[i][2].label}
    end
    
    self.motorSet = QGroupBox(loadStr("Motor Set")){
        layout = QFormLayout(self.motorcommands),
    }

    self.paramSet = QGroupBox(loadStr("Parame Set")){
        layout = QHBoxLayout{self.quadSet, self.motorSet},
    }

    self.layout = QVBoxLayout{
        --self.devPath,
        QHBoxLayout{
            self.devList, self.btnOpen, self.btnRefresh,QLabel(""), strech = "0,0,0,1"
        },
        self.currentState,
        self.paramSet,
        --QHBoxLayout{
        --    QFormLayout{self.sensors[8],self.sensors[9]},
        --    QFormLayout(self.commands),
        --},
        --QHBoxLayout{QLabel("Recv:"),QLabel(""),self.btnClear,strech="0,1,0"},
        --QHBoxLayout{self.quadpreview,self.recvEdit,strech="0,1"},
    }

    self.btnOpen.clicked = function()
        local path = self.devList:itemData(self.devList.currentIndex).path
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
        for i=1,3 do
            local v = 3.1415626/((self.quadparams[i].value-3000)/1000.0*360)
            log(v)
            data = QUtil.fromFloat(data, v)
        end
        for i=1,4 do
            data = QUtil.fromFloat(data,self.motorparams[i].value)
        end

        update_quad_viewer(self:parse_data(data))
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
        for i=1,3 do
            self.sensors[i][2].text = "" .. v.angle[i]
            self.quadview.quadAngle[i] = v.angle[i]
        end
        for i=1,4 do
            self.sensors[i+4][2].text = "" .. v.motorSpeed[i]
        end
    end

    self.hid.readyRead = function()
        local data = self.hid:readAll()
        --log(#data)
        local r = self:parse_data(data)
        --self.recvEdit.data = data
    end
end
--[[ Parse recieved data to structure
struct {
    float     angle[3];       // Pitch, roll, yaw
    float     motorSpeed[4];  //
    uint32_t  exeTime;        // code execute time
}

]]
function QuadMonitor:parse_data(data)
    local r = {}
    r.angle = {}
    r.angle[QuadViewer.PITCH] = QUtil.toFloat(data,1) * 180.0 / 3.1415926535
    r.angle[QuadViewer.ROLL] = QUtil.toFloat(data,5) * 180.0 / 3.1415926535
    r.angle[QuadViewer.YAW] = QUtil.toFloat(data,9) * 180.0 / 3.1415926535
    r.motorSpeed = {
        QUtil.toFloat(data,13),
        QUtil.toFloat(data,17),
        QUtil.toFloat(data,21),
        QUtil.toFloat(data,25),
    }
    r.exeTime = QUtil.toFloat(data,29)
    return r
end

-- Dialog wrapper
class "QuadMonitorDlg"(QDialog)
function QuadMonitorDlg:__init()
    QDialog.__init(self)
    self.windowTitle = "Quad Flight Monitor"
    self.layout = QVBoxLayout {QuadMonitor()}
end
