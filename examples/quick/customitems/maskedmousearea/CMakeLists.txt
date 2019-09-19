# Generated from maskedmousearea.pro.

cmake_minimum_required(VERSION 3.14)
project(maskedmousearea LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(INSTALL_EXAMPLEDIR "examples")

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Quick)
find_package(Qt6 COMPONENTS Qml)

add_qt_gui_executable(maskedmousearea
    main.cpp
    maskedmousearea.cpp maskedmousearea.h
)
target_link_libraries(maskedmousearea PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
)

# Resources:
set(maskedmousearea_resource_files
    "images/cloud_1.png"
    "images/cloud_2.png"
    "images/moon.png"
    "maskedmousearea.qml"
)

QT6_ADD_RESOURCES(maskedmousearea "maskedmousearea"
    PREFIX
        "/customitems/maskedmousearea"
    FILES
        ${maskedmousearea_resource_files}
)


install(TARGETS maskedmousearea
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)