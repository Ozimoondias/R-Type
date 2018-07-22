//
// Created by agar on 15/02/18.
//

#include "Button.hpp"

Button::Button(const std::string &str, const float x, const float y)
        : Entity(str, x, y, 0)
{
    _sprite.setPosition(((1920/2) - _sprite.getGlobalBounds().width / 2), y);
}

const   bool    Button::doShot()
{
    return (true);
}

void    Button::update()
{
}

void    Button::draw(sf::RenderWindow &window)
{
    window.draw(getSprite());
}