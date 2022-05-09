#include "ExternalGUI.h"
#include "src/board/Position.h"
#include "src/settings/Setting.h"
#include "TextButton.h"
#include "src/player/Player.h"
#include "InputField.h"
#include "src/settings/GlobalSettings.h"
#include "src/ship/ShipFactory.h"

int ExternalGUI::displayOptions(const std::string& title, const std::vector<std::string>& options) {
    // Create entities
    auto titleEntity = createTitle(title);
    std::vector<TextButton> displayableOptions;
    {
        auto globalBounds = titleEntity.getGlobalBounds();
        sf::Vector2f position(0, globalBounds.top + globalBounds.height + 20);
        sf::Vector2f vShift(0, 10);
        for (int i = 0; i < options.size(); ++i) {
            displayableOptions.emplace_back(
                TextButton::createText(options[i])
            );
            displayableOptions[i].setPosition(position);
            auto rectangle = displayableOptions[i].rectangle.getGlobalBounds();
            position = sf::Vector2f{0, rectangle.top + rectangle.height} + vShift;
        }
    }

    //Discard useless events
    processEvents();
    while (true) {

        //Process events from previous iteration
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (basicProcessing(event))
                continue;
            for (int i = 0; i < options.size(); ++i) {
                if (displayableOptions[i].processEvent(event))
                    return i;
            }
        }

        window.clear(sf::Color::White);

        //Render
        auto mousePosition = sf::Mouse::getPosition(window);
        for (int i = 0; i < options.size(); ++i) {
            if (displayableOptions[i].doHover(sf::Vector2f(mousePosition.x, mousePosition.y))) {
                break;
            }
        }
        window.draw(titleEntity);
        for (auto& option: displayableOptions) {
            option.draw(window);
        }
        window.display();
    }
}
Position ExternalGUI::getAttack(const Player& player, const Player& enemy) {
    // Create entities
    auto& globalSettings = GlobalSettings::getInstance();
    auto titleEntity = createTitle(player.getName() + ", attack!");
    DisplayableBoard myBoard(globalSettings.boardHeight, globalSettings.boardWidth, {10, 100});
    float right = myBoard.right() + 80;
    DisplayableBoard enemyBoard(globalSettings.boardHeight, globalSettings.boardWidth, {right, 100});
    auto yourBoardText = TextButton::createText("Your board");
    sf::FloatRect textRect = yourBoardText.getLocalBounds();
    yourBoardText.setOrigin(textRect.left + textRect.width / 2.f,
                     textRect.top);

    yourBoardText.setPosition((myBoard.left() + myBoard.right()) / 2, myBoard.bottom() + 30);
    auto enemyBoardText = TextButton::createText(enemy.getName() + "'s board");
    textRect = enemyBoardText.getLocalBounds();
    enemyBoardText.setOrigin(textRect.left + textRect.width / 2.f,
                            textRect.top);

    enemyBoardText.setPosition((enemyBoard.left() + enemyBoard.right()) / 2, enemyBoard.bottom() + 30);
    //Discard useless events
    processEvents();
    while (true) {
        //Process events from previous iteration
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (basicProcessing(event))
                continue;
        }
        auto clickedPosition = enemyBoard.processEvent(event);
        if (enemy.board->withinBorders(clickedPosition) && enemy.board->getCellPtr(clickedPosition)->isOkToAttack()) {
            return clickedPosition;
        }

        window.clear(sf::Color::White);

        //Render
        auto mousePosition = sf::Mouse::getPosition(window);
        auto highlightedPosition =
            enemyBoard.doHover({static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)});
        window.draw(titleEntity);
        window.draw(yourBoardText);
        window.draw(enemyBoardText);
        myBoard.recolor(*player.board, true);
        enemyBoard.recolor(*enemy.board, false);
        myBoard.draw(window);
        enemyBoard.draw(window);
        window.display();
    }
}
std::vector<Cell*> ExternalGUI::placeShip(Player& player, SimpleShip::Type type, int size) {
    // Create entities
    auto& globalSettings = GlobalSettings::getInstance();
    auto titleEntity = createTitle(player.getName() + ", place a ship");
    DisplayableBoard myBoard(globalSettings.boardHeight, globalSettings.boardWidth, {10, 100});
    //Discard useless events
    processEvents();
    Position direction = {0, 1};
    while (true) {
        //Process events from previous iteration
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (basicProcessing(event))
                continue;
            if (event.type == sf::Event::MouseWheelScrolled) {
                if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                    if (event.mouseWheelScroll.delta > 0) {
                        direction.rotate(false);
                    } else {
                        direction.rotate(true);
                    }
                }
            }
            auto clickedPosition = myBoard.processEvent(event);
            auto positions = ShipFactory::generateShipPositions(type, clickedPosition, size, direction);
            auto ship = ShipFactory::convertPositioning(positions, *player.board);
            if (!ship.empty()) {
                return ship;
            }
        }

        window.clear(sf::Color::White);

        //Render
        auto mousePosition = sf::Mouse::getPosition(window);
        auto highlightedPosition =
            myBoard.doHover({static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)});
        std::vector<Cell::State> previousStates;
        std::vector<Position> positions;
        if (highlightedPosition != Position{-1, -1}) {
            positions = ShipFactory::generateShipPositions(type, highlightedPosition, size, direction);
            for (auto position: positions) {
                auto cell = player.board->getCellPtr(position);
                if (!player.board->withinBorders(position) || cell->isShip())
                    continue;
                previousStates.push_back(cell->getState());
                if (!cell->isOkToPlaceShip()) {
                    cell->setState(Cell::State::misplacedShip);
                } else {
                    cell->setState(Cell::State::pendingShip);
                }
            }
        }
        window.draw(titleEntity);
        myBoard.recolor(*player.board, true);
        myBoard.draw(window);
        window.display();
        if (highlightedPosition != Position{-1, -1}) {
            int index = 0;
            for (auto position: positions) {
                auto cell = player.board->getCellPtr(position);
                if (!player.board->withinBorders(position) || cell->isShip())
                    continue;
                cell->setState(previousStates[index++]);
            }
        }

    }
}
void ExternalGUI::showResults(const Player& winner, int roundsPlayed) {

}
void ExternalGUI::finishWork() {

}
void ExternalGUI::displaySettings(const std::string& title, std::vector<Setting*>& settings) {
    // Create entities
    auto titleEntity = createTitle(title);
    std::vector<TextButton> descriptions;
    std::vector<InputField> inputs;
    auto exitEntity = TextButton(TextButton::createText("Exit"));
    {
        auto globalBounds = titleEntity.getGlobalBounds();
        sf::Vector2f position(0, globalBounds.top + globalBounds.height + 20);
        sf::Vector2f vShift(0, 10);
        float maxWidth = 0;
        for (int i = 0; i < settings.size(); ++i) {
            descriptions.emplace_back(
                TextButton::createText(settings[i]->getDescription() + ": " + settings[i]->toString())
            );
            descriptions[i].setPosition(position);
            auto rectangle = descriptions[i].rectangle.getGlobalBounds();
            position = sf::Vector2f{0, rectangle.top + rectangle.height} + vShift;
            maxWidth = std::max(maxWidth, rectangle.width + rectangle.left);
        }
        position.x = std::max(maxWidth + 20, 100.f);
        for (int i = 0; i < settings.size(); ++i) {
            inputs.emplace_back();
            inputs[i].setPosition({position.x, descriptions[i].rectangle.getGlobalBounds().top});
            inputs[i].setFont(TextButton::defaultFont);
            inputs[i].setPlaceholder("New value");
        }
        globalBounds = descriptions.back().rectangle.getGlobalBounds();
        exitEntity.setPosition({globalBounds.left, globalBounds.top + globalBounds.height + 30});
    }

    //Discard useless events
    processEvents();
    while (true) {

        //Process events from previous iteration
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (basicProcessing(event))
                continue;
            for (int i = 0; i < inputs.size(); ++i) {
                if (inputs[i].input(event)) {
                    auto tmp = std::stringstream(inputs[i].getText());
                    if (settings[i]->parseFromInput(tmp)) {
                        inputs[i].clear();
                        descriptions[i].setText(
                            TextButton::createText(settings[i]->getDescription() + ": " + settings[i]->toString())
                        );
                    }
                }
            }
            if (exitEntity.processEvent(event))
                return;
        }

        window.clear(sf::Color::White);

        //Render
        window.draw(titleEntity);
        for (auto& description: descriptions) {
            description.draw(window);
        }

        for (auto& input: inputs) {
            input.draw(window);
        }

        exitEntity.draw(window);

        window.display();
    }
}
void ExternalGUI::processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        basicProcessing(event);
    }
}

sf::Text ExternalGUI::createTitle(const std::string& text) {
    sf::Text result;
    int delta = 0;
    while (true) {
        result = TextButton::createText(text, TextButton::titleTextSize - delta);
        if (result.getLocalBounds().width > windowWidth)
            delta += 2;
        else
            break;
    }
    sf::FloatRect textRect = result.getLocalBounds();
    result.setOrigin(textRect.left + textRect.width / 2.f,
                     textRect.top);

    result.setPosition(sf::Vector2f(windowWidth / 2.f, 10));
    return result;
}
bool ExternalGUI::basicProcessing(sf::Event& event) {
    switch (event.type) {
        case (sf::Event::Closed): {
            window.close();
            exit(0);
        }
        case (sf::Event::Resized): {
            sf::FloatRect view(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(view));
            return true;
        }
        default: return false;
    }
}
ExternalGUI::ExternalGUI() : window(sf::VideoMode(windowWidth, windowHeight), "Battleships!") {
    TextButton::defaultFont.loadFromFile("../resources/fonts/JetBrainsMonoNL-Medium.ttf");
    window.setFramerateLimit(120);
}
