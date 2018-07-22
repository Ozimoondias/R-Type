//
// Created by agar on 21/02/18.
//

#ifndef CPP_RTYPE_SOUND_HPP
#define CPP_RTYPE_SOUND_HPP

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class Sound
{

public:

    Sound(const std::string &);
    virtual ~Sound(){}

    void    Play();
    void    Stop();
    bool    Run();

private:

    sf::Sound       _sound;
    sf::SoundBuffer _buff;

};

#endif //CPP_RTYPE_SOUND_HPP
