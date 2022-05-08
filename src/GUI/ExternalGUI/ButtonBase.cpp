#include "ButtonBase.h"

#include <utility>
bool ButtonBase::doHover(sf::Vector2f position) {
    if (rectangle.getGlobalBounds().contains(position)) {
        if (onHover)
            onHover(*this);
        return true;
    }
    return false;
}
bool ButtonBase::processEvent(sf::Event& event) {
    if (isLeftMouseButton(event) && rectangle.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
        if (onClick)
            onClick(*this);
        return true;
    }
    return false;
}

void ButtonBase::reset() {
    if (setDefault)
        setDefault(*this);
}

ButtonBase::ButtonBase(functionType onClick,
                       functionType onHover,
                       functionType setDefault) :
    onClick(std::move(onClick)),
    onHover(std::move(onHover)),
    setDefault(std::move(setDefault)) {

}
bool ButtonBase::isLeftMouseButton(const sf::Event& event) {
    return event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left;
}
void ButtonBase::draw(sf::RenderWindow& window, bool reset) {
    window.draw(rectangle);
    if (reset) {
        this->reset();
    }
}

