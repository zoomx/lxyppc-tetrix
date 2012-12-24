dofile("stm32isp.lua")
logEdit:clear()
--isp = STM32ISPDlg()
--isp:exec()

--dofile("serialview.lua")
--x = SerialDlg()
--x:exec()
--dofile("bldcviewer.lua")
dofile("hidviewer.lua")
dofile("quadviewer.lua")
--mdiArea:addSubWindow( BLDCViewer()  ):show()
mdiArea:addSubWindow( HidViewer()  ):show()
--mdiArea:addSubWindow( get_quad_view() ):show()
--mdiArea:addSubWindow( STM32ISP()  ):show()
--dlg = BLDCDlg()
--dlg:exec()


--dlg = HIDDlg()
--dlg:exec()


--dock = QDockWidget("BLDC Tester"){ HidViewer() }
--mainWindow:addDockWidget(8, dock)
