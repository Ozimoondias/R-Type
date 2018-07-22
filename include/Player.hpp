//
// Created by agar on 27/01/18.
//

#ifndef CPP_RTYPE_PLAYER_HPP
#define CPP_RTYPE_PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity
{

public:

    Player(const std::string &, const float, const float, const float, const int);
    virtual ~Player(){}

    void    setShot(const int);

    void    draw(sf::RenderWindow &);
    void    update();
	const   bool    doShot(){return true;};

private:

    sf::IntRect         rect;

    sf::Text            textpv;
    sf::Text            textscore;

    sf::Font            font;

};

#endif //CPP_RTYPE_PLAYER_HPP
