//
// Created by agar on 24/01/18.
//

#ifndef CPP_RTYPE_NETWORKMANAGER_HPP
#define CPP_RTYPE_NETWORKMANAGER_HPP

class CoreManager;

#include <map>
#include <memory>
#include <iostream>

class NetworkManager
{

public:

    CoreManager &getCoreManager();

    NetworkManager(CoreManager &);
    virtual ~NetworkManager(){}

    void print(){std::cout << "NetworkManager" << std::endl;}

private:

    CoreManager &coreManager;

};

#endif //CPP_RTYPE_NETWORKMANAGER_HPP
