//
// Created by agar on 25/01/18.
//

#ifndef CPP_RTYPE_GRAPHICSMANAGER_HPP
#define CPP_RTYPE_GRAPHICSMANAGER_HPP

class CoreManager;

#include <map>
#include <thread>
#include <iostream>
#include <functional>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GraphicsManager
{

public:

    CoreManager &getCoreManager();

    GraphicsManager(CoreManager &);
    virtual ~GraphicsManager(){}

    void    init();
    void    event();
    void    update(sf::Time &);
    void    render();
    void    gameloop();
    void    draw(sf::Text &);
    void    draw(sf::Text &, sf::Shader &);
    void    draw(sf::Sprite &);
    void    draw(sf::Sprite &, sf::Shader &);
    void    updateStatistics(sf::Time &);
    void    getBoarder(sf::Sprite &);

    sf::RenderWindow    &getwindow();

private:

    sf::Text            text;
    sf::Font            font;
    sf::Time            upTime;
    std::size_t         nbFrame;

    sf::RenderWindow    _window;

    CoreManager         &coreManager;

};

#endif //CPP_RTYPE_GRAPHICSMANAGER_HPP
