cmake_minimum_required(VERSION 3.10.2) # cmake --version

project(pong)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/plugins DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(include)

add_compile_options(-g -Wall)

set(libsources
  src/Ball.cpp
  src/Enemy.cpp
  src/Font.cpp
  src/Player.cpp
  src/Game.cpp
  src/GameObject.cpp
  src/PluginManager.cpp
  src/Pad.cpp
  src/Draw.cpp
  src/Math.cpp
  src/Keyboard.cpp
  src/Collision.cpp
  src/main.cpp
)
add_executable(pong src/main.cpp)
add_library(ponginterface SHARED ${libsources})

# tell the compiler where our files are.
# You don't need to do this if you have these files in
# your path
# include_directories(libraries/include)
# target_link_directories(pong PRIVATE libraries/lib)
# arget_link_directories(pong PRIVATE libraries/bin)

# tell the compiler that we want to link and use the SDL2
# library.
target_link_libraries(pong PRIVATE SDL2 SDL2_ttf)

target_link_libraries(pong PRIVATE dl)

if(WIN32)
  target_link_libraries(pong PRIVATE Kernel32)
ENDIF()

target_sources(
  pong PRIVATE
  src/Ball.cpp
  src/Enemy.cpp
  src/Font.cpp
  src/Player.cpp
  src/Game.cpp
  src/GameObject.cpp
  src/PluginManager.cpp
  src/Pad.cpp
  src/Draw.cpp
  src/Math.cpp
  src/Keyboard.cpp
  src/Collision.cpp
  src/main.cpp
)