//
// Created by agar on 13/02/18.
//

#ifndef CPP_RTYPE_MAP_HPP
#define CPP_RTYPE_MAP_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Back
{
public:

    Back();
    virtual ~Back(){}

    void    draw(sf::RenderWindow &, sf::Shader &);
    void    update();

    sf::Text    &getText();

private:

    sf::Text        text;
    sf::Font        font;

    sf::Texture     mTexture;
    sf::Sprite      mBackgroundSprite;

};

class Map
{

public:

    Map();
    virtual ~Map(){}

    void    draw(sf::RenderWindow &);
    void    update();

private:

    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;

    sf::Sprite  sprite1;
    sf::Sprite  sprite2;
    sf::Sprite  sprite3;

};

#endif //CPP_RTYPE_MAP_HPP
