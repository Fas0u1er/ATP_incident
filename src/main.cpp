#include "src/game_master/GameMaster.h"

#ifdef USE_GUI
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
} //TODO: После завершения хода не показывать сразу доску следующего игрока
 //TODO: Показать результаты после завершения игры
 //TODO: Добавить в настройки включение/выключение острова, изменение его размеров
 //TODO: Нормальный цвет кнопок, паддинг