--dofile("stm32isp.lua")
logEdit:clear()
--isp = STM32ISPDlg()
--isp:exec()

--dofile("serialview.lua")
--x = SerialDlg()
--x:exec()
dofile("bldcviewer.lua")
dofile("hidviewer.lua")
mdiArea:addSubWindow( BLDCViewer()  ):show()
mdiArea:addSubWindow( HidViewer()  ):show()
--dlg = BLDCDlg()
--dlg:exec()


--dlg = HIDDlg()
--dlg:exec()


--dock = QDockWidget("BLDC Tester"){ HidViewer() }
--mainWindow:addDockWidget(8, dock)