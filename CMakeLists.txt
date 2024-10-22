cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

include(cmake/get_cpm.cmake)
include(cmake/dependencies.cmake)

project(
    CppSWDesignExamples 
    VERSION 0.1.0
    DESCRIPTION "Source code and libraries that implement the examples from UR CMSC322."
    LANGUAGES CXX)

add_subdirectory(examples)
add_subdirectory(visitor)