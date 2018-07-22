//
// Created by agar on 16/02/18.
//

#include "CoreManager.hpp"
#include "SelectState.hpp"

SelectState::SelectState(StateManager &manager)
        : stateManager(manager)
{
    i = 0;

    mTexture.loadFromFile("../media/playerSolo1.png");
    mBackgroundSprite.setTexture(mTexture);
    mBackgroundSprite.setOrigin(40, 30);
    mBackgroundSprite.setPosition(655, 540);

    mTexture2.loadFromFile("../media/SELECT.png");
    mBackgroundSprite2.setTexture(mTexture2);

    stateManager.getCoreManager().entityManager.getBack().getText().setCharacterSize(150);
    stateManager.getCoreManager().entityManager.getBack().getText().setPosition(
            ((1920/2) - stateManager.getCoreManager().entityManager.getBack().getText().getGlobalBounds().width / 2), 50);
}

void    SelectState::update(sf::Time &dt)
{
    mBackgroundSprite.rotate(1);
}

void    SelectState::check()
{
    switch (i)
    {
        case 0:
            mTexture.loadFromFile("../media/playerSolo1.png");
            break;
        case 1:
            mTexture.loadFromFile("../media/playerSolo2.png");
            break;
        case 2:
            mTexture.loadFromFile("../media/playerSolo3.png");
            break;
    }
    mBackgroundSprite.setTexture(mTexture);
}

void    SelectState::CheckButton()
{
    switch (i)
    {
        case 0:
            stateManager.getCoreManager().entityManager.addPlayer("../media/playerSolo1.png", 12, 5);
            break;
        case 1:
            stateManager.getCoreManager().entityManager.addPlayer("../media/playerSolo2.png", 5, 10);
            break;
        case 2:
            stateManager.getCoreManager().entityManager.addPlayer("../media/playerSolo3.png", 8, 20);
            break;
    }
    stateManager.changeState(StateManager::GAME);
}

void    SelectState::render()
{
    stateManager.getCoreManager().entityManager.drawBack();
    stateManager.getCoreManager().graphicsManager.draw(mBackgroundSprite2);
    stateManager.getCoreManager().graphicsManager.draw(mBackgroundSprite);
    stateManager.getCoreManager().entityManager.shader.setUniform("time", stateManager._clock.getElapsedTime().asSeconds() * 2);
    stateManager.getCoreManager().entityManager.drawButtonSelect(i);
}

void    SelectState::event(sf::Event &evt)
{
    if (evt.type == sf::Event::KeyPressed)
        if (evt.key.code == sf::Keyboard::D) {
            if (i != 2)
                i += 1;
            check();
        }
        else if (evt.key.code == sf::Keyboard::Q) {
            if (i != 0)
                i -= 1;
            check();
        }
        else if (evt.key.code == sf::Keyboard::Escape)
            stateManager.changeState(StateManager::MENU);
        else if (evt.key.code == sf::Keyboard::Return)
            CheckButton();
}
