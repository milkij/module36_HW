#module36_HW
cmake_minimum_required(VERSION 3.23)

project(module36_HW VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/alexander/QT/6.6.1/macos")
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(MY_IMG_DIR ${CMAKE_SOURCE_DIR}/img)

find_package(Qt6 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        )
qt_standard_project_setup()

qt_add_executable(module36_HW
        src/main.cpp
        include/myWidget.cpp include/myWidget.h)

target_link_libraries(module36_HW PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt::Widgets)


target_include_directories(module36_HW PUBLIC ${MY_INCLUDE_DIR})
target_sources(module36_HW PUBLIC ${MY_IMG_DIR})
