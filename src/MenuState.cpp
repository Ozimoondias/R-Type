//
// Created by agar on 25/01/18.
//

#include "CoreManager.hpp"
#include "MenuState.hpp"

MenuState::MenuState(StateManager &manager)
        : stateManager(manager)
{
    i = 0;
    stateManager.getCoreManager().entityManager.getBoss().clear();
    stateManager.getCoreManager().entityManager.getBonus().clear();
    stateManager.getCoreManager().entityManager.getPlayer().clear();
    stateManager.getCoreManager().entityManager.getPlayerShot().clear();
    stateManager.getCoreManager().entityManager.getEnemy().clear();
    stateManager.getCoreManager().entityManager.getEnemyShot().clear();
    stateManager.getCoreManager().entityManager.getBack().getText().setCharacterSize(300);
    stateManager.getCoreManager().entityManager.getBack().getText().setPosition(
            ((1920/2) - stateManager.getCoreManager().entityManager.getBack().getText().getGlobalBounds().width / 2), 30);
}

void    MenuState::update(sf::Time &dt)
{
}

void    MenuState::CheckButton()
{
    switch (i)
    {
        case 0:
            stateManager.changeState(StateManager::SELECT);
            break;
        case 1:
            break;
        case 2:
            stateManager.setAlive(false);
            break;
    }
}

void    MenuState::render()
{
    stateManager.getCoreManager().entityManager.drawBack();
    stateManager.getCoreManager().entityManager.shader.setUniform("time", stateManager._clock.getElapsedTime().asSeconds());
    stateManager.getCoreManager().entityManager.updateButtonMenu(i);
    stateManager.getCoreManager().entityManager.drawButtonMenu(i);
}

void    MenuState::event(sf::Event &evt)
{
    if (evt.type == sf::Event::KeyPressed)
    {
        if (evt.key.code == sf::Keyboard::S) {
            if (i != 2)
                i += 1;
        }
        else if (evt.key.code == sf::Keyboard::Z) {
            if (i != 0)
                i -= 1;
        }
        else if (evt.key.code == sf::Keyboard::Return)
            CheckButton();
    }
}
