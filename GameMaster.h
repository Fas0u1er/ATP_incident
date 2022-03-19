#pragma once
#include "Player.h"
#include "ConsoleLibrary/Displayer.h"
#include "Settings.h"
#include "vector"
#include "memory"

using std::vector;
using std::unique_ptr;
class GameMaster {
    vector<unique_ptr<Player> > players;
    Displayer& displayer;


    void menu();
    void menu_Play();
    void menu_Settings();
    void menu_Exit();
    void play_FillBoards();
    void play_SetPlayers();
    void play_DoTurns();
    void countPlayers();

public:
    explicit GameMaster(Displayer& displayer);
    void run();

};
