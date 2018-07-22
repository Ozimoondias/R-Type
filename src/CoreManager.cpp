//
// Created by agar on 24/01/18.
//

#include "CoreManager.hpp"

CoreManager::CoreManager()
        :   entityManager(*this),
            graphicsManager(*this),
            networkManager(*this),
            stateManager(*this)
{
    srand(time(NULL));
}

void CoreManager::init()
{
    std::cout << "\nCoreManager::init()" << std::endl;

    graphicsManager.init();
}

void CoreManager::gameloop()
{
    std::cout << "CoreManager::gameloop()" << std::endl;

    graphicsManager.gameloop();
}

void CoreManager::quit()
{
    std::cout << "CoreManager::quit()" << std::endl;
}