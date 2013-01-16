--script.lua
--lua中的单行注释，以两个-开头，一址到该行的结尾，和C/C++中的//注释一样
--[[
这个是lua中的多行注释
以两个"-"和两个"["开头，以两个"]"结尾，和C/C++中的 /* 与 */一样
]]
-- 定义一个函数log，函数带一个参数 v
-- 这个函数简化了增加log信息的操作，如果参数是数字可以自动转化成字符
function log(v)
    logEdit:append(tostring(v))
end
dofile("quadmonitor.lua")
mdiArea:addSubWindow( QuadMonitor()  ):show()
