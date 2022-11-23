cmake_minimum_required(VERSION 3.23)
project(annotationtool)

set(CMAKE_CXX_STANDARD 14)

add_executable(annotationtool main.cpp)

SET(CMAKE_PREFIX_PATH /usr/local/)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS}) # Not needed for CMake >= 2.8.11
target_link_libraries(annotationtool ${OpenCV_LIBS})
