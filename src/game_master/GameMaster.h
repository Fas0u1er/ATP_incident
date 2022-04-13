#pragma once

#include <vector>

class Player;
class GUIInterface;

using std::vector;

class GameMaster {
    vector<Player*> players;
    GUIInterface& gui;
public:
    explicit GameMaster(GUIInterface& gui);
    void openMenu();
private:
    void runBattle();
    void initializePlayers();
    void showResults();
};
