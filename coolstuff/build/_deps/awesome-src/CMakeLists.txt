cmake_minimum_required(VERSION 3.10.2)

project(awesome)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB source_filez ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#SHARED can be loaded during runtime
# shared -> library.so (can be loaded in project during runtime and compile-time)
# otherwise -> .a (can only be loaded during compile-time)
add_library(awesome SHARED ${source_filez})