#pragma once

#include "vector"
#include "iostream"
#include "string"
#include "cassert"
#include "iomanip"
#include "SFML/Graphics.hpp"

#include "src/GUI/GUI.h"
#include "DisplayableBoard.h"

class Position;
class Player;

class ExternalGUI : public GUI {
private:

    void processEvents();

    bool basicProcessing(sf::Event& event);

    sf::Text createTitle(const std::string& text);

public:

    int displayOptions(const std::string& title, const std::vector<std::string>& options) override;

    Position getAttack(const Player& player, const Player& enemy) override;

    std::vector<Cell*> placeShip(Player& player, SimpleShip::Type type, int size) override;
    void displaySettings(const std::string& title, std::vector<Setting*>&) override;
    void showResults(const Player& winner, int roundsPlayed) override;
    void finishWork() override;

    void waitForNextPlayer(const Player &player) override;

    ExternalGUI();

private:

    static const int windowHeight = 1000;
    static const int windowWidth = 1600;

    sf::RenderWindow window;
};
