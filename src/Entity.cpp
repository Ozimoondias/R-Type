//
// Created by agar on 26/01/18.
//

#include "Entity.hpp"
#include <iostream>

Entity::Entity(const std::string &str, const float x, const float y, const float sd)
{
    _texture.loadFromFile(str);
    _sprite.setTexture(_texture);
    _sprite.setPosition(x, y);
    _alive = true;
    _speed = sd;
}

void        Entity::setPv(const int pv)
{
    _pv = pv;
}

const int   Entity::getPv()
{
    return (_pv);
}

void        Entity::setScore(const int score)
{
    _score = score;
}

const   int Entity::getScore()
{
    return (_score);
}

void        Entity::setAlive(const float state)
{
    _alive = state;
}

const float Entity::getAlive()
{
    return (_alive);
}

const float Entity::getSpeed()
{
    return (_speed);
}

sf::Texture &Entity::getTexture()
{
    return (_texture);
}

sf::Sprite  &Entity::getSprite()
{
    return (_sprite);
}

sf::Sound   &Entity::getSound()
{
    return (_sound);
}

void        Entity::Move(const float x, const float y)
{
    _sprite.move(x, y);
}

void        Entity::setSpeed(const float x)
{
    _speed = x;
}

void        Entity::setTexture(const std::string &str)
{
    _texture.loadFromFile(str);
    _sprite.setTexture(_texture);
}

void        Entity::playSound()
{
    if (!_sound.Playing)
        _sound.play();
}