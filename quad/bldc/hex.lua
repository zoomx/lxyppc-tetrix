--logEdit:clear()

function digi2hex(d)
    local s = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"}
    return s[d+1]
end
function dec2hex(v)
    if v then
        if v < 0 then
            v = v + 256
        end
        local h = math.modf(v/16)
        local l = v - h*16
        return digi2hex(h) .. digi2hex(l)
    end
    return "nil"
end

function hex2dec(v)
    local res = 0
    for i = 1,string.len(v) do
        local s = string.upper(v:sub(i,i))
        res = res * 16
        if s > "F" then
            res = res + 0
        elseif s > "9" then
            res = res + string.byte(s,1) - string.byte("A",1) + 10
        else
            res = res + (s and tonumber(s) or 0)
        end
    end
    return res
end

function check_hex_sum(line)
    if line:sub(1,1) ~= ":" then
        return false
    end
    local cnt = hex2dec(line:sub(2,3))
    local sum = cnt
    cnt = cnt + 1 -- include the check sum data
    sum = sum + hex2dec(line:sub(4,5)) -- address
    sum = sum + hex2dec(line:sub(6,7)) -- address
    sum = sum + hex2dec(line:sub(8,9)) -- type
    for i = 1, cnt do
        sum = sum + hex2dec(line:sub(8+i*2, 9 + i*2))
    end
    return sum % 256 == 0
end

function load_hex_file(path)
    file = io.open(path,"r")
    cur_addr = 0
    bin = {}
    local data_record = 0
    local end_of_record = 1
    local ext_seg_addr = 2
    local seg_addr = 3
    local ext_line_addr = 4
    local line_addr = 5
    if file then
        for line in file:lines() do
            
            if check_hex_sum(line) or true then    
                count = hex2dec(line:sub(2,3))
                addr = hex2dec(line:sub(4,7))
                type = hex2dec(line:sub(8,9))
                cksum = hex2dec(line:sub(count*2+10,count*2+11))
                --log("data count: " .. count .. "   type: " .. type .. string.format("  addr:%08x, ckssum:%02x, valid:", addr, cksum) .. tostring(check_hex_sum(line)))
                if type == data_record then
                    cur_addr =  cur_addr - (cur_addr%(2^16)) + addr
                    --local sss = string.format("%04X00",addr)
                    for i = 1,count do
                        bin.start_addr = bin.start_addr or cur_addr
                        bin[cur_addr + i - bin.start_addr] = hex2dec(line:sub(8+i*2, 9 + i*2))
                        --sss = sss .. string.format("%02X",hex2dec(line:sub(8+i*2, 9 + i*2)))
                    end
                    --log(sss)
                elseif type == end_of_record and count == 0 then
                    -- don't care
                elseif type == ext_seg_addr and count == 2 then
                    -- don't care
                elseif type == seg_addr and count == 4 then
                    -- don't care
                elseif type == ext_line_addr and count == 2 then
                    cur_addr = cur_addr % (2^16) + hex2dec(line:sub(10,13))*(2^16)
                elseif type == line_addr and count == 4 then
                    cur_addr = hex2dec(line:sub(10,17))
                end
            end
        end
        file:close()
    end
    return bin
end


function load_bin_file(path)
    local file = QFile(path)
    file:open()
    local bin = file:readAll()
    file:close()
    return bin
end

--[[
path = QCommonDlg.getOpenFileName("","","Hex文件(*.hex);;全部文件(*)")

prefix = path:sub(#path-2,#path)
prefix = prefix:upper()

content = prefix == "HEX" and load_hex_file(path) or load_bin_file(path)

edit = QHexEdit()
dlg = QDialog{
    layout = QHBoxLayout{
        edit
    },
    w = 400, h = 300
}

edit.data = content
edit.addressOffset = content.start_addr or 0
dlg:exec()
dlg = nil
--]]