//
// Created by agar on 19/01/18.
//

#ifndef CPP_RTYPE_MENUSTATE_HPP
#define CPP_RTYPE_MENUSTATE_HPP

#include "StateManager.hpp"

class   MenuState : public IState
{

public:

    MenuState(StateManager &);
    virtual ~MenuState(){}

    void        CheckButton();

    void        event(sf::Event &);
    void        update(sf::Time &);
    void        render();

private:

    int             i;

    StateManager    &stateManager;

};

#endif //CPP_RTYPE_MENUSTATE_HPP
