project(Desmond)
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

include_directories(linear-regression)
file(GLOB k-means_SRC
        "k-means/*.h"
        "k-means/*.cpp")
add_executable(Desmond ${k-means_SRC})