project(qhot)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Core)

find_package(
  Qt6
  REQUIRED
  Core
  Qml
  Quick
  QuickControls2
  Widgets)

add_subdirectory(src)
