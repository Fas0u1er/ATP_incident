#include "DisplayableBoard.h"
#include "src/board/Board.h"
#include "src/board/Cell.h"

void DisplayableBoard::recolor(Board& board, bool isMine) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            sf::Color color;
            switch (board.getCellPtr({i, j})->getState()) {
                case Cell::sea: { //Sea blue
                    color = sf::Color(0, 105, 148);
                    break;
                }
                case Cell::deadSea: { //Navy blue
                    color = sf::Color(11, 11, 69);
                    break;
                }
                case Cell::ship: { // Light gray
                    color = isMine ? sf::Color(211, 211, 211) : sf::Color(0, 105, 148);
                    break;
                }
                case Cell::attackedShip: { // Dark orange
                    color = sf::Color(220, 88, 42);
                    break;
                }
                case Cell::deadShip: { // Dark gray
                    color = sf::Color(33, 33, 33);
                    break;
                }
                case Cell::pendingShip: { // Green
                    color = sf::Color::Green;
                    break;
                }
                case Cell::misplacedShip: { // Red
                    color = sf::Color::Red;
                    break;
                }
                case Cell::island:{// Light green
                    color = sf::Color(171, 219, 35);
                    break;
                }
                default: throw std::logic_error("Unknown cell type in recolor");
            }
            grid[i][j].rectangle.setFillColor(color);
        }
    }
}

void DisplayableBoard::draw(sf::RenderWindow& window) {
    for (auto& el: verticalLines) {
        window.draw(el);
    }
    for (auto& el: horizontalLines) {
        window.draw(el);
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j].draw(window);
        }
    }
}
DisplayableBoard::DisplayableBoard(int height, int width, sf::Vector2f shift) : height(height), width(width) {
    TextButton temp({}, {},
                    [](ButtonBase& this_) { //On Hover
                      auto& actualThis = dynamic_cast<TextButton&>(this_);
                      actualThis.rectangle.setOutlineColor(sf::Color::Magenta);
                      actualThis.rectangle.setOutlineThickness(3);
                    },
                    [](ButtonBase& this_) { //setdefault
                      auto& actualThis = dynamic_cast<TextButton&>(this_);
                      actualThis.rectangle.setOutlineColor(sf::Color::Transparent);
                    });
    temp.setSize({CELL_SIZE, CELL_SIZE});
    grid.resize(height, std::vector<TextButton>(width, temp));
    float verticalPosition = 0;
    float totalWidth = (width + 1) * SEPARATOR_SIZE + width * CELL_SIZE;
    float totalHeight = (height + 1) * SEPARATOR_SIZE + height * CELL_SIZE;
    for (int i = 0; i < height; ++i) {
        horizontalLines.emplace_back(sf::Vector2f{totalWidth, SEPARATOR_SIZE});
        horizontalLines.back().setPosition(0, verticalPosition);
        horizontalLines.back().setFillColor(sf::Color::Black);
        verticalPosition += SEPARATOR_SIZE;
        float horizontalPosition = SEPARATOR_SIZE;
        for (int j = 0; j < width; ++j) {
            grid[i][j].setPosition({horizontalPosition, verticalPosition});
            horizontalPosition += SEPARATOR_SIZE + CELL_SIZE;
        }
        verticalPosition += CELL_SIZE;
    }
    horizontalLines.emplace_back(sf::Vector2f{totalWidth, SEPARATOR_SIZE});
    horizontalLines.back().setPosition(0, verticalPosition);
    float horizontalPosition = 0;
    for (int i = 0; i <= width; ++i) {
        verticalLines.emplace_back(sf::Vector2f{SEPARATOR_SIZE, totalHeight});
        verticalLines.back().setPosition(horizontalPosition, 0);
        verticalLines.back().setFillColor(sf::Color::Black);
        horizontalPosition += CELL_SIZE + SEPARATOR_SIZE;
    }
    for (auto& el: verticalLines) {
        el.move(shift);
    }
    for (auto& el: horizontalLines) {
        el.move(shift);

    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grid[i][j].move(shift);
        }
    }
}
Position DisplayableBoard::doHover(sf::Vector2f position) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j].doHover(position))
                return {i, j};
        }
    }
    return {-1, -1};
}

Position DisplayableBoard::processEvent(sf::Event& event) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j].processEvent(event))
                return {i, j};
        }
    }
    return {-1, -1};
}
