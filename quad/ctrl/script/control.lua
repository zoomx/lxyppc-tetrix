-- control.lua
-- implement some useful controls

-- implement a slider with value display ---------
class "QValueSlider"(QFrame)
function QValueSlider:__init(v)
    QFrame.__init(self)
    if v == 1 or v == 2 then
        self.slider = QSlider(v)
    else
        self.slider = QProgressBar() {textVisible = false}
    end
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
    if self.valueChanged then
        if type(self.valueChanged) == "table" then
            self.valueChanged[2](self.valueChanged[1])
        else
            self.valueChanged()
        end
    end
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
    if self.colorChanged then
        if type(self.colorChanged) == "table" then
            self.colorChanged[2](self.colorChanged[1])
        else
            self.colorChanged()
        end
    end
end
-- implement color selection button end -------
