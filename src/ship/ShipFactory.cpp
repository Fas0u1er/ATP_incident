#include "ShipFactory.h"

ShipFactory& ShipFactory::getInstance() {
    static ShipFactory instance;
    return instance;
}

Ship ShipFactory::constructShip(Player* playerPtr, Ship::Type type, int size) {
    Ship ship;
    vector<Cell*> newPlace;
    bool appropriatePlace = false;
    while(!appropriatePlace) {

        newPlace = playerPtr->getNewShipCells(type, size);
        appropriatePlace = true;

        for (auto cellPtr : newPlace) {
            if(!cellPtr->isFarFromShips()) {
                appropriatePlace = false;
                break;
            }
        }
    }

    ship.cells = newPlace;
    ship.state = Ship::State::untouched;
    ship.type = type;

    return ship;
}
