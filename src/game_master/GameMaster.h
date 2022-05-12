#pragma once

#include <vector>

class Player;
class GUI;

using std::vector;

class GameMaster {
    vector<Player*> players;
    GUI& gui;
    int roundsPlayed;

public:
    explicit GameMaster(GUI& gui);
    void openMenu();
private:
    void runBattle();
    void initializePlayers();
    void showResults();
};
