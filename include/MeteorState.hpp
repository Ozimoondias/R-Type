//
// Created by agar on 21/02/18.
//

#ifndef CPP_RTYPE_METEORSTATE_HPP
#define CPP_RTYPE_METEORSTATE_HPP

#include    "StateManager.hpp"

class   MeteorState : public IState
{

public:

    MeteorState(StateManager &);
    virtual ~MeteorState(){}

    void        event(sf::Event &);
    void        update(sf::Time &);
    void        render();

private:

    sf::Clock   _clock;

    sf::Texture     mTexture;
    sf::Sprite      mBackgroundSprite;

    StateManager    &stateManager;

};

#endif //CPP_RTYPE_METEORSTATE_HPP
