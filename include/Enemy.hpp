//
// Created by agar on 27/01/18.
//

#ifndef CPP_RTYPE_ENEMY_HPP
#define CPP_RTYPE_ENEMY_HPP

#include "Entity.hpp"

class   Pattern
{

public:

  Pattern(const float xxx, const float yyy, const float zzz, const float speed)
    : x(xxx), y(yyy), fr(zzz), sp(speed){}
    virtual ~Pattern(){}

  const float getx(){return(x);}
  const float gety(){return(y);}
  const float getfr(){return(fr);}
  const float getsp(){return(sp);}

private:

  float x;
  float y;
  float fr;
  float	sp;

};

class   Enemy : public Entity
{

public:
  Enemy(const std::string &, const float, const float, const float, const int, const int);
  virtual ~Enemy(){}

  void		draw(sf::RenderWindow &);
  void		update();

  void		doPattern();
  void		setPattern(const std::string &);
  const bool	doShot();

    void    setEnemyPattern();
    void    setEscadronPattern();
    void    setMeteorPattern();

    void    EscPattern1();
    void    EscPattern2();
    void    EscPattern3();

    void    MeteorPattern1();
    void    MeteorPattern2();
    void    MeteorPattern3();

    void		firstPattern();
    void		secondPattern();
    void		thirdPattern();
    void		fourthPattern();
    void		fifthPattern();

private:

    int         whitch;

    sf::Clock   _clock;
    sf::Clock   _clockShot;
    sf::Clock   _clockPattern;

    int                     pi;
    std::vector<Pattern>    directions;

};

#endif //CPP_RTYPE_ENEMY_HPP
