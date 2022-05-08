#include "src/game_master/GameMaster.h"
#include "src/GUI/SimplestGUI.h"
#include "src/GUI/ExternalGUI/ExternalGUI.h"

int main() {
    ExternalGUI gui;
    GameMaster game(gui);
    game.openMenu();
    return 0;
}