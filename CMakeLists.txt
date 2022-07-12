cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_EXTENSIONS OFF)

project(
    vec
    VERSION 0.0.1
    DESCRIPTION "Library for vector math utils"
    LANGUAGES CXX
)


# vector lib (header only)
add_library(vec INTERFACE)
target_include_directories(vec SYSTEM INTERFACE
    ${CMAKE_SOURCE_DIR}/include/vec
)


add_subdirectory(src)

option(ENABLE_TESTING "Enable Testing" ON)
if(ENABLE_TESTING)
    message("Testing enabled.")
    add_subdirectory(test)
endif()