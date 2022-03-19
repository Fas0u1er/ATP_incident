#include "GameMaster.h"
#include "ConsoleLibrary/ConsoleDisplayer.h"
#include "Simplest_GUI.cpp"
#include "iostream"
int main() {
    Simplest_GUI gui;
    GameMaster game(gui);
    game.run();
    return 0;
}