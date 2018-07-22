//
// Created by agar on 24/01/18.
//

#include "MeteorState.hpp"
#include "BossState.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"
#include "IntroState.hpp"
#include "OverState.hpp"
#include "SelectState.hpp"
#include "PauseState.hpp"

#include "CoreManager.hpp"

StateManager::StateManager(CoreManager &manager)
        :   coreManager(manager)
{
    _alive = true;
    _clock.restart();
    current_state = StateManager::States::MENU;
    state.push_back(std::unique_ptr<IState>(new MenuState(*this)));
}

bool        StateManager::getAlive()
{
    return (_alive);
}

void        StateManager::setAlive(bool state)
{
    _alive = state;
}

CoreManager &StateManager::getCoreManager()
{
    return (coreManager);
}

std::list<std::unique_ptr<IState>>  &StateManager::getState()
{
    return (state);
}

StateManager::States    StateManager::getCurrentState()
{
    return (current_state);
}

void    StateManager::changeState(StateManager::States st)
{
    std::cout << "\t\tStateManager::changeState()" << std::endl;

    switch (st)
    {
        case StateManager::States::INTRO:
            state.push_back(std::unique_ptr<IState>(new IntroState(*this)));
            break;
        case StateManager::States::MENU:
            state.push_back(std::unique_ptr<IState>(new MenuState(*this)));
            break;
        case StateManager::States::SELECT:
            state.push_back(std::unique_ptr<IState>(new SelectState(*this)));
            break;
        case StateManager::States::GAME:
            state.push_back(std::unique_ptr<IState>(new GameState(*this)));
            break;
        case StateManager::States::OVER:
            state.push_back(std::unique_ptr<IState>(new OverState(*this)));
            break;
        case StateManager::States::PAUSE:
            state.push_back(std::unique_ptr<IState>(new PauseState(*this)));
            break;
        case StateManager::States::BOSS:
            state.push_back(std::unique_ptr<IState>(new BossState(*this)));
            break;
        case StateManager::States::METEOR:
            state.push_back(std::unique_ptr<IState>(new MeteorState(*this)));
            break;
        default:
            state.push_back(std::unique_ptr<IState>(new MenuState(*this)));
            break;
    }
    state.pop_front();
    current_state = st;
}
