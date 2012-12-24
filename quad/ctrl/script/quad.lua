-- Draw the quad copter
logEdit:clear()
-- Draw the fans
function draw_fan(fan,init_angle,fan_count,pos,unit)
    init_angle = init_angle or 45   -- set the fan init angle, default is 45 for X copter
    fan_count = fan_count or 4      -- set the default fan count
    pos = pos or 0                  -- fan position for animation
    dAngle = 360 / fan_count        -- fan angles

    for i=1,fan_count do
        gl.PushMatrix()
    
        gl.Color(0.0,1.0,0.0)
        gl.Rotate(init_angle, 0.0, 0.0, -1.0);
        gl.Translate(unit*10,0.0,0.16)
        local dir = 1-math.fmod(i,2)*2
        gl.Rotate(pos/360.0*360.0*dir, 0.0, 0.0, -1.0);
        fan:render(1.1*unit)
        init_angle = init_angle + dAngle

        gl.PopMatrix()
    end
end

function draw_copter(body,fan,fan_pos,is_cross,fan_count,x,y,z,yaw,pitch,roll)
    init_angle = is_cross and 45 or 0
    x = x or 0.0
    y = y or 0.0
    z = z or 0.0
    yaw = yaw or 0.0
    pitch = pitch or 0.0
    roll = roll or 0.0
    fan_count = fan_count or 4
    
    gl.Translate(x,y,z)             -- translate the body
    gl.Rotate(180, 0.0, 0.0, -1.0);  -- rotate the body 180 degree

    gl.Rotate(yaw, 0.0, 0.0, -1.0);    -- rotate by Z axis
    gl.Rotate(pitch, 0.0, -1.0, 0.0);  -- rotate by Y axis
    gl.Rotate(roll, -1.0, 0.0, 0.0);   -- rotate by X axis
    
    gl.Color(1.0,0.0,0.0)              -- set the body color
    body:render(1/body.size)           -- render the body
    draw_fan(fan,init_angle,fan_count,fan_pos,1/body.size)
end

local andgle = 180
body = QObject3ds()
body:load("3Ds/Cross4.3DS")  -- load quadcopter body from the 3DS file, candidate: X4.3DS, X8.3DS
fan = QObject3ds()
fan:load("3Ds/f3.3DS")  -- load fans from the 3DS file, candidate: f2.3DS

splitter = QSplitter(mainWindow)
viewer = QGLViewer(mainWindow)
splitter:addWidget(viewer)
xSlider = QSlider(1){ max = 100, min = -100}
ySlider = QSlider(1){ max = 100, min = -100}
zSlider = QSlider(1){ max = 100, min = -100}

rxSlider = QSlider(1){ max = 360, min = -360}
rySlider = QSlider(1){ max = 360, min = -360}
rzSlider = QSlider(1){ max = 360, min = -360}

restoreBtn = QPushButton("ԭ")
restoreBtn.clicked = function ()
    xSlider.value = 0
    ySlider.value = 0
    zSlider.value = 0
    rxSlider.value = 0
    rySlider.value = 0
    rzSlider.value = 0
end

restoreCam = QPushButton("ԭ")
function restoreCam.clicked()
    viewer.camera.position = QGLVec(0.0,-3.0,1.5)
    viewer.camera:lookAt( QGLVec(viewer.sceneCenter) )
end

function draw_solar()
   draw_copter(body,fan,andgle,false,4,
    xSlider.value/100,ySlider.value/100,zSlider.value/100, -- transform params
    rzSlider.value,rySlider.value,rxSlider.value)          -- rotate params
end

frame = QGroupBox("̬"){
 w = 200,
 layout = QFormLayout{
    {"X:", xSlider},
    {"Y:", ySlider},
    {"Z:", zSlider},
    {"Yaw:",rzSlider},
    {"Pith:",rySlider},
    {"Roll:",rxSlider},
    "һ",
    {"ԭ̬",restoreBtn},
    {"ԭͷ",restoreCam},
    }
}
--splitter:addWidget(frame)

viewer.animateNeeded = function()
    andgle = andgle + 10
    if andgle > 360 then
        andgle = 0
    end
end


viewer.axisIsDrawn = true  -- display the axis
viewer.gridIsDrawn = true  -- display the grid
viewer.drawNeeded = draw_solar
viewer.camera.position = QGLVec(0.0,-3.0,1.5)
viewer.camera:lookAt(QGLVec(viewer.sceneCenter) )
viewer:startAnimation()

mdiArea:addSubWindow(splitter):show()