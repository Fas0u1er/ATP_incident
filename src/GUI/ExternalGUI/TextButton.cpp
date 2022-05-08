#include "TextButton.h"

const sf::Vector2f TextButton::shift = sf::Vector2f(10, 10);
sf::Text TextButton::createText(const std::string& text, int fontSize, const sf::Font& font) {
    sf::Text result;
    result.setFont(font);
    result.setString(text);
    result.setCharacterSize(fontSize);
    result.setFillColor(sf::Color::Black);
    return result;
}
void TextButton::draw(sf::RenderWindow& window, bool reset) {
    ButtonBase::draw(window, false);
    window.draw(text);
    if (reset)
        this->reset();
}
void TextButton::setPosition(sf::Vector2f position) {
    rectangle.setPosition(position);
    auto globalBounds = text.getGlobalBounds();
    text.move(position.x - globalBounds.left + shift.x / 2, position.y - globalBounds.top + shift.y / 2.f);
}


TextButton::TextButton(const sf::Text& text,
                       ButtonBase::functionType onClick,
                       ButtonBase::functionType onHover,
                       ButtonBase::functionType setDefault) : ButtonBase(std::move(onClick), std::move(onHover), std::move(setDefault)), text(text) {
    setText(text);
    rectangle.setFillColor(sf::Color::Yellow);
    setPosition({0, 0});
}

sf::Font TextButton::defaultFont = sf::Font();
void TextButton::setText(const sf::Text& newText) {
    text.setString(newText.getString());
    auto globalBounds = newText.getGlobalBounds();
    rectangle.setSize({globalBounds.width + shift.x, globalBounds.height + shift.y});
}
void TextButton::setSize(sf::Vector2f newSize) {
    rectangle.setSize(newSize);
}
void TextButton::move(sf::Vector2f offset) {
    rectangle.move(offset);
    text.move(offset);
}
