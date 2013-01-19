-- quadviewer.lua
dofile("quadview.lua")
dofile("control.lua")
dofile("language.lua")

class "QuadViewer" (QFrame)

function QuadViewer:__init()
    QFrame.__init(self)
    self.quadview = get_quad_view(self)
    self.angleControl = {
        {loadStr("Roll"), QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Pitch"), QLineEdit("0"){readonly=true, minw = 60}},
        {loadStr("Yaw"), QLineEdit("0"){readonly=true, minw = 60}},
    }

    self.heightControl = {
        {loadStr("Height"), QLineEdit("0"){readonly=true, minw = 60} }
    }

    self.mototControl = {
        {QLineEdit("0"){readonly=true, minw = 60}, QColorButton("#00ff00")},
        {QLineEdit("0"){readonly=true, minw = 60}, QColorButton("#00ff00")},
        {QLineEdit("0"){readonly=true, minw = 60}, QColorButton("#00ff00")},
        {QLineEdit("0"){readonly=true, minw = 60}, QColorButton("#00ff00")},
    }

    self.angleParam = QGroupBox(loadStr("Angle")){
        layout = QFormLayout( self.angleControl )
    }

    self.heightParam = QGroupBox(loadStr("Height")){
        layout = QFormLayout( self.heightControl)
    }

    self.motorForm = QFormLayout()
    for i=1,4 do
        self.motorForm:addRow(loadStr("Motor") .. i,
            QHBoxLayout{self.mototControl[i][1],self.mototControl[i][2]}
        )
        self.mototControl[i][2].colorChanged = {self, self.motorColorChanged}
    end
    self.motorParam = QGroupBox(loadStr("Motor")){
        layout = self.motorForm,
    }

    self.layout = QHBoxLayout{
        QVBoxLayout{
            self.angleParam,
            self.heightParam,
            self.motorParam,
        },
        QGroupBox(loadStr("Preview")){
            layout = QVBoxLayout{self.quadview},
        },
        strech = "0,1",
    }
end

function QuadViewer:motorColorChanged()
    for i=1,4 do
        self.quadview.motorColor[i] = self.mototControl[i][2].color
    end
end

function QuadViewer:updateAngle(angle)
    local v
    v = angle["Pitch"] or angle[QuadView.PITCH] or v or self.quadview.quadAngle[QuadView.PITCH]
    self.angleControl[1][2].text = ""..v
    self.quadview.quadAngle[QuadView.PITCH] = v

    v = angle["Roll"] or angle[QuadView.ROLL] or self.quadview.quadAngle[QuadView.ROLL]
    self.angleControl[2][2].text = ""..v
    self.quadview.quadAngle[QuadView.ROLL] = v
    
    v = angle["Yaw"] or angle[QuadView.YAW] or self.quadview.quadAngle[QuadView.YAW]
    self.angleControl[3][2].text = ""..v
    self.quadview.quadAngle[QuadView.YAW] = v
end

function QuadViewer:updateHeight(h)
    h = h or self.quadview.quadPos[3]
    self.heightControl[1][2].text = ""..h
    self.quadview.quadPos[3] = h
end

function QuadViewer:updateMotor(motor)
    for i=1,#motor do
        self.mototControl[i][1].text = ""..motor[i]
        self.quadview.fanSpeed[i] = motor[i]*(50/2000)
    end
end
