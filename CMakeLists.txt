cmake_minimum_required(VERSION 3.5)

project(InnClient VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        component/auth.cpp component/auth.h component/auth.ui res.qrc page/overview.cpp page/overview.h component/button.cpp component/button.h component/popup.cpp component/popup.h component/list.cpp component/list.h model/utils.cpp model/utils.h model/define.h page/chat_room.cpp page/chat_room.h component/text_editor.cpp component/text_editor.h component/chat_content.cpp component/chat_content.h component/smooth_scroll_area.cpp component/smooth_scroll_area.h component/user.cpp component/user.h component/context_menu.cpp component/context_menu.h)


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


if (CMAKE_BUILD_TYPE STREQUAL Debug)
    target_link_libraries(InnClient PUBLIC gtest_main)
endif ()

target_link_libraries(InnClient PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(InnClient PRIVATE Qt${QT_VERSION_MAJOR}::Svg)


set_target_properties(InnClient PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        )

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(InnClient)
endif()
