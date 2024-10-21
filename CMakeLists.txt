cmake_minimum_required(VERSION 3.5)

include(dependencies.cmake)

project(
    CppSWDesignExamples 
    VERSION 0.1.0
    DESCRIPTION "Source code and libraries that implement the examples from the C++ Software Design Book."
    LANGUAGES CXX)

add_subdirectory(examples)
add_subdirectory(visitor)