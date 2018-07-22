//
// Created by agar on 25/01/18.
//

#include "CoreManager.hpp"
#include "IntroState.hpp"

IntroState::IntroState(StateManager &manager)
        : stateManager(manager)
{
  mTexture.loadFromFile("../media/INTRO.png");
  mBackgroundSprite.setTexture(mTexture);
}

void    IntroState::update(sf::Time &dt)
{
}

void    IntroState::render()
{
    stateManager.getCoreManager().graphicsManager.draw(mBackgroundSprite);
}

void    IntroState::event(sf::Event &evt)
{
    if (evt.type == sf::Event::KeyPressed)
        if (evt.key.code == sf::Keyboard::Escape)
            stateManager.setAlive(false);
        else if (evt.key.code == sf::Keyboard::Return)
            stateManager.changeState(StateManager::MENU);
}
