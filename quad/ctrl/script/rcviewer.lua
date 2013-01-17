-- Remote control viewer
dofile("control.lua")
dofile("language.lua")

class "RCViewer"(QFrame)

RCViewer.MAX_CHANNEL = 8
function RCViewer:__init()
    QFrame.__init(self)
    self.chControl = {}
    self.formControl = {}
    for i=1,self.MAX_CHANNEL do
        self.chControl[i] = {}
        self.chControl[i][1] = loadStr("Channel")..i
        self.chControl[i][2] = QValueSlider(3) {min=0,max=4000}
        self.formControl[i] = {
            self.chControl[i][1],
            QHBoxLayout{
                self.chControl[i][2].slider,
                self.chControl[i][2].label,
                QLabel(self:description(i)),
            },
        }
    end
    self.layout = QFormLayout(self.formControl)
end
RCViewer.desc = {
    "Thro",
}
function RCViewer:description(channel)
    local r = self.desc[channel]
    return r and loadStr(r) or loadStr("Channel") .. channel
end

function RCViewer:setChannel(v)
    local len = #v
    len = len>self.MAX_CHANNEL and self.MAX_CHANNEL or len
    for i=1,len do
        self.chControl[i][2].slider.value = v[i]
    end
end