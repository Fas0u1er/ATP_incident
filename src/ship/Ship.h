#pragma once
#include <vector>
#include <string>

class ShipFactory;
class Cell;

class Ship {
public:
    enum State {
        untouched, attacked, dead
    };

    enum Type {
        line,
        cross,
        /* Size = one way length of ray
           For example:
            #
           ###
            #
            Has size 1*/
        T,
        /* Size = (common length of both vertical and horizontal parts - 1) / 2
           For example:
            ###
             #
             #
            Has size 1*/
        square
    };

    static std::string typeToString(Type);

    int getSize();

    int getHP();

    bool isAlive();

    Type getType();

    State getState();

    void updateState();

    std::vector<Cell*> getCells();

private:
    friend ShipFactory;
    std::vector<Cell*> cells;
    State state;
    Type type;
};