#include "GameMaster.h"
#include "ConsoleLibrary/ConsoleDisplayer.h"

int main() {
    ConsoleDisplayer displayer;
    GameMaster game(displayer);
    game.run();
}
