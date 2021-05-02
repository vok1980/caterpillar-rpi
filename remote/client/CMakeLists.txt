cmake_minimum_required(VERSION 3.14)
project(Client CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Network)
find_package(Qt6 COMPONENTS Quick)


qt_add_executable(client
    main.cpp
    movecontroller.h
    movecontroller.cpp
)

target_link_libraries(client
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Network
        Qt::Quick
        messages
)

set(qml_resource_files
    "main.qml"
    "SpeedRegulator.qml"
)

qt6_add_resources(client "qml"
    PREFIX
        "/"
    FILES
        ${qml_resource_files}
)

