#pragma once

using std::pair;
class GUI_Interface {
private:

public:
    virtual pair<pair<int, int>, pair<int, int>> placeShip(const Board& board, int length) = 0;
    virtual ~GUI_Interface() = 0;
};
