//
// Created by agar on 13/02/18.
//

#include "Map.hpp"

Back::Back()
{
    font.loadFromFile("../media/Neoneon.otf");
    text.setFont(font);
    text.setString("R-TYPE");
    text.setFillColor(sf::Color::Magenta);

    mTexture.loadFromFile("../media/radpack_4.jpg");
    mBackgroundSprite.setTexture(mTexture);
    mBackgroundSprite.setPosition(0, -50);
}

void Back::draw(sf::RenderWindow &window, sf::Shader &shader)
{
    window.draw(mBackgroundSprite, &shader);
    window.draw(text);
}

sf::Text    &Back::getText()
{
    return (text);
}

void Back::update()
{

}

Map::Map()
{
    if (!texture2.loadFromFile("../media/Back.png"))
        throw std::logic_error("/media/222.png not found !");
    sprite2.setTexture(texture2);

    /*if (!texture3.loadFromFile("../media/back2.png"))
        throw std::logic_error("/media/111.png not found !");
    sprite3.setTexture(texture3);*/
}

void    Map::update()
{
    if (sprite2.getPosition().x > -3840)
        sprite2.move(-2, 0);
    else
        sprite2.setPosition(sprite3.getOrigin());
}

void    Map::draw(sf::RenderWindow &window)
{
    window.draw(sprite2);
    //window.draw(sprite3);
}
