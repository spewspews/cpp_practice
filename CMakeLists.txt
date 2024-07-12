cmake_minimum_required(VERSION 3.29.6)
project(CppPractice CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER clang++)

add_compile_options("$<$<CONFIG:DEBUG>:-Wall;-Wextra;-fno-omit-frame-pointer;-fsanitize=address;-fsanitize=undefined;-fno-optimize-sibling-calls;-O1>")

add_link_options("$<$<CONFIG:DEBUG>:-fno-omit-frame-pointer;-fsanitize=address;-fsanitize=undefined;-g>")

add_subdirectory(lib)
include_directories(lib)
add_subdirectory(test)
