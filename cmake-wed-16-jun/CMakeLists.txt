cmake_minimum_required(VERSION 3.10.2)

project(PersonApp)

include_directories(include)

file(GLOB srcs src/*.cpp)

#add_compile_options(-I./include)

add_executable(PersonApp ${srcs})

target_sources(
	PersonApp PRIVATE
    ${srcs}
)
