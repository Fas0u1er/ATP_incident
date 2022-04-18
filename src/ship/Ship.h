#pragma once

#include <string>
#include <vector>

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
    static const std::vector <std::string> typeToString;
    virtual void updateState() = 0;

    [[nodiscard]] State getState() const;

protected:

    [[nodiscard]] int getSize() const;

    [[nodiscard]] int getHP() const;

    [[nodiscard]] bool isAlive() const;

    [[nodiscard]] Type getType() const;


    std::vector<Cell*>& getCells();

    friend ShipFactory;
    std::vector<Cell*> cells;
    State state;
    Type type;
};
