//
// Created by agar on 27/01/18.
//

#include <cmath>
#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(const std::string &str, const float x, const float y, const float sd, const int pv, const int pattern)
        : Entity(str, x, y, sd)
{
    pi = 0;
    _pv = pv;
    whitch = pattern;
    _clock.restart();
    _clockShot.restart();
    _clockPattern.restart();
    setPattern(str);
}

void    Enemy::setPattern(const std::string &str)
{
    if (whitch == 1)
        setEnemyPattern();
    else if (whitch == 2)
        setEscadronPattern();
    else if (whitch == 3)
        setMeteorPattern();
}

void    Enemy::setEnemyPattern()
{
    int o = rand() % 100;

    if (o >= 50)
        _sprite.setPosition(_sprite.getPosition().x - o,  _sprite.getPosition().y - o);
    else
        _sprite.setPosition(_sprite.getPosition().x + o,  _sprite.getPosition().y - o);

    typedef void (Enemy::*func_ptr)();
    func_ptr      ptr[5] =
          {
                  &Enemy::firstPattern,
                  &Enemy::secondPattern,
                  &Enemy::thirdPattern,
                  &Enemy::fourthPattern,
                  &Enemy::fifthPattern
          };
    srand(time(NULL));
    (this->*ptr[rand() % 5])();

    int i = rand() % 100;
    _sprite.setPosition(_sprite.getPosition().x,  _sprite.getPosition().y - i);
}

void    Enemy::setEscadronPattern()
{
  EscPattern1();
}

void    Enemy::setMeteorPattern()
{
    int o = rand() % 100;

    if (o >= 50)
        _sprite.setPosition(_sprite.getPosition().x - o,  _sprite.getPosition().y + o);
    else
        _sprite.setPosition(_sprite.getPosition().x + o,  _sprite.getPosition().y - o);

    typedef void (Enemy::*func_ptr)();
    func_ptr      ptr[3] =
            {
                    &Enemy::MeteorPattern1,
                    &Enemy::MeteorPattern2,
                    &Enemy::MeteorPattern3,
            };
    srand(time(NULL));
    (this->*ptr[rand() % 3])();

    int i = rand() % 100;
    _sprite.setPosition(_sprite.getPosition().x,  _sprite.getPosition().y - i);
}

void    Enemy::doPattern()
{
    if (_clockPattern.getElapsedTime().asSeconds() >= 1)
    {
        if (pi == directions.size()-1)
            pi = 0;
        else
            pi += 1;
        _clockPattern.restart();
    }
    Move(directions[pi].getx() * directions[pi].getsp(), directions[pi].gety());
}

const   bool    Enemy::doShot()
{
    if (_clockShot.getElapsedTime().asSeconds() >= directions[pi].getfr())
    {
        _clockShot.restart();
        return (true);
    }
    return (false);
}

void    Enemy::update()
{
    if (_clock.getElapsedTime().asSeconds() >= 25)
        _alive = false;
    doPattern();
    //doShot();
}

void    Enemy::draw(sf::RenderWindow &window)
{
    window.draw(getSprite());
}

// ------------------------------------------PATTERNS--------------------------------------

void	Enemy::firstPattern() // pattern rond+remonte
{
  directions.push_back(Pattern(-1.f, -6.5, 12, 20));
  directions.push_back(Pattern(-1.f, 6.5, 12, 13.5));
  directions.push_back(Pattern(2.f, 20, 2, 15));
}

void	Enemy::secondPattern() // barrage de tirs 
{
  directions.push_back(Pattern(-1.f, 6.5, 300, 6));
  directions.push_back(Pattern(0.f, -10, 1, 6));
  directions.push_back(Pattern(0.f, -10, 300, 6));
  directions.push_back(Pattern(0.f, -10, 300, 6));
}

void	Enemy::thirdPattern() // triangle
{
  directions.push_back(Pattern(-1.f, 2, 1, 3));
  directions.push_back(Pattern(-1.f, 2, 1, 3));
  directions.push_back(Pattern(-1.f, -2, 1, 3));
  directions.push_back(Pattern(-1.f, -2, 1, 3));
  directions.push_back(Pattern(1.f, 0, 1, 3));
  directions.push_back(Pattern(1.f, 0, 1, 3));
}

void	Enemy::fourthPattern() // attaque en ligne et descends
{
  directions.push_back(Pattern(-1.f, 2, 300, 4));
  directions.push_back(Pattern(0.f, 0, 300, 3));
  directions.push_back(Pattern(0.f, 0, 2, 3));
  directions.push_back(Pattern(0.f, 0, 2, 3));
  directions.push_back(Pattern(-1.f, 0, 300, 22));
  directions.push_back(Pattern(1.f, 0, 300, 22));
  directions.push_back(Pattern(0.f, 5, 300, 6));
  directions.push_back(Pattern(0.f, 0, 300, 3));
  directions.push_back(Pattern(0.f, 0, 2, 3));
  directions.push_back(Pattern(0.f, 0, 2, 3));
  directions.push_back(Pattern(-1.f, 0, 300, 22));
  directions.push_back(Pattern(1.f, 0, 300, 22));
}

void	Enemy::fifthPattern() // va te chercher tout derriere 300
{
  directions.push_back(Pattern(-1.f, -5, 1, 20));
  directions.push_back(Pattern(-1.f, 0, 1, 12));
  directions.push_back(Pattern(0.f, 13, 1, 15));
  directions.push_back(Pattern(1.f, 0, 1, 30));
  directions.push_back(Pattern(1.f, 25, 1, 30));
  directions.push_back(Pattern(0.f, 12, 1, 25));
}

void    Enemy::EscPattern1() // escadron en mode fleche
{
  directions.push_back(Pattern(-1.f, 0, 2, 15));
}

void    Enemy::MeteorPattern1() // ligne droite normale
{
  directions.push_back(Pattern(-1.f, 0, 400, rand() % (30 - 20 + 1) + 20));
}

void    Enemy::MeteorPattern2() // pluie de meteorites venant du haut
{
  srand(time(NULL));
  _sprite.setPosition((rand() % 1800) + 300, -60);
  directions.push_back(Pattern(-1.f, 20, 400, rand() % (16 - 8 + 1) + 8));
}

void    Enemy::MeteorPattern3() // pluie de meteorites venant du bas
{
  srand(time(NULL));
  _sprite.setPosition((rand() % 1800) + 300, 1130);
  directions.push_back(Pattern(-1.f, -20, 400, rand() % (16 - 8 + 1) + 8));
}
