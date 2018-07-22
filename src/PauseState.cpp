//
// Created by agar on 13/02/18.
//

#include "CoreManager.hpp"
#include "PauseState.hpp"

PauseState::PauseState(StateManager &manager)
        : stateManager(manager)
{
    i = 1;
}

void    PauseState::update(sf::Time &dt)
{
}

void    PauseState::CheckButton()
{
    switch (i)
    {
        case 1:
            stateManager.changeState(StateManager::GAME);
            break;
        case 2:
            stateManager.changeState(StateManager::MENU);
            break;
        case 3:
            stateManager.setAlive(false);
            break;
    }
}

void    PauseState::render()
{
    stateManager.getCoreManager().entityManager.drawMap();
    stateManager.getCoreManager().entityManager.drawEnemyShot();
    stateManager.getCoreManager().entityManager.drawPlayerShot();
    stateManager.getCoreManager().entityManager.drawEnemy();
    stateManager.getCoreManager().entityManager.drawPlayer();
    stateManager.getCoreManager().entityManager.shader.setUniform("time", stateManager._clock.getElapsedTime().asSeconds());
    stateManager.getCoreManager().entityManager.updateButtonPause(i);
    stateManager.getCoreManager().entityManager.drawButtonPause(i);
}

void    PauseState::event(sf::Event &evt)
{
    if (evt.type == sf::Event::KeyPressed)
    {
        if (evt.key.code == sf::Keyboard::S) {
            if (i != 3)
                i += 1;
        }
        else if (evt.key.code == sf::Keyboard::Z) {
            if (i != 1)
                i -= 1;
        }
        else if (evt.key.code == sf::Keyboard::Return)
            CheckButton();
    }
}
