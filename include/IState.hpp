//
// Created by agar on 24/01/18.
//

#ifndef CPP_RTYPE_ISTATE_HPP
#define CPP_RTYPE_ISTATE_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class CoreManager;

class IState
{

public:

    virtual void event(sf::Event &) = 0;
    virtual void update(sf::Time &) = 0;
    virtual void render() = 0;

};

#endif //CPP_RTYPE_ISTATE_HPP
