//
// Created by agar on 21/02/18.
//

#include "CoreManager.hpp"
#include "MeteorState.hpp"

MeteorState::MeteorState(StateManager &manager)
        : stateManager(manager)
{
    _clock.restart();
}

void    MeteorState::update(sf::Time &dt)
{
    stateManager.getCoreManager().entityManager.updateMap();
    stateManager.getCoreManager().entityManager.updateEnemyShot();
    stateManager.getCoreManager().entityManager.updatePlayerShot();
    stateManager.getCoreManager().entityManager.updateBonus();
    stateManager.getCoreManager().entityManager.updateEnemy();
    stateManager.getCoreManager().entityManager.updatePlayer();
    stateManager.getCoreManager().graphicsManager.getBoarder(
            stateManager.getCoreManager().entityManager.getPlayer()[0]->getSprite());
}

void    MeteorState::render()
{
    stateManager.getCoreManager().entityManager.drawMap();
    stateManager.getCoreManager().entityManager.drawEnemyShot();
    stateManager.getCoreManager().entityManager.drawPlayerShot();
    stateManager.getCoreManager().entityManager.drawBonus();
    stateManager.getCoreManager().entityManager.drawEnemy();
    stateManager.getCoreManager().entityManager.drawPlayer();
    if (_clock.getElapsedTime().asSeconds() >= 0.3)
    {
        stateManager.getCoreManager().entityManager.addMeteor();
        _clock.restart();
    }
    else if (stateManager.getCoreManager().entityManager.getPlayer()[0]->getScore() >= 100)
        stateManager.changeState(StateManager::MENU);
}

void    MeteorState::event(sf::Event &evt)
{
    if (evt.type == sf::Event::KeyPressed)
        if (evt.key.code == sf::Keyboard::Escape)
            stateManager.changeState(StateManager::PAUSE);
        else if (evt.key.code == sf::Keyboard::Return)
            stateManager.getCoreManager().entityManager.addPlayerShot();
}
