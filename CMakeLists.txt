cmake_minimum_required(VERSION 3.22)
project(Razor)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 17)

add_executable(razor 
    src/Razor.cpp
    src/Engine/Math/Vector.hpp
    src/Engine/Math/Matrix.hpp
)