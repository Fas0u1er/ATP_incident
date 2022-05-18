#pragma once
#include <string>

#include <SFML/Graphics.hpp>

const int GUI_TEXT_MAX = 24;

const int GUI_TEXT_BACKSPACE = 8;
const int GUI_TEXT_ESCAPE = 27;
const int GUI_TEXT_ENTER = 13;

const sf::Color GUI_TEXT_GRAY = sf::Color(105, 105, 105);

class InputField {
public:
    InputField();

    void setPosition(sf::Vector2f vec);

    bool input(sf::Event ev);

    void setFont(sf::Font& f);

    const sf::String& getText();

    void setPlaceholder(std::string str);

    void draw(sf::RenderWindow& window);

    void setLength(int arg);

    int getTextLength();

    bool isActive();

    void open();

    void clear();

private:
    sf::Text txt;
    sf::RectangleShape box;

    int size;

    int length;

    bool renderPlaceholder;

    void setActive(bool arg);

    bool active;

    sf::Vector2f pos;

    std::string placeholder;
};

