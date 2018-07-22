//
// Created by agar on 12/02/18.
//

#ifndef CPP_RTYPE_OVERSTATE_HPP
#define CPP_RTYPE_OVERSTATE_HPP

#include "StateManager.hpp"

class   OverState : public IState
{

public:

    OverState(StateManager &);
    virtual ~OverState(){}

    void        event(sf::Event &);
    void        update(sf::Time &);
    void        render();

private:

    sf::Texture     mTexture;
    sf::Sprite      mBackgroundSprite;

    StateManager    &stateManager;

};

#endif //CPP_RTYPE_OVERSTATE_HPP
