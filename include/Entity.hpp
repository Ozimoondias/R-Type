//
// Created by agar on 26/01/18.
//

#ifndef CPP_RTYPE_ENTITY_HPP
#define CPP_RTYPE_ENTITY_HPP

#include <iostream>
#include    <SFML/Audio.hpp>
#include    <SFML/System.hpp>
#include    <SFML/Window.hpp>
#include    <SFML/Graphics.hpp>

class       Entity
{

public:

    Entity(){}
    Entity(const std::string &, const float, const float, const float);
    virtual ~Entity(){}

    sf::Texture &getTexture();
    sf::Sprite  &getSprite();
    sf::Sound   &getSound();

    void        playSound();
    void        setSpeed(const float);
    void        Move(const float, const float);
    void        setTexture(const std::string &);

    const   int     getPv();
    void            setPv(const int);

    const   int     getScore();
    void            setScore(const int);

    const   float   getAlive();
    void            setAlive(const float);

    const float     getSpeed();

    virtual void    draw(sf::RenderWindow &) = 0;
    virtual void    update() = 0;
    virtual const bool  doShot() = 0;

protected:

    int         _pv;
    int         _score;

    bool        _alive;
    float       _speed;

    sf::Sound   _sound;
    sf::Sprite  _sprite;
    sf::Texture _texture;

};

#endif //CPP_RTYPE_ENTITY_HPP