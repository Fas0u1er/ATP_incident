#pragma once
#include "Board.h"
#include "Settings.h"
#include "Ship.h"


class Player {
protected:
    Board board;
    Settings settings;
public:
    virtual void setSettings(const Settings&) = 0;
    virtual void addShip(const Ship&) = 0;
    virtual void removeShip(const Ship&) = 0;
    virtual bool shipCount() = 0;
    virtual void doTurn() = 0;
    virtual const Board& getBoard() = 0;
    virtual const Settings& getSettings() = 0;

    virtual ~Player() = 0;
};


