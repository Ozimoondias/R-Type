//
// Created by agar on 13/02/18.
//

#ifndef CPP_RTYPE_PAUSESTATE_HPP
#define CPP_RTYPE_PAUSESTATE_HPP

#include "StateManager.hpp"

class   PauseState : public IState
{

public:

    PauseState(StateManager &);
    virtual ~PauseState(){}

    void        CheckButton();

    void        event(sf::Event &);
    void        update(sf::Time &);
    void        render();

private:

    int             i;

    StateManager    &stateManager;

};

#endif //CPP_RTYPE_PAUSESTATE_HPP
