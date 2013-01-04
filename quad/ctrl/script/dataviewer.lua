class "DataViewer" (QFrame)
logEdit:clear()
DataViewer.gridColorX = QColor("darkgray")
DataViewer.gridColorY = QColor("darkgray")
DataViewer.bankColor2 = QColor("black")
DataViewer.bankColor = QColor("black")
DataViewer.margins = {10,10,10,10} --- left,right,top,bottom
DataViewer.defaultColors = {
    QColor("red"),
    QColor("blue"),
    QColor("lightgreen"),
    QColor("lightblue"),
    QColor("yellow"),
    QColor("orange"),
    QColor("pink"),
    QColor("cyan"),
    QColor("orchid"),
}

function DataViewer:__init()
    QFrame.__init(self)
    self.windowTitle = "Data Viewer"
    self.minW = 100
    self.minH = 100
    self.gridX = 50
    self.gridY = 50
    self.scale = 1

    self.eventFilter = QPaintEvent.filter(
    function(obj,evt)
        self:paint_data(evt)
    end)
    self.data = {}

    self.eventFilter = QTimerEvent.filter(
    function(obj,evt)
        obj:update()
    end)

    self.eventFilter = QWheelEvent.filter(
    function(obj,evt)
        log("evt.delta = " .. evt.delta)
        if evt.delta > 0 then
            if self.scale < 16 then
                self.scale = self.scale * 1.2
                self:update()
            end
        else
            if self.scale > 0.05 then
                self.scale = self.scale / 1.2
                self:update()
            end
        end
    end)
    self:startAnimation()
end

function DataViewer:startAnimation(interval)
    local inter = interval and interval or 50
    if self.timerID then
        self:killTimer(self.timerID)
    end
    self.timerID = self:startTimer(inter)
    self.isAnimate = true
end

function DataViewer:stopAnimation()
    if self.timerID then
        self:killTimer(self.timerID)
    end
    self.timerID = nil
    self.isAnimate = false
end

function DataViewer:setDataPos(pos)
    self.dataPos = pos
    self:update()
end

function DataViewer:addData(data, color, min, max, step, width)
    local idx = #self.data+1
    self.data[idx] = {
        ["color"] = color and color or self:defaultColor(idx),
        ["data"] = data,
        ["min"] = min and min or 0,
        ["max"] = max and max or 600,
        ["step"] = step and step or 1,
        ["width"] = width and width or 1,
        ["display"] = true,
    }
    return self.data[idx]
end

function DataViewer:defaultColor(idx)
    color = self.defaultColors[idx]
    color = color and color or QColor("white")
    return color
end

function DataViewer:drawGrid(pt,w,h,pos)

    local xoffset = self.margins[1]
    local yoffset = self.margins[3]
    w = w - self.margins[1] - self.margins[2]
    h = h - self.margins[3] - self.margins[4]
    local penx = QPen(QBrush(self.gridColorX), 1, 3)
    pt:setPen(penx)
    local mid = h/2
    pt:drawLine(0+xoffset,mid+yoffset,w+xoffset,mid+yoffset)
    local y = mid
    while y - self.gridY > 0 do
        y = y - self.gridY
        pt:drawLine(0+xoffset,y+yoffset,w+xoffset,y+yoffset)
    end
    y = mid
    while y + self.gridY < h do
        y = y + self.gridY
        pt:drawLine(0+xoffset,y+yoffset,w+xoffset,y+yoffset)
    end

    local peny = QPen(QBrush(self.gridColorY), 1, 3)
    pt:setPen(peny)
    pt:drawLine(xoffset,h+yoffset,xoffset,0+yoffset)

    local x = 0
    while x + self.gridX < w do
        x = x + self.gridX
        pt:drawLine(x+xoffset,h+yoffset,x+xoffset,0+yoffset)
    end

    return xoffset
end

function DataViewer:paint_data(evt)
    local h = self.h
    local w = self.w
    pt = QPainter()
    pt:begin(self)
    pt:setBrush(QBrush(self.bankColor))
    pt:setPen(self.bankColor)
    pt:drawRect(0,0,w,h)
    local xoffset = self.margins[1]
    local yoffset = self.margins[3]
    local dataPos = 1
    w = w - self.margins[1] - self.margins[2]
    h = h - self.margins[3] - self.margins[4]

    pt:setBrush(QBrush(self.bankColor2))
    pt:setPen(self.bankColor2)
    pt:drawRect(xoffset,yoffset,w,h)

    for idata=1,#self.data do
        --log("draw data " .. idata)
        local d = self.data[idata]
        if d.display and #d.data>1 then
            local pos = 1
            local lastPos = #d.data
            local step = d.step * self.scale

            if lastPos*step > w then
                pos = math.modf( (lastPos*step - w)/step )
                lastPos = pos + w/step
            end

            if self.isAnimate == false and self.dataPos then
                pos = self.dataPos
                lastPos = pos + w/step
                if lastPos > #d.data then lastPos = #d.data end
            end

            self.currentDataPos = pos
            local px = 0
            local py = (d.data[pos]-d.min) * h / (d.max - d.min)
            py = h - py + yoffset
            pen = QPen(d.color)
            pen.width = d.width
            pt:setPen(pen)
            for i=pos+1,lastPos do
                local y = (d.data[i]-d.min) * h / (d.max - d.min)
                y = h - y + yoffset
                pt:drawLine(px+xoffset,py,px+step+xoffset,y)
                px = px+step
                py = y
            end
        end
    end
    self:drawGrid(pt,self.w,self.h,pos)
    pt:done()
end

class "DataDlg"(QDialog)
function DataDlg:__init()
    QDialog.__init(self)
    self.windowTitle = "Data Viewer"
    self.content = DataViewer()
    self.layout = QVBoxLayout {self.content}
end
