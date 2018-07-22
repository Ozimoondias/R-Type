//
// Created by agar on 26/01/18.
//

#ifndef CPP_RTYPE_SHOT_HPP
#define CPP_RTYPE_SHOT_HPP

#include <iostream>
#include "Entity.hpp"

class Shot : public Entity
{

public:

    Shot(const std::string &, const float, const float, const float, const float, const int);
    virtual ~Shot(){}

    void    draw(sf::RenderWindow &);
    void    update();
    const   bool    doShot(){return true;};

private:

    float       _fr;
    int         _type;
    sf::Clock   _clock;

};

#endif //CPP_RTYPE_SHOT_HPP
