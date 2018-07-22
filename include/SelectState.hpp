//
// Created by agar on 13/02/18.
//

#ifndef CPP_RTYPE_SELECTSTATE_HPP
#define CPP_RTYPE_SELECTSTATE_HPP

#include "StateManager.hpp"

class   SelectState : public IState
{

public:

    SelectState(StateManager &);
    virtual ~SelectState(){}

    void        check();
    void        CheckButton();

    void        event(sf::Event &);
    void        update(sf::Time &);
    void        render();

private:

    int             i;

    sf::Texture     mTexture;
    sf::Sprite      mBackgroundSprite;

    sf::Texture     mTexture2;
    sf::Sprite      mBackgroundSprite2;

    StateManager    &stateManager;

};

#endif //CPP_RTYPE_SELECTSTATE_HPP
