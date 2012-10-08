class "BLDCViewer"(QFrame)

function BLDCViewer:__init()
    QFrame.__init(self)
    self.windowTitle = "BLDC Viewer"
    self.portList = QComboBox();
    ports = QSerialPort.enumPort()
    table.foreach(ports, function (k,v) self.portList:addItem(v.portName, v)  end)
    self.serial = QSerialPort(self)
    self.serial.flowControl = QSerialPort.FLOW_OFF 
    self.serial.baudRate = QSerialPort.BAUD38400
    self.btnOpen = QPushButton("Open")
    self.btnSend = QPushButton("Send")
    self.btnClear = QPushButton("Clear")

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
        QHBoxLayout{QLabel("Send:"),self.btnSend},
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
    
    self.btnClear.clicked = function ()
        self.recvText:clear()
    end

    self.serial.readyRead = function()
        local len = self.serial:bytesAvailable()
        local x = self.serial:readAll()
        self.recvText:append(x)
        self.recvText:scrollToEnd()
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
        chk = chk + v
        r[k+4] = v
    end
    a = math.modf(chk/256)
    b = chk - 256*a
    r[#r+1] = a
    r[#r+1] = b
    --log(#r)
    return r
end