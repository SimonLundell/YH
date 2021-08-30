cmake_minimum_required(VERSION 3.10.2) # cmake --version

project(pong)


include_directories(include)


add_executable(pong src/main.cpp)
# tell the compiler where our files are.
# You don't need to do this if you have these files in
# your path
# include_directories(libraries/include)
# target_link_directories(pong PRIVATE libraries/lib)
# arget_link_directories(pong PRIVATE libraries/bin)

# tell the compiler that we want to link and use the SDL2
# library.
target_link_libraries(pong PRIVATE SDL2)

target_sources(
  pong PRIVATE
  src/Ball.cpp
  src/Enemy.cpp
  src/Player.cpp
  src/Game.cpp
  src/GameObject.cpp
  src/Pad.cpp
  src/Draw.cpp
  src/Math.cpp
  src/Keyboard.cpp
  src/Collision.cpp
  src/main.cpp
)