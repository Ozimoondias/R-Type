//
// Created by agar on 16/02/18.
//

#include "CoreManager.hpp"
#include "BossState.hpp"

BossState::BossState(StateManager &manager)
        : stateManager(manager)
{
    stateManager.getCoreManager().entityManager.getPlayerShot().clear();
    stateManager.getCoreManager().entityManager.getEnemy().clear();
    stateManager.getCoreManager().entityManager.getEnemyShot().clear();
    stateManager.getCoreManager().entityManager.addBoss();
}

void    BossState::update(sf::Time &dt)
{
    stateManager.getCoreManager().entityManager.updateMap();
    stateManager.getCoreManager().entityManager.updateEnemyShot();
    stateManager.getCoreManager().entityManager.updatePlayerShot();
    stateManager.getCoreManager().entityManager.updateEnemy();
    stateManager.getCoreManager().entityManager.updatePlayer();
    stateManager.getCoreManager().graphicsManager.getBoarder(
            stateManager.getCoreManager().entityManager.getPlayer()[0]->getSprite());
}

void    BossState::render()
{
    stateManager.getCoreManager().entityManager.drawMap();
    stateManager.getCoreManager().entityManager.drawEnemyShot();
    stateManager.getCoreManager().entityManager.drawPlayerShot();
    stateManager.getCoreManager().entityManager.drawEnemy();
    stateManager.getCoreManager().entityManager.drawPlayer();
}

void    BossState::event(sf::Event &evt)
{
    if (evt.type == sf::Event::KeyPressed)
        if (evt.key.code == sf::Keyboard::Escape)
            stateManager.changeState(StateManager::PAUSE);
        else if (evt.key.code == sf::Keyboard::Return)
            stateManager.getCoreManager().entityManager.addPlayerShot();
}