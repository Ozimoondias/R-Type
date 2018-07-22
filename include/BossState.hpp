//
// Created by agar on 16/02/18.
//

#ifndef CPP_RTYPE_BOSSSTATE_HPP
#define CPP_RTYPE_BOSSSTATE_HPP

#include    "StateManager.hpp"

class   BossState : public IState
{

public:

    BossState(StateManager &);
    virtual ~BossState(){}

    void        event(sf::Event &);
    void        update(sf::Time &);
    void        render();

private:

    sf::Texture     mTexture;
    sf::Sprite      mBackgroundSprite;

    StateManager    &stateManager;

};

#endif //CPP_RTYPE_BOSSSTATE_HPP
