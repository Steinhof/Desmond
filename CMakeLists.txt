project(Desmond)
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

include_directories(linear-regression)
file(GLOB linear-regression_SRC
        "linear-regression/*.h"
        "linear-regression/*.cpp")
add_executable(Desmond ${linear-regression_SRC})