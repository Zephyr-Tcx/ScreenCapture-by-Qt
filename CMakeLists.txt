cmake_minimum_required(VERSION 3.16)
project(ScreenCaptureTool VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 设置源文件目录
set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# 寻找Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

# 设置UI文件路径（绝对路径）
set(UI_FILE ${CMAKE_SOURCE_DIR}/mainwindow.ui)

# 设置源文件
set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/mainwindow.cpp
)

# 设置头文件
set(HEADERS
    ${CMAKE_SOURCE_DIR}/mainwindow.h
)

# 设置资源文件
set(RESOURCES
    ${CMAKE_SOURCE_DIR}/resources.qrc
)

# 创建可执行文件
add_executable(ScreenCaptureTool
    ${SOURCES}
    ${HEADERS}
    ${UI_FILE}
    ${RESOURCES}
)

# 设置包含目录
target_include_directories(ScreenCaptureTool PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}
)

# 链接Qt库
target_link_libraries(ScreenCaptureTool PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
)

# Windows特定设置
if(WIN32)
    set_target_properties(ScreenCaptureTool PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE FALSE
    )
endif()