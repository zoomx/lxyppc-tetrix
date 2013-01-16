-- language.lua
-- language implements

Lang = { Eng = 1, Chn = 2}
Lang[Lang.Eng] = {
    ["Title"] = "Quad Flight Monitor",
}
Lang[Lang.Chn] = {
    ["Title"] = "四轴监控器",
    ["Open"] = "打开",
    ["Send"] = "发送",
    ["Close"] = "关闭",
    ["Clear"] = "清除",
    ["Refresh"] = "刷新",
    ["Pitch"] = "俯仰",
    ["Roll"] = "横滚",
    ["Yaw"] = "偏航",
    ["Motor"] = "电机",
    ["exeTime"] = "执行时间",
    ["Thro"] = "油门",
    ["Preview"] = "预览",
    ["Angle"] = "角度",
    ["Attitude Data"] = "姿态数据",
    ["Parame Set"] = "参数设置",
    ["Quad Set"] = "四轴设置",
    ["Motor Set"] = "电机设置",
    ["Set"] = "设置",
    ["Gyro"] = "角速度",
    ["Acc"] = "加速度",
    ["Mag"] = "磁场",
    ["Sensor"] = "传感器",
    ["Sensor Data"] = "传感器数据",
    ["Save"] = "保存",
    ["Load"] = "加载",
}

-- set current language
Lang.current = Lang.Chn
function loadStr(id)
    return Lang[Lang.current][id] or Lang[Lang.Eng][id] or id
end
