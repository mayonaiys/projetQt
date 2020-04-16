cmake_minimum_required(VERSION 3.13)
project(projetQt)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 14)
add_executable(projetQt src/main.cpp src/GameWindow.cpp src/GameScene.cpp src/Player.cpp src/Player.h src/MenuWindow.cpp src/MenuWindow.h src/Sol.cpp src/Sol.h)
target_link_libraries(projetQt Qt5::Widgets)