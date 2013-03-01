-- info.lua   作者: lxyppc
-- 用lua代码实现的XToolbox的簡易帮助文档
-- 定义一个表，将动态帮助相关的变量保存进来，作用相当于命名空间
dynamicHelp = {}
-- 得到排序后的content中的值
function dynamicHelp.pick_value(content)
    table.sort(content)
    return content
end
-- 得到排序后的content中的Key
function dynamicHelp.pick_key(content)
    local res = {}
    for k,v in pairs(content) do
        if k:sub(1,2) ~= "__" then
            res[#res + 1] = k
        end
    end
    return dynamicHelp.pick_value(res)
end
-- 得到所有注册的类名
function dynamicHelp.register_classes()
    local classes = class_names() -- class_names 是luabind注册的函数，用于得到所有的类名
    classes[#classes + 1] = "gl"    
    table.sort(classes)    
    return classes
end
dynamicHelp.classFilter = QLineEdit()  -- 用classFilter中的字符来过滤类名
dynamicHelp.nameFilter = QLineEdit()  -- 用nameFilter中的字符来过滤类名
dynamicHelp.tab = QTabWidget()  -- 创建一个TabWidget，用来存放类的各种成员
dynamicHelp.baseClass = QLabel("Base: ") -- 用来显示基类的标签
-- 用来调用网页搜索关键词的标签
dynamicHelp.online_help = QLabel("Search Help: "){ openExternalLinks = true }
dynamicHelp.reg_classes = dynamicHelp.register_classes() -- 保存所有已注册的类
-- 创建一个类名列表，并用reg_classes初始化
dynamicHelp.classList = QListWidget{ dynamicHelp.reg_classes }
dynamicHelp.currentClassName = ""
-- TabWidget中各项内容的参数表
dynamicHelp.member_lists = {
    -- 都是列表类型          显示在tab上的名字   class_info中对应的项        用于排序的函数
  { list = QListWidget(), name = "methods", field = "methods",        pick = dynamicHelp.pick_key},
  { list = QListWidget(), name = "attributes",    field = "attributes",     pick = dynamicHelp.pick_value},
  { list = QListWidget(), name = "static", field = "static_methods", pick = dynamicHelp.pick_key},
  { list = QListWidget(), name = "constants",    field = "constants",      pick = dynamicHelp.pick_key},
}
-- 更新在线帮助内容
function dynamicHelp.upadte_online(text)
    local site = "doc.qt.nokia.com"
    if dynamicHelp.currentClassName == "gl" then
        if dynamicHelp.tab.currentIndex == 2 then
            text = "gl" .. text
        end
        site = "opengl.org"
    end
    dynamicHelp.online_help.text = "Search Help:  " ..
        [[<a href="http://www.google.com.hk/search?q=]] 
        .. text .. [[%20site:]] .. site .. [[&btnI=i">]]
        .. text .. "</a>"
end
-- 初始化所有的列表，并加入到tab中
for k,v in pairs(dynamicHelp.member_lists) do
    dynamicHelp.tab:addTab(v.list,v.name)
    v.list.currentTextChanged = dynamicHelp.upadte_online
end
-- 动态帮助左边部分，上面一个过滤器，下面一个类名列表
dynamicHelp.frm1 = QFrame{
    layout = QVBoxLayout{ -- 垂直布局
        QHBoxLayout{
            QLabel("Class Name Filter:"),
            dynamicHelp.classFilter,
        },
        dynamicHelp.classList,
    }
}
-- 右边部分，上面是基类名，中间是成员列表，下面是在线帮助
dynamicHelp.frm2 = QFrame{
    layout = QVBoxLayout{  -- 垂直布局
        dynamicHelp.baseClass,
        QHBoxLayout{
            QLabel("Name Filter:"),
            dynamicHelp.nameFilter,
        },
        dynamicHelp.tab,
        dynamicHelp.online_help,
    }
}
-- 当基类名被点中时，跳转到已注册的基类处
dynamicHelp.baseClass.linkActivated = function(link)
    dynamicHelp.classList:clear()
    dynamicHelp.classList:addItems(dynamicHelp.reg_classes)
    local res = dynamicHelp.classList:findItems(link,0) --查找满足要求的项
    if res and #res > 0 then -- 如果有，则重新设置列表的当前行
        dynamicHelp.classList.currentRow = res[1].row
    end
end
-- 当类名列表中的当前项改变时，更新成员列表中的内容
dynamicHelp.classList.currentTextChanged = function(text)
    dynamicHelp.currentClassName = text
    local info = class_info(_G[text]) --得到选中的类所对应类信息
    local bases = dynamicHelp.pick_value(info.bases) -- 提取基类信息
    local r = "Base: "
    for k,v in pairs(bases) do -- 为基类名创建超链接
        local ref = [[<a href="]] .. v ..[[">]] .. v .. "</a>"
        r = r .. ref .. ", "
    end
    if text == "gl" then
        info = {}
        info.static_methods = {}
        info.constants = {}
        info.attributes = {}
        info.methods = {}
        for k,v in pairs(_G[text]) do
            if type(v) == "function" then
                info.static_methods[k] = v
            elseif type(v) == "number" then
                info.constants[k] = v
            end
        end
    end
    --由于baseClass的openExternalLinks为false，当点击基类超链接时会触发linkActivated信号
    dynamicHelp.baseClass.text = r
    for k,v in pairs(dynamicHelp.member_lists) do -- 遍历参数表
        v.list:clear() -- 将相应的列表清空
        local items = v.pick(info[v.field]) -- 调用根据info中相应的项得到排序后的列表
        -- 在Tab中各项的名字后面加上成员的数量
        dynamicHelp.tab:setTabText(k-1, v.name .. "(" .. #items .. ")")
        v.items = items
        v.list:addItems(items)
    end
end
-- 当过滤器中的文本改变时，只显示匹配成功的类名 
dynamicHelp.classFilter.textChanged = function(str)
    local r = {}
    for k,v in pairs(dynamicHelp.reg_classes) do
        if string.match(v:upper(),str:upper()) then --匹配忽略大小写
            r[#r+1] = v
        end
    end
    dynamicHelp.classList:clear()
    dynamicHelp.classList:addItems(r) -- 将匹配成功的类名加入列表
end
-- 当过滤器中的文本改变时，只显示匹配成功的成员名
dynamicHelp.nameFilter.textChanged = function(str)
    -- 根据当前tab的索引，得到list中的元素并匹配
    local list = dynamicHelp.member_lists[dynamicHelp.tab.currentIndex+1]
    local r = {}
    for k,v in pairs(list.items) do
        if string.match(v:upper(),str:upper()) then --匹配忽略大小写
            r[#r+1] = v
        end
    end
    list.list:clear()
    list.list:addItems(r) -- 将匹配成功的类名加入列表
end
-- 以splitter作为动态帮助的主界面
dynamicHelp.splitter = QSplitter{
    childrenCollapsible = false, --禁止完全隐藏Splitter中的内容
    dynamicHelp.frm1, --左/上部分
    dynamicHelp.frm2, --右/下部分
}
-- 将splitter加入到一个DockWidget中
dynamicHelp.dock = QDockWidget("Dynamic Help"){dynamicHelp.splitter}
-- 将dock加入main window中，并且放在底部。Qt::BottomDockWidgetArea = 8
mainWindow:addDockWidget(8, dynamicHelp.dock)
-- 当dock区域改变时，调整splitter的布局
dynamicHelp.dock.dockLocationChanged = function(area)
    -- area 1,2 表示dock在左右，4,8表示dock在上下
    -- orientation 1表示水平布局，2表示垂直布局
    dynamicHelp.splitter.orientation = area>2 and 1 or 2 -- area > 2表示dock在上或在下
end
-- 在menuBar中添加一个名为Help的菜单，并在上面加上dock的开关
mainWindow.menuBar{
    QMenu("&Help"){
        dynamicHelp.dock.toggleViewAction
    }
}
--mdiArea:addSubWindow(splitter):show()












