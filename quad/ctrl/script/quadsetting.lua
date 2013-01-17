-- quadsetting.lua
dofile("control.lua")
dofile("language.lua")

class "QuadSetting" (QFrame)


QuadSetting.ANGLE = 1
QuadSetting.THRO = 2
QuadSetting.MOTOR = 3
QuadSetting.ANGLE_BTN = 4
QuadSetting.MOTOR_BTN = 5
function QuadSetting:__init()
    QFrame.__init(self)

    self.angleControl = {
        {loadStr("Roll"),  QValueSlider(1){min=2000, max=4000, minw = 60, offset = -3000, ratio = 720/2000}},
        {loadStr("Pitch"), QValueSlider(1){min=2000, max=4000, minw = 60, offset = -3000, ratio = 720/2000}},
        {loadStr("Yaw"),   QValueSlider(1){min=2000, max=4000, minw = 60, offset = -3000, ratio = 720/2000}},
    }
    self.throControl = {
        {loadStr("Thro"),  QValueSlider(1){min=2000, max=4000, minw = 60, offset = -2000}},
    }
    self.motorControl = {
        {loadStr("Motor").."1", QValueSlider(1){min=0, max=2000} },
        {loadStr("Motor").."2", QValueSlider(1){min=0, max=2000} },
        {loadStr("Motor").."3", QValueSlider(1){min=0, max=2000} },
        {loadStr("Motor").."4", QValueSlider(1){min=0, max=2000} },
    }

    self.btnSetAtt = QPushButton(loadStr("Set")){maxw=40}
    self.btnSetMotor = QPushButton(loadStr("Set")){maxw=40}
    self.btnRestoreAtt = QPushButton(loadStr("Restore")){maxw=40}
    self.btnRestoreMotor = QPushButton(loadStr("Restore")){maxw=40}
    self.valueChanged = nil

    self.btnSetAtt.clicked = function()
        self:valueChange(QuadSetting.ANGLE_BTN)
    end

    self.btnRestoreAtt.clicked = function()
        for i=1,3 do
            self.angleControl[i][2].slider.value = 0 - self.angleControl[i][2].offset
        end
        self.throControl[1][2].slider.value = 0 - self.throControl[1][2].offset        
        self:valueChange(QuadSetting.ANGLE_BTN)
    end

    self.btnSetMotor.clicked = function()
        self:valueChange(QuadSetting.MOTOR_BTN)
    end

    self.btnRestoreMotor.clicked = function()
        for i=1,4 do
            self.motorControl[i][2].slider.value = 0 - self.motorControl[i][2].offset
        end
        self:valueChange(QuadSetting.MOTOR_BTN)
    end
    
    self.attLayout = QFormLayout()
    for i=1,3 do
        self.angleControl[i][2].valueChanged = {self, self.angleChange}
        self.attLayout:addRow(
            self.angleControl[i][1],
            QHBoxLayout{self.angleControl[i][2].slider,self.angleControl[i][2].label}
        )
    end
    self.throControl[1][2].valueChanged = {self, self.throChange}
    self.attLayout:addRow(
            self.throControl[1][1],
            QHBoxLayout{self.throControl[1][2].slider,self.throControl[1][2].label}
        )

    self.attLayout:addRow(
        QHBoxLayout{
        self.btnSetAtt,
        self.btnRestoreAtt}
    )

    self.attSettings = QGroupBox(loadStr("Quad Set")){
        layout = self.attLayout
    }

    self.motorLayout = QFormLayout()
    for i=1,4 do
        self.motorControl[i][2].valueChanged = {self, self.motorChange}
        self.motorLayout:addRow(
            self.motorControl[i][1],
            QHBoxLayout{self.motorControl[i][2].slider,self.motorControl[i][2].label}
        )
    end
    self.motorLayout:addRow(
        QHBoxLayout{
        self.btnSetMotor,
        self.btnRestoreMotor}
    )
    self.motorSettings = QGroupBox(loadStr("Parame Set")){
        layout = self.motorLayout
    }

    self.layout = QHBoxLayout{
        self.attSettings,
        self.motorSettings,
    }
end

function QuadSetting:valueChange(reason)
    --log("reason:".. reason)
    local r = {}
    r.angle = {
        self.angleControl[1][2].slider.value + self.angleControl[1][2].offset,
        self.angleControl[2][2].slider.value + self.angleControl[2][2].offset,
        self.angleControl[3][2].slider.value + self.angleControl[3][2].offset,
    }
    r.thro  = self.throControl[1][2].slider.value + self.throControl[1][2].offset
    r.motor = {
        self.motorControl[1][2].slider.value + self.motorControl[1][2].offset,
        self.motorControl[2][2].slider.value + self.motorControl[2][2].offset,
        self.motorControl[3][2].slider.value + self.motorControl[3][2].offset,
        self.motorControl[4][2].slider.value + self.motorControl[4][2].offset,
    }
    if self.valueChanged then
        if type(self.valueChanged) == "table" then
            self.valueChanged[2](self.valueChanged[1],r,reason)
        else
            self.valueChanged(r,reason)
        end
    end
end

function QuadSetting:angleChange()
    self:valueChange(QuadSetting.ANGLE)
end

function QuadSetting:throChange()
    self:valueChange(QuadSetting.THRO)
end

function QuadSetting:motorChange()
    self:valueChange(QuadSetting.MOTOR)
end
