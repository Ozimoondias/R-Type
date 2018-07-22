#ifndef CPP_RTYPE_METEORS_HPP
#define CPP_RTYPE_METEORS_HPP

#include "Entity.hpp"
#include "Enemy.hpp"

class   Meteors : public Entity
{

public:
  Meteors(const std::string &, const float, const float, const float, const int);
  virtual ~Meteors(){}

  void		draw(sf::RenderWindow &);
  void		update();

  void		doPattern();
  void		setPattern(const std::string &);
  const bool	doShot();

  void		firstPattern();
  void		secondPattern();
  void		thirdPattern();
  void		fourthPattern();
  void		fifthPattern();

private:

  sf::Clock   _clock;
  sf::Clock   _clockShot;
  sf::Clock   _clockPattern;

  sf::Text            text;
  sf::Font            font;

  int                     pi;
  std::vector<Pattern>    directions;
};

#endif //CPP_RTYPE_METEORS_HPP
