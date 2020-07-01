cmake_minimum_required(VERSION 3.13)
project(untitled13)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp Player.cpp Player.h AiPlayer.cpp AiPlayer.h Utility.cpp Utility.h
        Board.cpp Board.h ShipPlacement.cpp ShipPlacement.h BattleShip.cpp BattleShip.h
        GameAttributes.cpp GameAttributes.h HumanPlayer.cpp HumanPlayer.h RandomAI.cpp RandomAI.h
        HuntAndDestroyAI.cpp HuntAndDestroyAI.h CheatingAI.cpp CheatingAI.h
        Move.h Move.cpp)