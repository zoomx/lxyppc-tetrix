-- control.lua
-- implement some useful controls

-- implement a slider with value display ---------
class "QValueSlider"(QFrame)
function QValueSlider:__init(v)
    QFrame.__init(self)
    self.slider = QSlider(v)
    self.label = QLabel()-- { minw=40,maxw=40}
    self.offset = 0
    self.ratio = 1
    self.unit = ""
    self.slider.valueChanged = {self, self.valueSliderChanged}
    self.layout = QHBoxLayout{
        self.slider, self.label
    }
    self.maxh = 20
    self:valueSliderChanged()
    self.valueChanged = nil
end

function QValueSlider:__call(v)
    if v.max then self.slider.max = v.max end
    if v.min then self.slider.min = v.min end
    if v.minw then self.minw = v.minw end
    if v.maxw then self.maxw = v.maxw end
    if v.offset then self.offset = v.offset end
    if v.ratio then self.ratio = v.ratio end
    if v.unit then self.unit = v.unit end
    if v.valueChanged then self.valueChanged = v.valueChanged end
    self:valueSliderChanged()
    return self
end

function QValueSlider:valueSliderChanged()
    self.label.text = (self.slider.value + self.offset)*self.ratio .. self.unit
    local t = self.valueChanged and self.valueChanged()
end
-- implement a slider with value display end ----------

-- implement color selection button -----------
class "QColorButton" (QToolButton)
function QColorButton:__init(color)
    QToolButton.__init(self)
    self.color = QColor(color) or QColor("gray")
    self.styleSheet = "background:"..self.color.name
    self.clicked = {self,self.changeColor}
end

function QColorButton:changeColor()
    local color = QCommonDlg.getColor(self.color)
    if color.isValid then
        self.color = color
    end
    self.styleSheet = "background:"..self.color.name
    local t = self.colorChanged and self.colorChanged()
end
-- implement color selection button end -------
