class "QuadView" (QGLViewer)


QuadView.X = 1
QuadView.Y = 2
QuadView.Z = 3
QuadView.PITCH = 1
QuadView.ROLL = 2
QuadView.YAW = 3

function QuadView:__init(parent,body,fan)
    QGLViewer.__init(self, mainWindow)
    self.axisIsDrawn = true
    self.gridIsDrawn = true
    self.body = QObject3ds()
    self.body:load(body)
    self.fan = QObject3ds()
    self.fan:load(fan)
    self.fanSpeed = {0,0,0,0,0,0,0,0}
    self.fanPos = {0,0,0,0,0,0,0,0}
    self.fanDir = {1,-1,1,-1}
    self.quadPos = {0,0,0} -- x,y,z
    self.quadAngle = {0,0,0} -- pitch,roll,yaw
    self.fanCount = 4
    self.fanInitAngle = 45
    local color = QColor("#00ff00")
    self.motorColor = {color,color,color,color,color,color,color,color,}
    self.bodyColor = {0.2,0,0}

    self.drawNeeded = {self, self.draw_quad}
    self.animateNeeded = {self, self.update_pos}
    self:startAnimation()
end

function QuadView:draw_quad()
    --log("draw quad")
    gl.Translate(self.quadPos[self.X],self.quadPos[self.Y],self.quadPos[self.Z])
    gl.Rotate(180, 0.0, 0.0, -1.0);
    gl.Rotate(self.quadAngle[self.YAW], 0.0, 0.0, -1.0);    -- rotate by Z axis
    gl.Rotate(self.quadAngle[self.PITCH], 0.0, -1.0, 0.0);  -- rotate by Y axis
    gl.Rotate(self.quadAngle[self.ROLL], -1.0, 0.0, 0.0);   -- rotate by X axis
    --  set body color
    --gl.Color(1.0,0.0,0.0)
    gl.Color(self.bodyColor)
    local unit = 1/self.body.size
    self.body:render(unit)
    local dAngle = 360 / self.fanCount
    local fanAngle = self.fanInitAngle
    for i=1,self.fanCount do
        gl.PushMatrix()
        -- set fan color
        local color = self.motorColor[i]
        --gl.Color(0.0,1.0,0.0)
        gl.Color(color.r/255.0*0.2,color.g/255.0*0.2,color.b/255.0*0.2)
        
        gl.Rotate(fanAngle, 0.0, 0.0, -1.0);
        gl.Translate(unit*10,0.0,0.16)
        gl.Rotate(self.fanPos[i]/360.0*360.0*self.fanDir[i], 0.0, 0.0, -1.0);
        self.fan:render(1.1*unit)
        fanAngle = fanAngle + dAngle
        gl.PopMatrix()
    end
end

function QuadView:update_pos()
    --log("update pos")
    for i=1,self.fanCount do
        self.fanPos[i] = self.fanPos[i] + self.fanSpeed[i]
        while self.fanPos[i] > 360 do
            self.fanPos[i] = self.fanPos[i] - 360
        end
        while self.fanPos[i] < 0 do
            self.fanPos[i] = self.fanPos[i] + 360
        end
    end
end

function get_quad_view(parent,body,fan)
    body = body and body or "3Ds/X4.3DS"
    fan = fan and fan or "3Ds/f3.3DS"
    qv = QuadView(parent,body,fan)
    qv.camera.position = QGLVec(0.0,-3.0,1.5)
    qv.camera:lookAt(QGLVec(qv.sceneCenter))
    return qv
end
