//
// Created by agar on 21/02/18.
//

#include "Sound.hpp"

Sound::Sound(const std::string &str)
{
    _buff.loadFromFile(str);
    _sound.setBuffer(_buff);
}

void    Sound::Play()
{
    _sound.play();
}

void    Sound::Stop()
{
    _sound.stop();
}

bool    Sound::Run()
{
    if (_sound.getStatus() == sf::Sound::Playing)
        return (true);
    return (false);
}