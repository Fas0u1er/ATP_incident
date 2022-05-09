#pragma once

#include <utility>

#include "ButtonBase.h"
#include "functional"
class TextButton;

class TextButton : public ButtonBase {

    static const sf::Vector2f shift;


public:
    static sf::Text createText(const std::string& text,
                               int fontSize = regularTextSize,
                               const sf::Font& font = defaultFont);
    static const int regularTextSize = 30;
    static const int titleTextSize = 48;
    static sf::Font defaultFont;

    explicit TextButton(
        const sf::Text& text,
        functionType onClick = {},
        functionType onHover = {},
        functionType setDefault = {}
    );

    void setPosition(sf::Vector2f position);

    void draw(sf::RenderWindow& window, bool reset = true) override;

    void setText(const sf::Text& newText);

    void setSize(sf::Vector2f newSize);

    void move(sf::Vector2f offset);

    void defaultClickable();

    sf::Text text;
};

