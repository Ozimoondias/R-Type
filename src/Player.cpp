//
// Created by agar on 27/01/18.
//

#include "Player.hpp"

Player::Player(const std::string &str, const float x, const float y, const float sd, const int pv)
        : Entity(str, x, y, sd)
{
    _pv = pv + 5;
    _score  = 0;

    font.loadFromFile("../media/Neoneon.otf");

    textpv.setFont(font);
    textpv.setPosition(700.f, 5.f);
    textpv.setCharacterSize(50);
    textpv.setFillColor(sf::Color::Green);

    textscore.setFont(font);
    textscore.setPosition(1100.f, 5.f);
    textscore.setCharacterSize(50);
    textscore.setFillColor(sf::Color::Cyan);

}

void    Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        Move(1.5 * _speed,  0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        Move(-1.5 * _speed,  0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        Move(0,  1.5 * _speed);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        Move(0,  -1.5 * _speed);
}

void    Player::draw(sf::RenderWindow &window)
{
    textpv.setString("PV\t" + std::to_string(_pv));
    textscore.setString("SCORE\t" + std::to_string(_score));
    window.draw(getSprite());
    window.draw(textpv);
    window.draw(textscore);
}