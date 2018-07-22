//
// Created by agar on 19/01/18.
//

#ifndef CPP_RTYPE_GAMESTATE_HPP
#define CPP_RTYPE_GAMESTATE_HPP

#include "StateManager.hpp"

class   GameState : public IState
{

public:

    GameState(StateManager &);
    virtual ~GameState(){}

    void        event(sf::Event &);
    void        update(sf::Time &);
    void        render();

private:

    sf::Clock   _clock;
    sf::Texture mTexture;
    sf::Sprite  mBackgroundSprite;

    StateManager    &stateManager;

};

#endif //CPP_RTYPE_GAMESTATE_HPP
