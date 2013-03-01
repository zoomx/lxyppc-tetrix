-- quaternion.lua
-- press ctrl+R to run the script
--quadPos
--fanDir
--fanSpeed
logEdit:clear()
ROLL = model.ROLL
PITCH = model.PITCH
YAW = model.YAW
PI = math.acos(0)*2

function ang2rad(ang)
    return ang*PI/180
end

function rad2ang(rad)
    return rad*180/PI
end

function rad2angs(rads)
    local r = {}
    for i=1,#rads do  r[i]=rad2ang(rads[i])  end
    return r
end

function disp_euler(euler)
    log( "ROLL:" .. euler[ROLL] ..
         ", PITCH:" .. euler[PITCH] ..
         ", YAW:" .. euler[YAW]
    )
end

function disp_quad(quad)
    log( "W:" .. quad[1] ..
         ", X:" .. quad[2] ..
         ", Y:" .. quad[3] ..
         ", Z:" .. quad[4] ..
         ", |q| = " .. math.sqrt(
            quad[1]*quad[1] + quad[2]*quad[2]
          + quad[3]*quad[3] + quad[4]*quad[4]
        )
    )
    ang = rad2ang(math.acos(quad[1])*2)
    x = quad[2] / math.sin(ang/2)
    y = quad[3] / math.sin(ang/2)
    z = quad[4] / math.sin(ang/2)
    log("Rotate: " .. ang .. "deg at(" 
    .. x .. "," .. y .. "," .. z .. ")")
end

function euler2quad(euler)
    local r = ang2rad(euler[ROLL])
    local p = ang2rad(euler[PITCH])
    local y = ang2rad(euler[YAW])
    local quad = {
        math.cos(r/2)*math.cos(p/2)*math.cos(y/2)+
        math.sin(r/2)*math.sin(p/2)*math.sin(y/2),

        math.sin(r/2)*math.cos(p/2)*math.cos(y/2)-
        math.cos(r/2)*math.sin(p/2)*math.sin(y/2),

        math.cos(r/2)*math.sin(p/2)*math.cos(y/2)+
        math.sin(r/2)*math.cos(p/2)*math.sin(y/2),

        math.cos(r/2)*math.cos(p/2)*math.sin(y/2)-
        math.sin(r/2)*math.sin(p/2)*math.cos(y/2),
    }
    return quad
end

function quad2euler(quad)
    local euler = {0,0,0}
    local w = quad[1]
    local x = quad[2]
    local y = quad[3]
    local z = quad[4]
    euler[ROLL] = math.atan2(2*(w*x+y*z), 1-2*(x*x+y*y))
    euler[PITCH] = math.asin(2*(w*y-z*x))
    euler[YAW] = math.atan2(2*(w*z+x*y),1-2*(y*y+z*z))
    return rad2angs(euler)
end

function quad_iter(quad, gx, gy, gz)
    q0 = quad[1]
    q1 = quad[2]
    q2 = quad[3]
    q3 = quad[4]
    halfT = 0.5
    q0i = (-q1 * gx - q2 * gy - q3 * gz) * halfT;
    q1i = (q0 * gx + q2 * gz - q3 * gy) * halfT;
    q2i = (q0 * gy - q1 * gz + q3 * gx) * halfT;
    q3i = (q0 * gz + q1 * gy - q2 * gx) * halfT;
    q0 = q0 + q0i;
    q1 = q1 + q1i;
    q2 = q2 + q2i;
    q3 = q3 + q3i;
    return {q0,q1,q2,q3}
end

euler = {0,0,0}
euler[ROLL] = model.quadAngle[ROLL]
euler[PITCH] = model.quadAngle[PITCH]
euler[YAW] = model.quadAngle[YAW]
quad = euler2quad(euler)
quad = quad_iter(quad, ang2rad(10) , ang2rad(10),0)
euler = quad2euler(quad)
disp_euler(euler)
disp_quad(quad)

model.quadAngle[ROLL] = euler[ROLL]
model.quadAngle[PITCH] = euler[PITCH]
model.quadAngle[YAW] = euler[YAW]
model.quadAngle[ROLL] = 0
model.quadAngle[PITCH] = 0
model.quadAngle[YAW] = 0

log("done")