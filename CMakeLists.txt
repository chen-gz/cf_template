cmake_minimum_required(VERSION 3.10)
project(cf_template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_definitions(GLOBAL_DEFINE DEBUG)
add_executable(main main.cpp)
