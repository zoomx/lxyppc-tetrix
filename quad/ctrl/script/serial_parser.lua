-- serial_parser.lua
class "SerialParser"
SerialParser.IDLE = 0
SerialParser.HEAD1 = 1
SerialParser.HEAD2 = 2
SerialParser.LEN1 = 3
SerialParser.LEN2 = 4
SerialParser.DATA = 5
SerialParser.CS1 = 6
SerialParser.CS2 = 7
SerialParser.H1 = 0x55
SerialParser.H2 = 0xaa
function SerialParser:__init()
    self.state = self.IDLE
    self.data = {}
    self.len = 0
    self.len_buf = {0,0}
    self.cs = 0
    self.cs_calc = 0
    self.get_data = nil
end

function SerialParser:log(x)
    log(x)
end

function SerialParser:pack_data(data)
    local len = #data
    local l = QUtil.fromUint16(len)
    local r = {self.H1, self.H2, l[2], l[1]}
    local chk = 0x55 + 0xaa
    chk = chk + (l[2]<0 and l[2]+256 or l[2])
    chk = chk + (l[1]<0 and l[1]+256 or l[1])
    for k,v in pairs(data) do
        if v < 0 then
            v = v + 256
        end
        chk = chk + v
        r[k+4] = v
    end
    --while chk > 65535 do
    --    chk = chk - 65536
    --end
    
    l = QUtil.fromUint16(chk)
    --a = math.modf(chk/256)
    --b = chk - 256*a
    r[#r+1] = l[2]
    r[#r+1] = l[1]
    --log(#r)
    return r
end

function to_uint8(x)
    return x<0 and x + 256 or x
end

function SerialParser:update(byte)
    if self.state == self.IDLE and byte == self.H1 then
        self.state = self.HEAD1
        self.cs_calc = self.cs_calc + to_uint8(byte)
        --self:log("Head1")
    elseif self.state == self.HEAD1 and byte == self.H2 then
        self.state = self.HEAD2
        self.cs_calc = self.cs_calc + to_uint8(byte)
        --self:log("Head2")
    elseif self.state == self.HEAD2 then
        self.state = self.LEN1
        self.cs_calc = self.cs_calc + to_uint8(byte)
        self.len = byte*256
        self.len_buf[2] = byte
        --self:log("len1")
    elseif self.state == self.LEN1 then
        self.state = self.DATA
        self.cs_calc = self.cs_calc + to_uint8(byte)
        self.len_buf[1] = byte
        self.len = QUtil.toUint16(self.len_buf)
        self.data = {}
        --self:log("len2  len=" .. self.len)
    elseif self.state == self.LEN2 then
        self.state = self.DATA
    elseif self.state == self.DATA then
        if #self.data < self.len then
            self.data[#self.data+1] = byte
        self.cs_calc = self.cs_calc + to_uint8(byte)
            --self:log("data")
        else
            self.state = self.CS1
            self.cs = to_uint8(byte) * 256;
            --self:log("cs1")
        end
    elseif self.state == self.CS1 then
        self.cs = self.cs + to_uint8(byte)
        --log("cs:" .. self.cs .. ", calc:" .. self.cs_calc)
        if self.cs == self.cs_calc then
            log("got data")
            if self.get_data then
                if type(self.valueChanged) == "table" then
                    self.get_data[2](self.get_data[1],self.data)
                else
                    self.get_data(self.data)
                end
            end
            --log(QUtil.showBytes(self.data))
        end
        --self:log("cs2")
    else
        self.state = self.IDLE    
        --self:log("error")
    end
    
end

function SerialParser:parse_data(data)
    for i=1,#data do
        self:update(data[i])
    end
end
--log(x)