function log(v)
    logEdit:append(tostring(v))
end

function file_new()
    mdiArea:addSubWindow( QLuaEdit() ):show()
end

function file_open()
    name = QCommonDlg.getOpenFileName("打开Lua脚本文件", "", "Lua脚本(*.lua);;全部文件(*)")
    file = io.open(name,"r")
    if file then
        editor = QLuaEdit()
        editor.plainText = file:read("*a")
        file:close()
        editor.windowTitle = name
        mdiArea:addSubWindow(editor):show()
    end
end

function file_save_as()
    editor = mdiArea.currentSubWindow.widget
    path = editor.windowTitle
    path = QCommonDlg.getSaveFileName("保存Lua脚本文件",path, "Lua脚本(*.lua);;全部文件(*)")
    file = io.open(path, "w+")
    if file then
        file:write(editor.plainText)
        file:close()
        editor.windowTitle = path
    end
end

function file_save()
    editor = mdiArea.currentSubWindow.widget
    path = editor.windowTitle
    file = io.open(path, "w+")
    if file then
        file:write(editor.plainText)
        file:close()
    else
        file_save_as()
    end
end

function file_close()
    mdiArea:closeActiveSubWindow()
end

function file_quit()
    mainWindow:close()
end

function file_save_tag()
    editor = mdiArea.currentSubWindow.widget
    editor:setTag("clas","[color=#800080]","[/color]")
    editor:setTag("key","[color=#0000FF]","[/color]")
    editor:setTag("quo","[color=#C80000]","[/color]")
    editor:setTag("com","[color=#008000]","[/color]")
    QApplication.clipboard():setText(editor.tagText)
    log("加标签的源代码复制到剪切板中!")
end

function edit_run()
    editor = mdiArea.currentSubWindow.widget
    assert(loadstring(editor.plainText))()
end

mainWindow:menuBar(){
    QMenu("文件(&F)"){
        QAction("新建(&N)"){
            triggered = file_new, QKeySequence("Ctrl+N"),
        },
        QAction("打开(&O)"){
            triggered = file_open, QKeySequence("Ctrl+O"),
        },
        QAction("保存(&S)"){
            triggered = file_save, QKeySequence("Ctrl+S"),
        },
        QAction("另存为(&a)"){
            triggered = file_save_as, QKeySequence("Ctrl+Shift+A"),
        },
        QAction("带标签复制(&t)"){
            triggered = file_save_tag, QKeySequence("Ctrl+T"),
        },
        QAction("关闭(&C)"){
            triggered = file_close, QKeySequence("Ctrl+Shift+C"),
        },
        QAction(""){
            separator = true
        },
        QAction("退出(&Q)"){
            triggered = file_quit, QKeySequence("Ctrl+Shift+Q"),
        }
    },
    QMenu("编辑(&E)"){
        QAction("运行(&R)"){
            triggered = edit_run, QKeySequence("Ctrl+R"),
        },
    }
}

dofile("serialview.lua")
