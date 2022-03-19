cmake_minimum_required(VERSION 3.21)
project(ATP_incident)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static -static-libgcc")
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(ConsoleLibrary)
add_executable(ATP_incident
        main.cpp
        GameMaster.cpp
        ConsolePlayer.cpp
        "Ship and Cell.cpp"
        Board.cpp
        Simplest_GUI.cpp
        Position.cpp
        )

target_link_libraries(ATP_incident CONSOLE_LIBRARY)
target_include_directories(ATP_incident PUBLIC ${PROJECT_SOURCE_DIR})
