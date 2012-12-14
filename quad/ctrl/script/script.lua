--script.lua
--lua中的单行注释，以两个-开头，一址到该行的结尾，和C/C++中的//注释一样
--[[
这个是lua中的多行注释
以两个"-"和两个"["开头，以两个"]"结尾，和C/C++中的 /* 与 */一样
]]
-- 定义一个函数log，函数带一个参数 v
-- 这个函数简化了增加log信息的操作，如果参数是数字可以自动转化成字符
function log(v)
    logEdit:append(tostring(v))
end
-- 当[文件]->[新建]菜单被触发时调用函数
function file_new()
    -- 创建一个QLuaEdit对象，并且加入到mdiArea中
    editor = QLuaEdit()
    subWindow = mdiArea:addSubWindow( editor )
    subWindow:show()
    -- mdiArea这个变量是在X工具箱中预先定义好的，它对应的Qt类型是QMdiArea，具有QMdiArea的大部分特性
    -- 也就是说，Qt中QMdiArea这个类型所拥有的方法和属性，它基本上都有
    -- 调用它的addSubWindow函数添加一个子窗口，在Qt中它的参数是QWidget，这里用QLuaEdit作字窗口
    -- QLuaEdit是我自己写的一个针对lua脚本的编辑器，带行号和語法高亮
    -- 还可以将高亮的部分加上自定义的标签输出出来
end
--[[ 和 mdiArea一起预定义的还有mainWindow,logEdit和qApp
mainWindow 是主窗口，对应Qt中的类型是 QMainWindow
logEdit 是日志窗口中的编辑框，对应Qt中的类型是 QTextEdit
qApp  是当前应用程序的实例，对应Qt中的类型是 QApplication
lua中没有指针与引用的概念，因此在Qt中需要引用或指针的函数，都以相同的方式向用
]]
-- 当[文件]->[打开]菜单被触发时调用函数
function file_open()
    -- 获取一个打开文件名
    name = QCommonDlg.getOpenFileName("打开Lua脚本文件", "", "Lua脚本(*.lua);;全部文件(*)")
    -- 以只读方式打开文件
    file = io.open(name,"r")
    if file then
        editor = QLuaEdit()   -- 创建一个lua editor
        -- 由于QLuaEdit继承自QTextEdit，这里设置其plainText属性为文件内容
        editor.plainText = file:read("*a")
        file:close()  -- 关闭文件
        editor.windowTitle = name  -- 设置窗口名称为文件名
        mdiArea:addSubWindow(editor):show() -- 添加一个子窗口并显示
    end
end
-- 当[文件]->[另存为]菜单被触发时调用函数
function file_save_as()
    -- 取得当前激活的子窗口，并得到其lua编辑器，在Qt中通过QMdiArea的currentSubWindow
    -- 属性可以得到当前激活的子窗口，其类型为QMdiSubWindow，要得到子窗口所包含的窗口，
    -- 需要调用其widget属性
    editor = mdiArea.currentSubWindow.widget
    path = editor.windowTitle  -- 通过windowTitle得到文件名
    -- 获取一个保存文件名，并以当前的文件名作为初始文件名
    path = QCommonDlg.getSaveFileName("保存Lua脚本文件",path, "Lua脚本(*.lua);;全部文件(*)")
    -- 以写方式打开这个文件，如果文件存在则清空，不存在则创建
    file = io.open(path, "w+")
    if file then
        -- 将文字内容写入文件
        file:write(editor.plainText)
        file:close()
        -- 设置新的窗口标题为文件名
        editor.windowTitle = path
    end
end
-- 当[文件]->[保存]菜单被触发时调用函数
function file_save()
    editor = mdiArea.currentSubWindow.widget
    path = editor.windowTitle
    file = io.open(path, "w+")
    if file then
        file:write(editor.plainText)
        file:close()
    else
        -- 如果文件打开失败，则使用另存为方式保存
        file_save_as()
    end
end
-- 当[文件]->[关闭]菜单被触发时调用函数
function file_close()
    -- 关闭当前激活的窗口
    mdiArea:closeActiveSubWindow()
end
-- 当[文件]->[退出]菜单被触发时调用函数
function file_quit()
    -- 关闭主窗口，如果主窗口为程序最后一个窗口，则程序退出
    mainWindow:close()
end
-- 当[文件]->[带标签复制]菜单被触发时调用函数
function file_save_tag()
    editor = mdiArea.currentSubWindow.widget
    -- 设置名字中含有"clas"的标签，标签起始为"[color=#800080]",结束为"[/color]"
    editor:setTag("clas","[color=#800080]","[/color]")
    editor:setTag("key","[color=#0000FF]","[/color]")
    editor:setTag("quo","[color=#C80000]","[/color]")
    editor:setTag("com","[color=#008000]","[/color]")
    -- 调用QApplication类的静态函数clipboard，该函数返回应用程序的全局剪切板对象
    -- 为QClipboard类型，再调用全局剪切板对象的setText函数
    -- 将带标签的代码存入剪切板中
    QApplication.clipboard():setText(editor.tagText)
    log("加标签的源代码已复制到剪切板中!")
end
--[[
预定义的标签名字有
keyword     关键字
user keyword  用户关键字，可以通过QLuaEdit的addKeyWord函数添加
block comment 块注释
line comment 行注释
double quotation 双引号字符串
single quotation 单引号字符串
long quotation 长字符串
class 类
function 函数
]]
-- 当[编辑]->[运行]菜单被触发时调用函数
function edit_run()
    editor = mdiArea.currentSubWindow.widget
    -- 加载编辑器中的lua脚本，并执行
    assert(loadstring(editor.plainText))()
end
-- 通过menuBar函数得到mainWindow的menuBar对象
-- 以表格的方式向menuBar中添加菜单
menuBar = mainWindow:menuBar(){
    -- 添加一个[文件]菜单
    QMenu("文件(&F)"){
        -- 添加一个 [新建]菜单项
        QAction("新建(&N)"){
            -- 当此菜单项被触发时，调用file_new函数
            -- 设置此菜单项的快捷键为"Ctrl+N"
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
    --[[ 编辑菜单使用普通方式添加，效果与这里被注释掉的代码相同
    QMenu("编辑(&E)"){
        QAction("运行(&R)"){
            triggered = edit_run, QKeySequence("Ctrl+R"),
        },
    }
    ]]
}
--以普通方式添加一个编辑菜单
-- 新建一个名为[编辑]菜单
editMenu = QMenu("编辑(&E)")
-- 新建一个名为[运行]的菜单项
editRunAct = QAction("运行(&R)")
-- 当[运行]菜单项触发时，调用edit_run函数
editRunAct.triggered = edit_run
-- 设置[运行]菜单项的快捷方式为 "Ctrl+R"
editRunAct.shortcut = QKeySequence("Ctrl+R")
-- 为[编辑]菜单添加一个菜单项
editMenu:addAction(editRunAct)
-- 将[编辑]菜单加入mainWindow的menuBar中
menuBar:addMenu(editMenu)
--加载info.lua脚本并执行
dofile("info.lua")
dofile("ttt.lua")

