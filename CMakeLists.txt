cmake_minimum_required(VERSION 3.23)
project(annotationtool)

set(CMAKE_CXX_STANDARD 14)

add_executable(annotationtool main.cpp)

SET(CMAKE_PREFIX_PATH /usr/local/)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS}) # Not needed for CMake >= 2.8.11
target_link_libraries(annotationtool ${OpenCV_LIBS})


set(CMAKE_PREFIX_PATH /Users/benjaminsylvanus/Qt/6.4.1/macos/lib/cmake/)
set(Qt6_DIR /Users/benjaminsylvanus/Qt/6.4.1/macos/lib/cmake/Qt6/)

set(Qt6CoreTools_DIR /Users/benjaminsylvanus/Qt/6.4.1/macos/lib/cmake/Qt6CoreTools)
set(Qt6GuiTools_DIR /Users/benjaminsylvanus/Qt/6.4.1/macos/lib/cmake/Qt6GuiTools)
#set(Qt6CoreTools_DIR /Users/benjaminsylvanus/Qt/6.3.1/macos/lib/cmake/Qt6CoreTools)
#set(Qt6CoreTools_DIR /Users/benjaminsylvanus/Qt/6.3.1/macos/lib/cmake/Qt6CoreTools)
#Qt6CoreTools

#message(${CMAKE_PREFIX_PATH})
message(${Qt6_DIR})



#target_link_libraries(TestQt PRIVATE Qt6::Gui)



find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(annotationtool
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        )


