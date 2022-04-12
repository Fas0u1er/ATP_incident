#include "src/event_loop/GameMaster.h"
#include "ConsoleLibrary/ConsoleDisplayer.h"
#include "src/GUI/SimplestGUI.h"

int main() {
    SimplestGUI gui;
    GameMaster game(gui);
    game.run();
    return 0;
}