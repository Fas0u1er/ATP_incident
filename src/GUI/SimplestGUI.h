#pragma once
#include "vector"
#include "iostream"
#include "string"
#include "cassert"
#include "iomanip"

#include "GUI.h"
#include "src/board/Board.h"

class Position;
class Player;

class SimplestGUI : public GUI {
private:

    template<typename T>
    void printElement(T t, const int& width);

    static void wrongInput(bool waitForEnter);

    static int getInt();

    static Position get1IndexedPosition();

    static Position get0IndexedPosition();

    static char getChar(const std::string& valid);

    static Position charToDirection(char c);

    static std::string getNewLine();

    static void systemPause();

public:
    void displayBoard(const Board& board, bool isMine) override;

    int displayOptions(const std::string& title, const std::vector<std::string>& options) override;

    Position getAttack(const Player& player, Player& enemy) override;

    void displayPlayer(const Player& player, bool isMine) override;

    std::vector<Cell*> placeShip(Player& player, SimpleShip::Type type, int size) override;

    void clearScreen() override;

    void displaySettings(const std::string& title, std::vector<Setting*>&) override;
    void showResults(const Player& winner, int roundsPlayed) override;
    void finishWork() override;
};
