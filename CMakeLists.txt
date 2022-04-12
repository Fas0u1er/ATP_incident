cmake_minimum_required(VERSION 3.21)
project(ATP_incident)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static -static-libgcc")
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(ConsoleLibrary)
add_executable(ATP_incident
        src/main.cpp
        src/board/Board.cpp
        src/board/BoardBuilder.cpp
        src/board/Cell.cpp
        src/board/Position.cpp
        src/event_loop/GameMaster.cpp
        src/event_loop/Menu.cpp
        src/event_loop/BattleMaster.cpp
        src/GUI/SimplestGUI.cpp
        src/player/ConsolePlayer.cpp
        src/ship/Ship.cpp
        src/ship/ShipFactory.cpp
        )

target_link_libraries(ATP_incident CONSOLE_LIBRARY)
target_include_directories(ATP_incident PUBLIC ${PROJECT_SOURCE_DIR})
