-- http://code.google.com/p/qp-gcc/downloads/detail?name=mingw-static-4.4.5-all.7z
ld = QUiLoader()
w = ld:load("test.ui")
dlg = QDialog()


function parse_objects(w)
    for k,btn in pairs(QPushButton.findChildren(w)) do
       w[btn.objectName] = btn
    end
end
parse_objects(w)

ls = QListWidget.findChild(w)
function btn_clicked(btn)
  ls:addItem(btn.text .. " -> clicked")
end

--for k,btn in pairs(QPushButton.findChildren(w)) do
--   btn.clicked = {btn,btn_clicked}
--end

w["btn1"].clicked = {w["btn1"],btn_clicked}
w["btn2"].clicked = {w["btn2"],btn_clicked}
w["btn3"].clicked = {w["btn3"],btn_clicked}


dlg.layout = QVBoxLayout{
   w,
}

dlg:exec()