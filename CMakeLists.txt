cmake_minimum_required(VERSION 3.16)
project(ScreenCaptureTool VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

# 添加资源文件
qt_add_resources(qrc_files "resources.qrc")

# 添加可执行文件
add_executable(ScreenCaptureTool
    src/main.cpp
    src/mainwindow.cpp
    mainwindow.h
    ${qrc_files}
)

# 链接Qt库
target_link_libraries(ScreenCaptureTool PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
)

# 设置应用程序图标（Windows）
if(WIN32)
    set_target_properties(ScreenCaptureTool PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE FALSE
    )
endif()