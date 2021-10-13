cmake_minimum_required(VERSION 3.5)

project(InnClient VERSION 0.1 LANGUAGES CXX)

add_definitions(-DQT_MESSAGELOGCONTEXT)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPENSSL_DIR ${CMAKE_SOURCE_DIR}/3rdparty/openssl)
set(CEF_DIR ${CMAKE_SOURCE_DIR}/3rdparty/cef)
set(CEF_LIB_FILE ${CEF_DIR}/bin/Release/libcef.lib)
set(CEF_WRAPPER_LIB_FILE ${CEF_DIR}/bin/Release/libcef_dll_wrapper.lib)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Svg REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Network REQUIRED)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    include(FetchContent)
    FetchContent_Declare(
            googletest
            # Specify the commit you depend on and update it regularly.
            URL https://github.91chifun.workers.dev/https://github.com//google/googletest/archive/refs/tags/release-1.11.0.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    #    add_executable(${PROJECT_NAME} test.cpp library.cpp)
    #    target_link_libraries(${PROJECT_NAME} gtest_main)
endif ()

set(PROJECT_SOURCES
        main.cpp
        #        mainwindow.cpp
        #        mainwindow.h
        #        mainwindow.ui
        res.qrc page/overview.cpp page/overview.h component/button.cpp component/button.h component/popup.cpp component/popup.h component/list.cpp component/list.h model/utils.cpp model/utils.h model/define.h page/chat_room.cpp page/chat_room.h component/text_editor.cpp component/text_editor.h component/chat_content.cpp component/chat_content.h component/smooth_scroll_area.cpp component/smooth_scroll_area.h component/user.cpp component/user.h component/context_menu.cpp component/context_menu.h component/control_panel.cpp component/control_panel.h service/net_conn_service.cpp service/net_conn_service.h service/packet_parse_service.cpp service/packet_parse_service.h auth.cpp auth.h service/logger_service.cpp service/logger_service.h mainwindow.cpp mainwindow.h service/core_service.cpp service/core_service.h cef/_app.cpp cef/_app.h cef/manager.cpp cef/manager.h cef/app.cpp cef/app.h cef/handler.cpp cef/handler.h component/title_bar.cpp component/title_bar.h component/navigation.cpp component/navigation.h component/borderless_window.cpp component/borderless_window.h)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(InnClient
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
else()
    if (ANDROID)
        add_library(InnClient SHARED
                ${PROJECT_SOURCES}
                )
    elseif (CMAKE_BUILD_TYPE STREQUAL Debug)
        add_executable(InnClient
                ${PROJECT_SOURCES}
                test.h
                )
    elseif (CMAKE_BUILD_TYPE STREQUAL Release)
        add_executable(InnClient
                ${PROJECT_SOURCES}
                )
    endif ()
endif ()

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/app.manifest ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.manifest)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND mt.exe -manifest \"${CMAKE_CURRENT_SOURCE_DIR}\\${PROJECT_NAME}.manifest\" -inputresource:\"$<TARGET_FILE:${PROJECT_NAME}>\" -outputresource:\"$<TARGET_FILE:${PROJECT_NAME}>\")


if (CMAKE_BUILD_TYPE STREQUAL Debug)
    target_link_libraries(InnClient PUBLIC gtest_main)
endif ()

target_link_libraries(InnClient PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(InnClient PRIVATE Qt${QT_VERSION_MAJOR}::Svg)
target_link_libraries(InnClient PRIVATE Qt${QT_VERSION_MAJOR}::Network)
target_link_libraries(InnClient PRIVATE ${CEF_LIB_FILE} ${CEF_WRAPPER_LIB_FILE})

include_directories(${CEF_DIR})

set_target_properties(InnClient PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        )

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(InnClient)
endif ()

file(GLOB_RECURSE INN_DEPEND_DLLS
        ${OPENSSL_DIR}/libcrypto-1_1-x64.dll
        ${OPENSSL_DIR}/libssl-1_1-x64.dll
        )

file(COPY ${INN_DEPEND_DLLS} DESTINATION .)