--dofile("stm32isp.lua")
logEdit:clear()
--isp = STM32ISPDlg()
--isp:exec()

--dofile("serialview.lua")
--x = SerialDlg()
--x:exec()
dofile("bldcviewer.lua")
dlg = BLDCDlg()
dlg:exec()

dofile("hidviewer.lua")
--dlg = HIDDlg()
--dlg:exec()

--mdiArea:addSubWindow( HidViewer()  ):show()
--dock = QDockWidget("BLDC Tester"){ HidViewer() }
--mainWindow:addDockWidget(8, dock)