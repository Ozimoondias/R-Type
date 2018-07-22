//
// Created by agar on 25/01/18.
//

#ifndef CPP_RTYPE_INTROSTATE_HPP
#define CPP_RTYPE_INTROSTATE_HPP

#include    "StateManager.hpp"

class   IntroState : public IState
{

public:

    IntroState(StateManager &);
    virtual ~IntroState(){}

    void        event(sf::Event &);
    void        update(sf::Time &);
    void        render();

private:

    sf::Texture mTexture;
    sf::Sprite  mBackgroundSprite;

    StateManager    &stateManager;

};

#endif //CPP_RTYPE_INTROSTATE_HPP
