cmake_minimum_required(VERSION 3.16)
project(ScreenCaptureTool VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 寻找Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

# 设置UI文件
set(UI_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.ui
)

# 设置源文件
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
)

# 设置头文件
set(HEADERS
    mainwindow.h
)

# 设置资源文件
qt_add_resources(RESOURCES
    resources.qrc
)

# 创建可执行文件
add_executable(ScreenCaptureTool
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${RESOURCES}
)

# 链接Qt库
target_link_libraries(ScreenCaptureTool PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Gui
)

# 设置包含目录
target_include_directories(ScreenCaptureTool PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

# Windows特定设置
if(WIN32)
    # 设置应用程序图标
    set_target_properties(ScreenCaptureTool PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE FALSE
    )
    
    # 复制Qt DLL到构建目录（可选）
    add_custom_command(TARGET ScreenCaptureTool POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "$<TARGET_FILE:Qt6::Core>"
        "$<TARGET_FILE:Qt6::Widgets>"
        "$<TARGET_FILE:Qt6::Gui>"
        $<TARGET_FILE_DIR:ScreenCaptureTool>
    )
endif()