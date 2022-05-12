#include "Bot.h"

Bot::Bot(int index) : Player(index),
                      gen(std::random_device()()) {}

Position Bot::getRandomCell() {
    int i = getRandint(GlobalSettings::getInstance().boardHeight);
    int j = getRandint(GlobalSettings::getInstance().boardWidth);
    return {i, j};
}

int Bot::getRandint(int range) {
    return std::uniform_int_distribution<> (0, range - 1)(gen);
}

