cmake_minimum_required(VERSION 3.10)

PROJECT(robot_monitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

INCLUDE_DIRECTORIES(include)
 add_executable(robot_monitor
 src/main.cpp
 src/SensorRecord.cpp
 src/Parser.cpp
 src/StatsCalculator.cpp
 src/Reporter.cpp
 src/Logger.cpp
 )