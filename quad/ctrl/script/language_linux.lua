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
    ["GyroX"] = "角速度X",
    ["GyroY"] = "角速度Y",
    ["GyroZ"] = "角速度Z",
    ["Acc"] = "加速度",
    ["AccX"] = "加速度X",
    ["AccY"] = "加速度Y",
    ["AccZ"] = "加速度Z",
    ["Mag"] = "磁场",
    ["MagX"] = "磁场X",
    ["MagY"] = "磁场Y",
    ["MagZ"] = "磁场Z",
    ["Sensor"] = "传感器",
    ["Sensor Data"] = "传感器数据",
    ["Save"] = "保存",
    ["Load"] = "加载",
    ["Height"] = "高度",
    ["Restore"] = "还原­",
    ["RC Data"] = "遥控数据",
    ["Channel"] = "通道",
}

-- set current language
Lang.current = Lang.Chn
function loadStr(id)
    return Lang[Lang.current][id] or Lang[Lang.Eng][id] or id
end
