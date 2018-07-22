//
// Created by agar on 25/01/18.
//

#include "CoreManager.hpp"
#include "GameState.hpp"

GameState::GameState(StateManager &manager)
        : stateManager(manager)
{
    _clock.restart();
}

void    GameState::update(sf::Time &dt)
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

void    GameState::render()
{
    stateManager.getCoreManager().entityManager.drawMap();
    stateManager.getCoreManager().entityManager.drawEnemyShot();
    stateManager.getCoreManager().entityManager.drawPlayerShot();
    stateManager.getCoreManager().entityManager.drawBonus();
    stateManager.getCoreManager().entityManager.drawEnemy();
    stateManager.getCoreManager().entityManager.drawPlayer();
    if (_clock.getElapsedTime().asSeconds() >= 1)
    {
        stateManager.getCoreManager().entityManager.addEnemy();
        _clock.restart();
    }
    else if (stateManager.getCoreManager().entityManager.getPlayer()[0]->getScore() >= 25)
    {
        stateManager.getCoreManager().entityManager.addBoss();
        stateManager.changeState(StateManager::METEOR);
    }
}

void    GameState::event(sf::Event &evt)
{
    if (evt.type == sf::Event::KeyPressed)
        if (evt.key.code == sf::Keyboard::Escape)
            stateManager.changeState(StateManager::PAUSE);
        else if (evt.key.code == sf::Keyboard::Return)
            stateManager.getCoreManager().entityManager.addPlayerShot();
}
