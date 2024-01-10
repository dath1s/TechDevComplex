cmake_minimum_required(VERSION 3.23)
project(TechDevComplex)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp Google_tests/ComplexTest.cpp)
add_executable(Complex_run ${SOURCE_FILES})

include_directories(Complex_lib)
add_subdirectory(Complex_lib)

target_link_libraries(Complex_run Complex_lib)

add_subdirectory(Google_tests)