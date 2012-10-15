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

function unpack(r)
    local len = #r
    if len == 1 then
        return r[1]
    elseif len == 2 then
        return r[1],r[2]
    elseif len == 3 then
        return r[1],r[2],r[3]
    elseif len == 4 then
        return r[1],r[2],r[3],r[4]
    end
    return r
end

function to_lsb_b(data,len)
    local r = to_lsb(data,len)
    return unpack(r)
end

function to_msb_b(data,len)
    local r = to_msb(data,len)
    return unpack(r)
end