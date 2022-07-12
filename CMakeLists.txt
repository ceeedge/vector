cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_EXTENSIONS OFF)

project(
    vec
    VERSION 0.0.1
    DESCRIPTION "Library for vector math utils"
    LANGUAGES CXX
)


add_subdirectory(src)