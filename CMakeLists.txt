cmake_minimum_required(VERSION 3.16)
project(ATP_incident)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static -static-libgcc")
set(CMAKE_CXX_STANDARD 20)
#add_subdirectory(ConsoleLibrary)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)
add_executable(
        ATP_incident
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
        src/settings/GlobalSettings.cpp
        src/settings/Setting.cpp
        src/board/Board.cpp
        src/GUI/ExternalGUI/ExternalGUI.cpp
        src/GUI/ExternalGUI/ButtonBase.cpp
        src/GUI/ExternalGUI/TextButton.cpp
        src/GUI/ExternalGUI/InputField.cpp
        src/GUI/ExternalGUI/DisplayableBoard.cpp src/GUI/ExternalGUI/DisplayableBoard.h)


include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
IF (NOT UNIX OR APPLE) # == Windows or Apple
    FetchContent_Declare(
            SFML
            GIT_REPOSITORY https://github.com/SFML/SFML.git
            GIT_TAG 2.5.1
    )
    FetchContent_MakeAvailable(SFML)
    target_link_libraries(
            ATP_incident
            sfml-graphics
            sfml-window
            sfml-system
    )
else ()
    find_package(SFML COMPONENTS graphics window system REQUIRED)
endif ()
target_link_libraries(
        ATP_incident
        sfml-graphics
        sfml-window
        sfml-system
)
target_include_directories(ATP_incident PUBLIC ${PROJECT_SOURCE_DIR})
