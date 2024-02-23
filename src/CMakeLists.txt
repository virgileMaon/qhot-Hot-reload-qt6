set(CMAKE_AUTOMOC ON)

set(SRCS main.cpp providessomething.cpp urlinterceptor.cpp
         commandline/commandlineparser.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/commandline)

qt_add_resources(RESOURCES ../resources.qrc)

add_executable(qhot ${SRCS} ${RESOURCES})
target_link_libraries(qhot Qt6::Core Qt6::Qml Qt6::Widgets Qt6::Quick
                      Qt6::QuickControls2)
