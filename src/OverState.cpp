//
// Created by agar on 12/02/18.
//

#include "CoreManager.hpp"
#include "OverState.hpp"

OverState::OverState(StateManager &manager)
        : stateManager(manager)
{
    mTexture.loadFromFile("../media/GAMEOVER.jpg");
    mBackgroundSprite.setTexture(mTexture);
}

void    OverState::update(sf::Time &dt)
{
}

void    OverState::render()
{
    stateManager.getCoreManager().graphicsManager.draw(mBackgroundSprite);
}

void    OverState::event(sf::Event &evt)
{
    if (evt.type == sf::Event::KeyPressed)
        stateManager.changeState(StateManager::MENU);
}