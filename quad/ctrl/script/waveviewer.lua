-- waveviewer.lua
-- implement the waverorm viewer

dofile("waveview.lua")
dofile("control.lua")
dofile("language.lua")

class "WaveViewer"(QFrame)

function WaveViewer:__init()
    QFrame.__init(self)
    self.elements = {}
    self.nameList = {}
    self.viewer = WaveView()
    self.elementLayout = QFormLayout()
    self.btnLoad = QPushButton(loadStr("Load"))
    self.btnSave = QPushButton(loadStr("Save"))
    self.slider = QSlider(1){min = 1, max = 10}

    self.btnLoad.clicked = function()
        local name = QCommonDlg.getOpenFileName()
        local file = io.open(name,"r")
        if file then
            local line = file:read()
            local ready = true
            local nameIdx = 1
            for val in line:gmatch("([^\t]*)\t") do
                --log("get name: " .. val)
                if self.elements[val] then
                    self.elements[val].data = {}
                    self.elements[val].viewer.data = self.elements[val].data
                    self.nameList[nameIdx] = val
                    nameIdx = nameIdx + 1
                else
                    ready = false
                    log("Field [" .. val .. "] mismatch, ignore this file")
                end
            end
            --for i=1,9 do self.sensorsData[i] = {}; self.sensorGraph.data[i].data = self.sensorsData[i] end
            while line and ready do
                line = file:read()
                if line then
                    local idx = 1
                    for value in line:gmatch("([^\t]*)\t") do
                        local v = tonumber(value)
                        local n = self.nameList[idx]
                        self.elements[n].data[ #self.elements[n].data + 1] = v
                        idx = idx+1
                        --log("v:".. (v or "nil") .. ", value:".. value)
                    end
                    --log("get " .. idx .. " content")
                end
            end
            --log("load " .. #self.sensorsData[1] .. " records")
            self.slider.max = #self.elements[ self.nameList[1] ].data
            self.slider.value = 1
            file:close()
        end
    end

    self.btnSave.clicked = function()
        local name = QCommonDlg.getSaveFileName()
        local file = io.open(name,"w+")
        if file then
            local namelen = #self.nameList
            for i=1,namelen do
                file:write(self.nameList[i] .. "\t")
            end
            file:write("\n")
            --file:write("gyroX\tgyroY\tgyroZ\taccX\taccY\taccZ\tmagX\tmagY\tmaxZ\n")
            if namelen> 0 then
                local len = #self.elements[self.nameList[1]].data
                for i=1,len do
                    for j=1,namelen do
                        local name = self.nameList[j]
                        file:write(self.elements[name].data[i],"\t")
                    end
                    file:write("\n")
                end
            end
            file:close()
        end
    end

    self.slider.valueChanged = function()
        if self.slider.value == self.slider.max then
            self.viewer:startAnimation()
        else
            if self.viewer.isAnimate then
                self.viewer:stopAnimation()
                self.slider.max = #self.elements[ self.nameList[1] ].data
            else
                self.viewer:setDataPos(self.slider.value)
            end
        end
    end

    self.layout = QVBoxLayout{
        QHBoxLayout{
            self.elementLayout,
            self.viewer,
            strech = "0,1",
        },
        QHBoxLayout{
            self.btnLoad,
            self.btnSave,
            self.slider,
            strech = "0,0,1",
        },
    }
end

function WaveViewer:updateColors()
    for k,v in pairs(self.elements) do
        -- assign color btn's value to the viewer
        v.viewer.color = v.color.color
    end
end

function WaveViewer:updateDisplay()
    for k,v in pairs(self.elements) do
        -- assign check btn's value to the viewer
        v.viewer.display = v.check.checked
    end
end

function WaveViewer:addData(name, displayName)
    displayName = displayName or loadStr(name)
    self.elements[name] = {}
    self.elements[name].displayName = displayName
    self.elements[name].data = {}
    local viewer = self.viewer:addData(self.elements[name].data)
    self.elements[name].viewer = viewer
    self.elements[name].edit = QLineEdit("0"){readonly=true, minw = 60}
    self.elements[name].color = QColorButton(viewer.color)
    self.elements[name].color.colorChanged = {self, self.updateColors}
    self.elements[name].check = QCheckBox(){
            maxw = 20, maxh=20, 
            checked = viewer.display,
            clicked = {self,self.updateDisplay}}
    viewer.min = -20480
    viewer.max = 20480
    self.elementLayout:addRow(
        displayName,
        QHBoxLayout{
            self.elements[name].edit,
            self.elements[name].color,
            self.elements[name].check
        })--]]
    self.nameList[#self.nameList + 1] = name
end