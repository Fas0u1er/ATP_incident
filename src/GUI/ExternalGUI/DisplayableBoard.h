#pragma once

#include <vector>
#include "TextButton.h"
#include "src/board/Position.h"
class Board;

class DisplayableBoard {
//    sf::RectangleShape rectangle(sf::Vector2f(squareSize, squareSize));
//    rectangle.setFillColor(sf::Color(0, 105, 148));
    std::vector<std::vector<TextButton>> grid;
    std::vector<sf::RectangleShape> verticalLines;
    std::vector<sf::RectangleShape> horizontalLines;

    constexpr static float CELL_SIZE = 40;
    constexpr static float SEPARATOR_SIZE = 3;
public:
    int height;
    int width;
    DisplayableBoard(int height, int width, sf::Vector2f shift);
    void draw(sf::RenderWindow& window);
    void recolor(Board& board, bool isMine);
    Position doHover(sf::Vector2f position);
    Position processEvent(sf::Event& event);
    float right() {
        return verticalLines.back().getGlobalBounds().left + SEPARATOR_SIZE;
    }

    float left() {
        return verticalLines[0].getGlobalBounds().left;
    }

    float bottom() {
        return horizontalLines.back().getGlobalBounds().top + SEPARATOR_SIZE;
    }
};