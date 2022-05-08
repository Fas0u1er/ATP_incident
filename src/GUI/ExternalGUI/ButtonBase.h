#pragma once

#include "SFML/Graphics.hpp"
#include "functional"

class ButtonBase {
public:
    using functionType = std::function<void(ButtonBase&)>;
    bool processEvent(sf::Event& event);
private:
    functionType onClick;
    functionType onHover;
    functionType setDefault;


public:
    sf::RectangleShape rectangle;
    virtual void draw(sf::RenderWindow& window, bool reset = true);
    void reset();
    bool doHover(sf::Vector2f position);

    explicit ButtonBase(
        functionType onClick = {},
        functionType onHover = {},
        functionType setDefault = {}
    );

    static bool isLeftMouseButton(const sf::Event& event);

};

