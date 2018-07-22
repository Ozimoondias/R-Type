//
// Created by agar on 25/01/18.
//

#include "CoreManager.hpp"

GraphicsManager::GraphicsManager(CoreManager &manager)
        :   coreManager(manager)
{
}

CoreManager &GraphicsManager::getCoreManager()
{
    return (coreManager);
}

void    GraphicsManager::draw(sf::Text &sprite)
{
    _window.draw(sprite);
}

void    GraphicsManager::draw(sf::Text &sprite, sf::Shader &shader)
{
    _window.draw(sprite, &shader);
}

void    GraphicsManager::draw(sf::Sprite &sprite)
{
    _window.draw(sprite);
}

void    GraphicsManager::draw(sf::Sprite &sprite, sf::Shader &shader)
{
    _window.draw(sprite, &shader);
}

void    GraphicsManager::getBoarder(sf::Sprite &sprite)
{
    const float borderDistance = 10.f;
    sf::FloatRect viewBounds(_window.getDefaultView().getCenter() - _window.getDefaultView().getSize() / 2.f, _window.getDefaultView().getSize());
    sf::Vector2f position = sprite.getPosition();
    position.x = std::max(position.x, viewBounds.left + borderDistance);
    position.x = std::min(position.x, viewBounds.left + viewBounds.width - (borderDistance + sprite.getGlobalBounds().width));
    position.y = std::max(position.y, viewBounds.top + borderDistance);
    position.y = std::min(position.y, viewBounds.top + viewBounds.height - (borderDistance + sprite.getGlobalBounds().height));
    sprite.setPosition(position);
}

void    GraphicsManager::init()
{
    std::cout << "\tGraphicsManager::init()" << std::endl;

    nbFrame = 0;
    upTime = sf::Time::Zero;

    _window.create(sf::VideoMode(1920, 1080), "R-Type 2018", sf::Style::Fullscreen);
    _window.setVerticalSyncEnabled(true);
    _window.setMouseCursorVisible(false);
    _window.setKeyRepeatEnabled(false);
    _window.setFramerateLimit(60);

    font.loadFromFile("../media/Neoneon.otf");
    text.setFont(font);
    text.setPosition(5.f, 5.f);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Magenta);
}

void    GraphicsManager::event()
{
    sf::Event   event;

    while (_window.pollEvent(event))
    {
        coreManager.stateManager.getState().front()->event(event);
        if (event.type == sf::Event::Closed)
            _window.close();
    }
}

void    GraphicsManager::update(sf::Time &dt)
{
    coreManager.stateManager.getState().front()->update(dt);
    updateStatistics(dt);
}

void    GraphicsManager::render()
{
    _window.clear(sf::Color::Black);
    coreManager.stateManager.getState().front()->render();
    _window.draw(text);
    _window.setView(_window.getDefaultView());
    _window.display();
}

void    GraphicsManager::updateStatistics(sf::Time &dt)
{
    upTime += dt;
    nbFrame += 1;
    if (upTime >= sf::seconds(1.0f))
    {
        text.setString(" FPS " + std::to_string(nbFrame));
        upTime -= sf::seconds(1.0f);
        nbFrame = 0;
    }
}

void    GraphicsManager::gameloop()
{
    std::cout << "\tGraphicsManager::gameloop()" << std::endl;

    sf::Time    dt;
    sf::Clock   clock;
    sf::Time    timeSinceLastUpdate = sf::Time::Zero;
    sf::Time    TimePerFrame = sf::seconds(1.f/60.f);

    while (_window.isOpen())
    {
        dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            event();
            update(dt);
            if (!coreManager.stateManager.getAlive())
                _window.close();
        }
        render();
    }
}

sf::RenderWindow    &GraphicsManager::getwindow()
{
    return (_window);
}