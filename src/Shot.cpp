//
// Created by agar on 26/01/18.
//

#include "Shot.hpp"

Shot::Shot(const std::string &str, const float x, const float y, const float sd, const float d, const int type)
        : Entity(str, x, y, sd)
{
    _fr = d;
    _type = type;
    _clock.restart();
}

void    Shot::update()
{
    if (_clock.getElapsedTime().asSeconds() >= _fr)
        _alive = false;
    switch (_type)
    {
        case -2:
            Move(_speed, -5);
            break;
        case -1:
            Move(_speed, -2.5);
            break;
        case 0:
            Move(_speed, 0);
            break;
        case 1:
            Move(_speed, 2.5);
            break;
        case 2:
            Move(_speed, 5);
            break;
    }
}

void    Shot::draw(sf::RenderWindow &window)
{
    window.draw(getSprite());
}