cmake_minimum_required(VERSION 3.13)
project(projetQt)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 14)
add_executable(projetQt src/main.cpp src/GameWindow1.cpp src/Player.cpp src/Player.h src/MenuWindow.cpp src/MenuWindow.h src/Wall.cpp src/Wall.h src/Level1.cpp src/Level1.h src/Ground.cpp src/Ground.h src/Flammes.cpp src/Flammes.h src/FinalFlag.cpp src/FinalFlag.h src/VictoryWindow.cpp src/VictoryWindow.h src/GameOverWindow.cpp src/GameOverWindow.h src/MenuLevel.cpp src/MenuLevel.h src/Piece.cpp src/Piece.h src/TimerWindow.cpp src/TimerWindow.h src/tuto1.cpp src/tuto1.h src/tuto2.cpp src/tuto2.h src/tuto3.cpp src/tuto3.h src/GameWindow2.cpp src/GameWindow2.h src/Level2.cpp src/Level2.h src/MovingGround.cpp src/GameWindow3.cpp src/GameWindow3.h src/Level3.cpp src/Level3.h src/JetPack.cpp src/JetPack.h)
target_link_libraries(projetQt Qt5::Widgets)