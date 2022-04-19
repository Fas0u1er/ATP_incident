cmake_minimum_required(VERSION 3.16)
project(ATP_incident)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static -static-libgcc")
set(CMAKE_CXX_STANDARD 20)
#add_subdirectory(ConsoleLibrary)
add_executable(ATP_incident
        src/board/RectangleBoard.cpp
        src/board/BoardBuilder.cpp
        src/board/Cell.cpp
        src/board/Position.cpp
        src/game_master/GameMaster.cpp
        src/GUI/SimplestGUI.cpp
        src/menu_displayer/MenuDisplayer.cpp
        src/player/PlayerFactory.cpp
        src/player/bot/Bot.cpp
        src/player/bot/GodBot.cpp
        src/player/bot/RookieBot.cpp
        src/player/bot/VeteranBot.cpp
        src/player/HumanPlayer.cpp
        src/player/Player.cpp
        src/ship/Ship.cpp
        src/ship/ShipFactory.cpp
        src/ship/SimpleShip.cpp
        src/main.cpp
        src/settings/GlobalSettings.cpp src/settings/Setting.cpp src/settings/Setting.h src/board/Board.cpp src/board/Board.h)

#target_link_libraries(ATP_incident CONSOLE_LIBRARY)
target_include_directories(ATP_incident PUBLIC ${PROJECT_SOURCE_DIR})
