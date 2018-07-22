//
// Created by agar on 20/02/18.
//

#include "Bonus.hpp"

Bonus::Bonus(const std::string &str, const float x, const float y, const int type)
        : Entity(str, x, y, 0)
{
    _type = type;
}

void    Bonus::update()
{
    Move(-1,  2);
}

void    Bonus::draw(sf::RenderWindow &window)
{
    window.draw(getSprite());
}

bool    Bonus::getBonus(std::unique_ptr<Entity> &player)
{
    switch (_type)
    {
        case 1:
            player->setSpeed(player->getSpeed() + 0.2);
            break;
        case 2:
            player->setPv(player->getPv() + 2);
            break;
        case 3:
            return (true);
    }
    return (false);
}
