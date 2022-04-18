#pragma once

#include <vector>


class Player;
class Board;

class BoardBuilder {
public:
    static BoardBuilder& getInstance();

    Board constructEmptyRectangleBoard();

    void fillShips(Player*, Board*);

private:
    BoardBuilder() = default;
};