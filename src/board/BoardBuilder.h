#pragma once

#include <vector>
#include <memory>


class Player;
class RectangleBoard;
class Board;

class BoardBuilder {
public:
    static BoardBuilder& getInstance();

    std::unique_ptr <Board> constructEmptyRectangleBoard();

    void fillShips(Player*, Board*);

private:
    BoardBuilder() = default;
};