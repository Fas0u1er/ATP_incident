#include "src/game_master/GameMaster.h"

#if USE_GUI
#include "src/GUI/ExternalGUI/ExternalGUI.h"
using GUI_TYPE = ExternalGUI;
#else
#include "src/GUI/SimplestGUI.h"
using GUI_TYPE = SimplestGUI;
#endif

int main() {
    GUI_TYPE gui;
    GameMaster game(gui);
    game.openMenu();
    return 0;
}