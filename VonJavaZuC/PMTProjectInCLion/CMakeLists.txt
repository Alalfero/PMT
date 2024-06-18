cmake_minimum_required(VERSION 3.28)
project(PMT C)

set(CMAKE_C_STANDARD 11)

add_executable(JavaToCTest javatoc_test.c JavaToC.c CUnit.c)
target_link_libraries(JavaToCTest m)