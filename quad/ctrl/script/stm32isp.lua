-- STM32 ISP host side
-- refer to AN2606 and AN3155

dofile("hex.lua")
class "STM32ISP"(QFrame)

STM32ISP.ACK = 0x79
STM32ISP.NAK = 0x1F
STM32ISP.DETECT = 0x7F
STM32ISP.START_ADDRR = 0x08000000
STM32ISP.PAGE_SIZE = 0x400
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
    self.btnErase = QPushButton("Erase")
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
            self.btnErase,
            QLabel(""),
            strech = "0,0,0,0,0,1"
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
        self.flashData.data = bin.data
        self.flashData.addressOffset = bin.start_addr or 0
    end
    
    self.progress.min = 0
    self.progress.max = 20
    self.btnProg.clicked = function()
        -- calc data size
        local dataLen = #self.flashData.data
        -- divide them into 256 bytes
        --[[
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
        --t = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}
        --self.flashData:append(t)
        --self.flashData:append(t)

        --dataLen = #self.flashData.data
        --]]
        local add = tonumber("0x" .. self.startAdd.text)
        local remain = dataLen
        local idx = 1
        self.progress.max = add + dataLen
        self.progress.min = add
        self.progress.value = add
        while remain > 128 do
            local d = get_data(self.flashData.data, idx, 128)
            cmd_write_memory(self.serial, add, d)
            add = add + 128
            idx = idx + 128
            remain = remain - 128
            self.progress.value = add
        end
        if remain > 0 then
            local d = get_data(self.flashData.data, idx, remain)
            cmd_write_memory(self.serial, add, d)
        end
        self.progress.value = add + remain
    end

    self.btnErase.clicked = function()
        local dataLen = #self.flashData.data
        local add = tonumber("0x" .. self.startAdd.text)
        cmd_erase_page(self.serial,add,dataLen)
    end

    self.btnDetect.clicked = function()
        -- detect the ISP
        self.serial:write({self.DETECT})
        local resp = self.serial:read(1)
        if resp[1] == self.ACK then
            log("Detect: ACK")
        else
            log("Detect:" .. #resp .. "," .. dec2hex(resp[1]))
            return
        end
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
        self.progress.max = add + len
        self.progress.min = add
        self.progress.value = add
        while len >128 do
            flashData = cmd_read_memory(self.serial, add, 128)
            self.flashData:append(flashData)
            add = add + 128
            len = len - 128
            self.progress.value = add
        end
        if len > 0 then
            flashData = cmd_read_memory(self.serial, add, len)
            self.flashData:append(flashData and flashData or {})
        end
        self.progress.value = add + len
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

function get_data(data, start, len)
    local l = #data
    local r = {}
    for i=start,start+len-1 do
        r[#r+1] = data[i]
        if i > l then
            return r
        end
    end
    return r
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
        if i - math.modf(i/16)*16 == 0 then
            log(str)
            str = "(" .. #data .. "):"
        end
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

function append_data(data,buf)
    for i=1,#buf    do
        table.insert(data,buf[i])
    end
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
        data[#data+1] = len - 1
        data[#data+1] = 255 - len + 1
        serial:write(data)
        --log_data(data)
        resp = serial:read(1)
        if resp[1] == STM32ISP.ACK then
            log("READ Add: ACK")
            --data = { (len-1)}
            --data[#data+1] = 255 - data[1]
            --serial:write(data)
            --log_data(data)
            resp = serial:read(1)
            if resp[1] == STM32ISP.ACK then
                log("READ Len: ACK")
                -- read data from the BL
                local res = {}
                while len>0 do
                    resp = serial:read(len)
                    len = len - #resp
                    append_data(res,resp)
                end
                log("Success read " .. #res .. " bytes from 0x" .. string.format("%08X",add))
                return res
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

function cmd_write_memory(serial, add, mem_data)
    local len = #mem_data
    --log("got " .. len .. "bytes")
    while len - math.modf(len/4)*4 ~= 0 do
        log( "pad len " .. len)
        mem_data[#mem_data+1] = 0xff
        len = #mem_data
    end
    len = len <= 128 and len or 128
    local addData = to_msb(add)
    log("write " .. len .. " bytes to 0x" .. string.format("%08X",add))
    serial:write({0x31,0xce})
    local resp = serial:read(1)
    if resp[1] == STM32ISP.ACK then
        log("Write: ACK")
        local data = to_msb(add)
        data[#data+1] = check_sum(data)
        data[#data+1] = len - 1
        serial:write(data)
        log_data(data)
        --resp = serial:read(1)
        resp = {STM32ISP.ACK}
        if resp[1] == STM32ISP.ACK then
            log("Write Add: ACK")
            --data = { (len-1)}
            --data[#data+1] = 255 - data[1]
            --serial:write(data)
            --log_data(data)
            --resp = serial:read(1)
            if resp[1] == STM32ISP.ACK then
                log("Write Len: ACK")
                -- write data to the BL
                mem_data[#mem_data+1] = bit_xor(check_sum(mem_data), len-1)
                serial:write(mem_data)
                log_data(mem_data)
                log(string.format("%02X",mem_data[129]))
                resp = serial:read(2)
                log("Write " .. len .. " bytes to 0x" .. string.format("%08X",add) .. "  result:" .. dec2hex(resp[1]) .. "," .. dec2hex(resp[1]))
                return len
            else
                log("Write Len: NAK")
            end
        else
            log("Write Add: NAK")
        end
    else
        log("Write: NAK")
    end
    return 0
end

function cmd_erase_page(serial, add, len)
    add = math.modf(add/STM32ISP.PAGE_SIZE)*STM32ISP.PAGE_SIZE
    log(string.format("Add: %08X, count:%d",add,len))
    len = math.modf((len+STM32ISP.PAGE_SIZE-1)/STM32ISP.PAGE_SIZE)
    if add < STM32ISP.START_ADDRR then
        return nil
    end
    local startPage = math.modf( (add - STM32ISP.START_ADDRR)/STM32ISP.PAGE_SIZE) + 1
    log("start page " .. startPage .. "  page count: " .. len)
    serial:write({0x44,0xbb})
    local resp = serial:read(1)
    if resp[1] == STM32ISP.ACK then
        log("Extend erase: ACK")
        local data = to_msb(startPage-1,2)
        local data1 = to_msb(len-1,2)
        data[#data+1] = data1[1]
        data[#data+1] = data1[2]
        data[#data+1] = check_sum(data)
        serial:write(data)
        resp = serial:read(1)
        if resp[1] == STM32ISP.ACK then
            log("Extend erase page: ACK")
            resp = serial:read(1)
            if resp[1] == STM32ISP.ACK then
                log("Extend erase done: ACK")
            else
                log("Extend erase done: NAK")
            end
        else
            log("Extend erase page: NAK")
        end
    else
        log("Extend erase: NAK")
    end
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