cmake_minimum_required(VERSION 3.16)

project(QtMessengerClient VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Core Quick Network REQUIRED)

qt_add_executable(appQtMessengerClient
    main.cpp
)

qt_add_qml_module(appQtMessengerClient
    URI QtMessengerClient
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(appQtMessengerClient PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appQtMessengerClient
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(appQtMessengerClient
    PRIVATE Qt6::Quick)
