//
// Created by agar on 24/01/18.
//

#ifndef CPP_RTYPE_COREMANAGER_HPP
#define CPP_RTYPE_COREMANAGER_HPP

#include "EntityManager.hpp"
#include "NetworkManager.hpp"
#include "StateManager.hpp"
#include "GraphicsManager.hpp"

class CoreManager
{

public:

    CoreManager();
    virtual ~CoreManager(){}

    void init();
    void reset();
    void gameloop();
    void quit();

    EntityManager   entityManager;
    NetworkManager  networkManager;
    StateManager    stateManager;
    GraphicsManager graphicsManager;

};

#endif //CPP_RTYPE_COREMANAGER_HPP
