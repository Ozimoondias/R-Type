//
// Created by agar on 24/01/18.
//

#ifndef CPP_RTYPE_STATEMANAGER_HPP
#define CPP_RTYPE_STATEMANAGER_HPP

#include "IState.hpp"

#include <list>
#include <memory>
#include <iostream>

class StateManager
{

public:

    enum    States
    {
        NONE,
        INTRO,
        TITLE,
        MENU,
        BOSS,
        NETHUB,
        SELECT,
        PLAYER1,
        METEOR,
        GAME,
        GAME2,
        NETGAME,
        OVER,
        PAUSE
    };

    CoreManager &getCoreManager();

    StateManager(CoreManager &);
    virtual ~StateManager(){}

    bool    getAlive();
    void    setAlive(bool);

    States  getCurrentState();
    void    changeState(StateManager::States);

    std::list<std::unique_ptr<IState>>  &getState();

    sf::Clock               _clock;

private:

    bool                    _alive;
    StateManager::States    current_state;
    std::list<std::unique_ptr<IState>>  state;

    CoreManager &coreManager;

};

#endif //CPP_RTYPE_STATEMANAGER_HPP
