# Qt项目配置文件
QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 启用C++11标准
CONFIG += c++11

# 应用程序信息
TARGET = ScreenCaptureTool
TEMPLATE = app

# 版本信息
VERSION = 1.0.0
QMAKE_TARGET_COMPANY = "Your Company"
QMAKE_TARGET_DESCRIPTION = "定时屏幕截图工具"
QMAKE_TARGET_COPYRIGHT = "Copyright © 2023 Your Company. All rights reserved."

# 源文件和头文件
SOURCES += \
    src/main.cpp \
    src/screencapturer.cpp

HEADERS += \
    src/screencapturer.h

FORMS += \
    ui/screencapturer.ui

# 资源文件
RESOURCES += \
    resources/icons.qrc

# 编译器选项
QMAKE_CXXFLAGS += -Wall -Wextra -O2
CONFIG += debug_and_release

# Windows平台特定设置
win32 {
    # 设置应用程序图标
    RC_ICONS = resources/icons/app.ico
    
    # 设置应用程序清单
    QMAKE_LFLAGS += /MANIFEST:NO
    
    # 设置控制台（调试）或窗口（发布）
    CONFIG(debug, debug|release) {
        # 调试版显示控制台
        CONFIG += console
    } else {
        # 发布版隐藏控制台
        QMAKE_LFLAGS += /SUBSYSTEM:WINDOWS,5.01
    }
    
    # 禁用DEP
    QMAKE_LFLAGS += /NXCOMPAT:NO
}

# Linux平台特定设置
linux {
    # 桌面文件
    desktop.path = $$PREFIX/share/applications
    desktop.files = ScreenCaptureTool.desktop
    INSTALLS += desktop
    
    # 图标
    icon16.path = $$PREFIX/share/icons/hicolor/16x16/apps
    icon16.files = resources/icons/16x16/apps/ScreenCaptureTool.png
    icon32.path = $$PREFIX/share/icons/hicolor/32x32/apps
    icon32.files = resources/icons/32x32/apps/ScreenCaptureTool.png
    icon48.path = $$PREFIX/share/icons/hicolor/48x48/apps
    icon48.files = resources/icons/48x48/apps/ScreenCaptureTool.png
    icon64.path = $$PREFIX/share/icons/hicolor/64x64/apps
    icon64.files = resources/icons/64x64/apps/ScreenCaptureTool.png
    icon128.path = $$PREFIX/share/icons/hicolor/128x128/apps
    icon128.files = resources/icons/128x128/apps/ScreenCaptureTool.png
    icon256.path = $$PREFIX/share/icons/hicolor/256x256/apps
    icon256.files = resources/icons/256x256/apps/ScreenCaptureTool.png
    icon512.path = $$PREFIX/share/icons/hicolor/512x512/apps
    icon512.files = resources/icons/512x512/apps/ScreenCaptureTool.png
    INSTALLS += icon16 icon32 icon48 icon64 icon128 icon256 icon512
}

# macOS平台特定设置
macx {
    # 应用程序包设置
    QMAKE_INFO_PLIST = Info.plist
    
    # 图标
    ICON = resources/icons/app.icns
    
    # 应用程序包目标
    TARGET = ScreenCaptureTool
    
    # 禁用默认的macOS部署
    CONFIG -= app_bundle
}

# 构建目录
DESTDIR = build
OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui

# 包含路径
INCLUDEPATH += src

# 发布版本配置
CONFIG(release, debug|release) {
    # 发布版本不包含调试符号
    QMAKE_CXXFLAGS_RELEASE -= -O2
    QMAKE_CXXFLAGS_RELEASE += -O3
    
    # 剥离符号
    QMAKE_LFLAGS += -s
    
    # 定义发布宏
    DEFINES += QT_NO_DEBUG_OUTPUT
}

# 调试版本配置
CONFIG(debug, debug|release) {
    # 调试版本包含调试符号
    QMAKE_CXXFLAGS += -g
    
    # 定义调试宏
    DEFINES += QT_DEBUG
}

# 预编译头文件（可选）
# CONFIG += precompile_header
# PRECOMPILED_HEADER = src/stdafx.h

# 翻译文件
TRANSLATIONS += \
    translations/screencapture_zh_CN.ts \
    translations/screencapture_en_US.ts

# 构建后操作
# 将可执行文件复制到项目根目录
# QMAKE_POST_LINK += $$quote(cmd /c copy /Y \"$$DESTDIR\\$${TARGET}.exe\" .\\$${TARGET}.exe)