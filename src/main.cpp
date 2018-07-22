#include    <iostream>

#include    "CoreManager.hpp"

int         main()
{
    CoreManager
            manager;

    manager.init();
    manager.gameloop();
    manager.quit();

    return 0;
}