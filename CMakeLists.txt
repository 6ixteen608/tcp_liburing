cmake_minimum_required(VERSION 3.16)
project(linux_io_examples)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)
include_directories(lib)

add_executable(echo.out echo.cpp)
target_link_libraries(echo.out server)
