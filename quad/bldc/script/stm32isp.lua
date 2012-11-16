-- STM32 ISP host side
-- refer to AN2606 and AN3155

dofile("hex.lua")
class "STM32ISP"(QFrame)

STM32ISP.ACK = 0x79
STM32ISP.NAK = 0x1F
STM32ISP.DETECT = 0x7F
function STM32ISP:__init()
    QFrame.__init(self)
    self.windowTitle = "STM32 ISP"
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
    self.serial.parity = QSerialPort.PAR_EVEN
    self.serial.queryMode = QSerialPort.Polling

    self.btnOpen = QPushButton("Open")
    self.btnLoad = QPushButton("Load File")
    self.btnProg = QPushButton("Program device")
    self.btnDetect = QPushButton("Detect")
    self.btnGetID = QPushButton("Get ID")
    self.btnRead = QPushButton("Read")
    self.btnOption = QPushButton("Read Option")

    self.startAdd = QLineEdit("08000000"){
        inputMask = "HHHHHHHH"
    }
    self.length = QLineEdit("256"){
        inputMask = "99999"
    }

    self.progress = QProgressBar()


    self.btnSend = QPushButton("Send")
    self.btnClear = QPushButton("Clear")

    self.sendText = QHexEdit{
        overwriteMode = false,
        readOnly = false,
    }

    self.flashData = QHexEdit()
    self.flashData.overwriteMode = false
    self.flashData.readOnly = true

    self.recvText = QHexEdit()
    self.recvText.overwriteMode = false
    self.recvText.readOnly = true

    self.layout = QVBoxLayout{
        QHBoxLayout{
            self.portList,
            self.btnOpen,
            self.btnDetect,
            self.btnGetID,
            QLabel(""),
            strech = "0,0,0,0,1"
        },
        QHBoxLayout{ self.btnOption, },
        QHBoxLayout{
            self.btnRead,
            QLabel("Add:"),self.startAdd,
            QLabel("Len:"),self.length,
        },
        QHBoxLayout{QLabel("Flash Data:"),self.btnLoad,strech = "1,0"},
        self.flashData,
        self.btnProg,
        self.progress,
        --QHBoxLayout{QLabel("Send:"),self.btnSend},
        --self.sendText,
        --QHBoxLayout{QLabel("Recv:"),self.btnClear},
        --self.recvText,
    }

    self.btnLoad.clicked = function()
        -- load hex file
        local name = QCommonDlg.getOpenFileName("Open Hex file", "", "Hex file(*.hex);;all files(*)")
        local bin = load_hex_file(name)
        self.flashData.data = bin
        self.flashData.addressOffset = bin.start_addr or 0
    end
    
    self.progress.min = 0
    self.progress.max = 20
    self.btnProg.clicked = function()
        -- calc data size
        local dataLen = #self.flashData.data
        -- divide them into 256 bytes
        local pageCnt = math.modf( (dataLen+255)/256 )
        local lastPageCnt = dataLen - (pageCnt-1) * 256
        log("data len:" .. dataLen .. " bytes, " .. (pageCnt-1) .. " pages and " .. lastPageCnt .. "bytes")
        local roundUp = math.modf((lastPageCnt+3)/4) * 4
        log("round last page to " .. roundUp .. "bytes" )
        local t = {}
        for i=1,roundUp-lastPageCnt do
            t[i] = 0xff
        end
        self.flashData:append(t)

        -- read flash
        --local flashData = cmd_read_memory(self.serial, 0x08000000, 256)
        --local flashData = cmd_read_memory(self.serial, 0x1FFFF800, 12)
        --self.flashData.data = flashData
        
    end

    self.btnDetect.clicked = function()
        -- detect the ISP
        self.serial:write({self.DETECT})
        --local resp = self.serial:read(1)
        --if resp[1] == self.ACK then
        --    log("Detect: ACK")
        --else
        --    log("Detect:" .. #resp .. "," .. dec2hex(resp[1]))
        --    return
        --end
        -- detect valid commads
        cmd_get(self.serial)
        -- get chip ID
        cmd_get_id(self.serial)
    end

    self.btnGetID.clicked = function()
        -- detect valid commads
        cmd_get(self.serial)
        -- get chip ID
        cmd_get_id(self.serial)
    end

    self.btnOption.clicked = function()
        cmd_get_option(self.serial)
    end
    
    self.btnRead.clicked = function()
        local len = tonumber(self.length.text)
        local add = tonumber("0x" .. self.startAdd.text)
        self.flashData.addressOffset = add
        self.flashData:clear()
        while len >128 do
            flashData = cmd_read_memory(self.serial, add, 128)
            self.flashData:append(flashData)
            add = add + 128
            len = len - 128
        end
        if len > 0 then
            flashData = cmd_read_memory(self.serial, add, len)
            self.flashData:append(flashData and flashData or {})
        end
    end

    self.btnSend.clicked = function()
        --log("send data")
        --local d = pack_data(self.sendText.data)
        --for k,v in pairs(d) do
        --    log( k .. ":" .. v)
        --end
        --self.serial:write(d)
    end
    
    self.btnClear.clicked = function ()
        self.recvText:clear()
    end

    self.serial.readyRead = function()
        local len = self.serial:bytesAvailable()
        local x = self.serial:readAll()
        self.recvText:append(x)
        self.recvText:scrollToEnd()
        log("ready read")
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

    --log_data(to_lsb(0xfffefbfc,4))
    --log_data(to_msb(0x01020304,4))
end

class "STM32ISPDlg"(QDialog)
function STM32ISPDlg:__init()
    QDialog.__init(self)
    self.windowTitle = "BLDC Viewer"
    self.layout = QVBoxLayout {STM32ISP()}
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

function log_data(data)
    local str = ""
    if data then
    str = "(" .. #data .. "):"
    for i=1,#data do
        str = str .. dec2hex(data[i]) .. ","
    end
    else
    str = "(nil)"
    end
    log(str)
end

function cmd_get(serial)
    serial:write({0x00,0xff})
    -- wait ack
    local resp = serial:read(1)
    if resp[1] == STM32ISP.ACK then
        log("GET: ACK")
        local N = serial:read(1)[1]
        N = N and N or 1
        log("len: " .. (N + 1) )
        local data = serial:read(N+1)
        log_data(data)
        resp = serial:read(1)
        if resp[1] == STM32ISP.ACK then
            log("GET done: ACK")
            return true
        else
            log("GET done: NAK")
        end
    else
        log("GET: NAK")
    end
    return false
end

function cmd_get_id(serial)
    serial:write({0x02,0xfd})
    -- wait ack
    local resp = serial:read(1)
    if resp[1] == STM32ISP.ACK then
        log("GET ID: ACK")
        local N = serial:read(1)[1]
        log("len: " .. (N + 1) .. "must be 1" )
        local data = serial:read(N+1)
        log_data(data)
        resp = serial:read(1)
        if resp[1] == STM32ISP.ACK then
            log("GET done: ACK")
            return data
        else
            log("GET done: NAK")
        end
    else
        log("GET: NAK")
    end
    return nil
end

function check_sum(data)
    local sum = 0
    for i=1,#data do
        sum = bit_xor(sum, data[i])
    end
    return sum
end


function to_lsb(data,len)
    local r = {}
    local td
    len = len or 4
    for i=1,len do
        td = math.modf(data/256)
        r[i] = data - td * 256
        data = td
    end
    return r
end

function to_msb(data,len)
    local r = {}
    len = len or 4
    local p = 2^((len-1)*8)
    for i=1,len do
        r[i] = math.modf(data/p)
        data = data - r[i]*p
        p = p / 256
    end
    return r
end


function cmd_read_memory(serial, add, len)
    len = len <= 256 and len or 256
    local addData = to_msb(add)
    log("read " .. len .. " bytes from 0x" .. string.format("%08X",add))
    serial:write({0x11,0xee})
    local resp = serial:read(1)
    if resp[1] == STM32ISP.ACK then
        log("READ: ACK")
        local data = to_msb(add)
        data[#data+1] = check_sum(data)
        serial:write(data)
        --log_data(data)
        resp = serial:read(1)
        if resp[1] == STM32ISP.ACK then
            log("READ Add: ACK")
            data = { (len-1)}
            data[#data+1] = 255 - data[1]
            serial:write(data)
            --log_data(data)
            if resp[1] == STM32ISP.ACK then
                log("READ Len: ACK")
                -- read data from the BL
                resp = serial:read(len)
                log("Success read " .. #resp .. " bytes from 0x" .. string.format("%08X",add))
                return resp
            else
                log("READ Len: NAK")
            end
        else
            log("READ Add: NAK")
        end
    else
        log("READ: NAK")
    end
    return nil
end

function cmd_get_option(serial)
    serial:write({0x01,0xfe})
    local resp = serial:read(1)
    if resp[1] == STM32ISP.ACK then
        log("READ Option: ACK")
        local data = serial:read(3)
        log_data(data)
        resp = serial:read(1)
        if resp[1] == STM32ISP.ACK then
            log("READ Option Done: ACK")
        else
            log("READ Option Done: NAK")
        end
    else
        log("READ Option: NAK")
    end
end