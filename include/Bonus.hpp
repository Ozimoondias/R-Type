//
// Created by agar on 20/02/18.
//

#ifndef CPP_RTYPE_BONUS_HPP
#define CPP_RTYPE_BONUS_HPP

#include "Entity.hpp"

class Bonus : public Entity
{

public:

    Bonus(const std::string &, const float, const float, const int);
    virtual ~Bonus(){}

    bool    getBonus(std::unique_ptr<Entity> &);

    void    draw(sf::RenderWindow &);
    void    update();
	const   bool    doShot(){return true;};

private:

    int                 _type;

    sf::IntRect         rect;

};

#endif //CPP_RTYPE_BONUS_HPP
