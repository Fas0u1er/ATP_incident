#include "src/game_master/GameMaster.h"
#include "src/GUI/SimplestGUI.h"

int main() {
    SimplestGUI gui;
    GameMaster game(gui);
    game.openMenu();
    return 0;
}