#pragma once
#include "vector"
#include "iostream"
#include "string"
#include "cassert"
#include "iomanip"

#include "GUIInterface.h"
class Position;
class Player;

class SimplestGUI : public GUIInterface {
private:

    template<typename T>
    void printElement(T t, const int& width);

    static void wrongInput();

    static int getInt();

    static Position get1IndexedPosition();

    static Position get0IndexedPosition();

    static char getChar(const std::string& valid);

    static Position charToDirection(char c);

public:
    void displayBoard(const Board& board, bool isMine) override;

    int displayOptions(const std::string& title, const vector<string>& options) override;

    Position getAttack(const Player& player, const Board& attackedBoard) override;

    void displayPlayer(const Player& player, bool isMine) override;

    std::vector<Cell*> placeShip(Player& player, Ship::Type type, int size) override;

    void clearScreen() override;

};
