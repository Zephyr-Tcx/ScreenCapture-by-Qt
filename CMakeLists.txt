# CMake最低版本要求
cmake_minimum_required(VERSION 3.16)

# 项目设置
project(ScreenCaptureTool
    VERSION 1.0.0
    DESCRIPTION "定时屏幕截图工具"
    LANGUAGES CXX
)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置自动处理Qt的特殊文件
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 查找Qt库
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# 设置源文件
set(SOURCES
    src/main.cpp
    src/screencapturer.cpp
)

set(HEADERS
    src/screencapturer.h
)

set(FORMS
    ui/screencapturer.ui
)

set(RESOURCES
    resources/icons.qrc
)

# 创建可执行文件
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
    ${RESOURCES}
)

# 链接Qt库
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Widgets
)

# 设置目标属性
set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist"
)

# Windows特定设置
if(WIN32)
    # 设置Windows子系统（避免弹出控制台窗口）
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "/SUBSYSTEM:WINDOWS"
    )
    
    # 添加版本信息
    set(VERSION_RESOURCE "${CMAKE_CURRENT_SOURCE_DIR}/version.rc")
    if(EXISTS ${VERSION_RESOURCE})
        target_sources(${PROJECT_NAME} PRIVATE ${VERSION_RESOURCE})
    endif()
endif()

# 设置包含目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# 安装配置
if(UNIX AND NOT APPLE)
    # Linux安装配置
    install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
    )
    
    # 桌面文件
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/ScreenCaptureTool.desktop
        DESTINATION share/applications
    )
    
    # 图标
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/16x16/apps/ScreenCaptureTool.png
        DESTINATION share/icons/hicolor/16x16/apps
        RENAME ${PROJECT_NAME}.png
    )
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/32x32/apps/ScreenCaptureTool.png
        DESTINATION share/icons/hicolor/32x32/apps
        RENAME ${PROJECT_NAME}.png
    )
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/48x48/apps/ScreenCaptureTool.png
        DESTINATION share/icons/hicolor/48x48/apps
        RENAME ${PROJECT_NAME}.png
    )
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/64x64/apps/ScreenCaptureTool.png
        DESTINATION share/icons/hicolor/64x64/apps
        RENAME ${PROJECT_NAME}.png
    )
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/128x128/apps/ScreenCaptureTool.png
        DESTINATION share/icons/hicolor/128x128/apps
        RENAME ${PROJECT_NAME}.png
    )
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/256x256/apps/ScreenCaptureTool.png
        DESTINATION share/icons/hicolor/256x256/apps
        RENAME ${PROJECT_NAME}.png
    )
endif()

# macOS特定配置
if(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE_INFO_STRING "${PROJECT_DESCRIPTION}"
        MACOSX_BUNDLE_ICON_FILE "app.icns"
        MACOSX_BUNDLE_BUNDLE_NAME "${PROJECT_NAME}"
        MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
        MACOSX_BUNDLE_COPYRIGHT "${PROJECT_COPYRIGHT}"
    )
    
    # 复制资源到应用包
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/resources"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/../Resources"
    )
endif()

# 可选的代码分析
option(ENABLE_CLANG_TIDY "Enable clang-tidy analysis" OFF)
if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
    if(CLANG_TIDY_EXE)
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()
endif()

# 可选的测试
option(BUILD_TESTS "Build tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    
    # 添加测试子目录
    add_subdirectory(tests)
endif()

# 可选的文档生成
option(BUILD_DOCS "Build documentation" OFF)
if(BUILD_DOCS)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
        
        configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
        
        add_custom_target(doc
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
        )
    endif()
endif()

# 打包目标（可选）
if(WIN32)
    # 创建Windows安装包
    include(InstallRequiredSystemLibraries)
    
    set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
    set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
    set(CPACK_PACKAGE_VENDOR "Your Company")
    set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_DESCRIPTION}")
    set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
    set(CPACK_PACKAGE_EXECUTABLES "${PROJECT_NAME}" "Screen Capture Tool")
    
    include(CPack)
endif()

# 输出构建信息
message(STATUS "Building ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "Source directory: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "Build directory: ${CMAKE_CURRENT_BINARY_DIR}")