cmake_minimum_required(VERSION 3.20.2)

project(coolstuff)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB source_filez ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(coolstuff ${source_filez})

include(FetchContent)

FetchContent_Declare(
    awesome
    URL /home/simon/YH/awesome
)

FetchContent_MakeAvailable(awesome)

target_link_libraries(coolstuff PRIVATE awesome)
include_directories(${awesome_SOURCE_DIR}/include)
