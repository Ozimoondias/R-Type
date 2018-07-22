//
// Created by agar on 24/01/18.
//

#include "NetworkManager.hpp"

NetworkManager::NetworkManager(CoreManager &manager)
        :   coreManager(manager)
{
}

CoreManager &NetworkManager::getCoreManager()
{
    return (coreManager);
}