#include "Bot.h"

Bot::Bot(int index) : Player(index),
                      gen(std::random_device()()) {}

Position Bot::get_random_cell() {
    int i = get_randint(GlobalSettings::getInstance().boardHeight);
    int j = get_randint(GlobalSettings::getInstance().boardWidth);
    return {i, j};
}

int Bot::get_randint(int range) {
    std::uniform_int_distribution<> distrib(0, range - 1);
    return distrib(gen);
}

