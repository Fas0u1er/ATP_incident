#include "GlobalSettings.h"

GlobalSettings::GlobalSettings() {
    int amount = 0;
    for (const auto& [type, sizes] : ships) {
        amount += sizes.size();
    }
    assert(amount == shipsNumber);
    resize(playerNumber);
}
void GlobalSettings::resize(int newPlayerNumber) {
    playerNumber = newPlayerNumber;
    int difference = playerNumber - int(playerSettings.size());
    if (difference > 0) {
        for (int i = 0; i < difference; ++i) {
            playerSettings.emplace_back();
            playerSettings.back().name = "Placeholder name #" + std::to_string(playerSettings.size());
        }
    } else
        playerSettings.resize(newPlayerNumber);
}
GlobalSettings& GlobalSettings::getInstance() {
    static GlobalSettings obj;
    return obj;
}
