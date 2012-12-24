class "QuadViewer" (QGLViewer)


QuadViewer.X = 1
QuadViewer.Y = 2
QuadViewer.Z = 3
QuadViewer.PITCH = 1
QuadViewer.ROLL = 2
QuadViewer.YAW = 3

function QuadViewer:__init(parent,body,fan)
    QGLViewer.__init(self, mainWindow)
    self.axisIsDrawn = true
    self.gridIsDrawn = true
    self.body = QObject3ds()
    self.body:load(body)
    self.fan = QObject3ds()
    self.fan:load(fan)
    self.fanSpeed = {1,1,1,1,0,0,0,0}
    self.fanPos = {0,0,0,0,0,0,0,0}
    self.fanDir = {1,-1,1,-1}
    self.quadPos = {0,0,0} -- x,y,z
    self.quadAngle = {0,0,0} -- pitch,roll,yaw
    self.fanCount = 4
    self.fanInitAngle = 45

    self.drawNeeded = {self, self.draw_quad}
    self.animateNeeded = {self, self.update_pos}
    self:startAnimation()
end

function QuadViewer:draw_quad()
    --log("draw quad")
    gl.Translate(self.quadPos[self.X],self.quadPos[self.Y],self.quadPos[self.Z])
    gl.Rotate(180, 0.0, 0.0, -1.0);
    gl.Rotate(self.quadAngle[self.YAW], 0.0, 0.0, -1.0);    -- rotate by Z axis
    gl.Rotate(self.quadAngle[self.PITCH], 0.0, -1.0, 0.0);  -- rotate by Y axis
    gl.Rotate(self.quadAngle[self.ROLL], -1.0, 0.0, 0.0);   -- rotate by X axis
    gl.Color(1.0,0.0,0.0)
    local unit = 1/self.body.size
    self.body:render(unit)
    local dAngle = 360 / self.fanCount
    local fanAngle = self.fanInitAngle
    for i=1,self.fanCount do
        gl.PushMatrix()
        gl.Color(0.0,1.0,0.0)
        gl.Rotate(fanAngle, 0.0, 0.0, -1.0);
        gl.Translate(unit*10,0.0,0.16)
        gl.Rotate(self.fanPos[i]/360.0*360.0*self.fanDir[i], 0.0, 0.0, -1.0);
        self.fan:render(1.1*unit)
        fanAngle = fanAngle + dAngle
        gl.PopMatrix()
    end
end

function QuadViewer:update_pos()
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
    qv = QuadViewer(parent,body,fan)
    qv.camera.position = QGLVec(0.0,-3.0,1.5)
    qv.camera:lookAt(QGLVec(qv.sceneCenter))
    return qv
end
