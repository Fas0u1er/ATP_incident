#pragma once
#include "Player.h"
#include "GUI_Interface.h"
#include "Settings.h"
#include "vector"
#include "memory"
#include "Board.h"

using std::vector;
using std::unique_ptr;
class GameMaster {
    vector<unique_ptr<Player> > players;
    GUI_Interface& displayer;


    void menu();
    void menu_Play();
    void menu_Settings();
    void menu_Exit();
    void play_FillBoards();
    void play_SetPlayers();
    void play_DoTurns();
    void countPlayers();

public:
    explicit GameMaster(GUI_Interface& displayer);
    void run();

};
