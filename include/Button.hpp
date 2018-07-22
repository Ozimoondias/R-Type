//
// Created by agar on 15/02/18.
//

#ifndef CPP_RTYPE_BUTTON_HPP
#define CPP_RTYPE_BUTTON_HPP

#include "Entity.hpp"

class   Button : public Entity
{

public:

    Button(const std::string &, const float, const float);
    virtual ~Button(){}

    void draw(sf::RenderWindow &);
    void update();
    const bool doShot();

private:

};

#endif //CPP_RTYPE_BUTTON_HPP
