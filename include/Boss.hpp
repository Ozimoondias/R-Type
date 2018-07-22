#ifndef _BOSS_HPP_
# define _BOSS_HPP_

#include "Entity.hpp"

class				Boss : public Entity
{
private:
  sf::CircleShape		chomp;
  sf::CircleShape		first_meteor;
  sf::CircleShape		second_meteor;
  sf::CircleShape		third_meteor;
  int				attack_y;
  int				attack_x;
  int				up_down_attack;
  sf::Clock			clock;
  int				life;
  int				zone;
  sf::Transform			transform1;
  sf::Transform			transform2;
  sf::Transform			transform3;
  int				linking_one_two;
  int				berserk_mode;
  std::vector<sf::CircleShape>	boss_circles; // [0]==boss;[1]==first_meteor[2]==sec_met[3]

  enum class			Etat : unsigned int
    {
      attack = 0,
      up = 1,
      down = 2,
      comeback = 3
    };

public:
  Boss(std::unique_ptr<Entity> &);
  virtual ~Boss(){}
  int				getAttackX() { return (this->attack_x); }
  int				getAttackY() { return (this->attack_y); }
  sf::CircleShape&		GetChomp() { return (this->chomp); }
  sf::CircleShape&		GetFirstMeteorite() { return (this->first_meteor); }
  sf::CircleShape&		GetSecondMeteorite() { return (this->second_meteor); }
  sf::CircleShape&		GetThirdMeteorite() { return (this->third_meteor); }
  //void                  FirstPattern(Player player);
  void				FirstPattern();
  void				SecondPattern();
  int				Attack();
  int				ComingBack();
  int				GetPosX();
  int				GetPosY();
  int				Which_Zone() const;
  //bool                  checkColl(Bullet bullet);
  int				GetEtat() { return this->up_down_attack; }
  void				takeDamages() { this->life--; }
  int				GetLife() { return this->life; }
  sf::Transform&		GetFirstTransform() { return this->transform1; }
  sf::Transform&		GetSecondTransform() { return this->transform2; }
  sf::Transform&		GetThirdTransform() { return this->transform3; }
  void				MeteoriteStrike();
  void				Link_Patterns();
  const std::vector<sf::CircleShape>	GetBossCircles() { return this->boss_circles; }

  void				draw(sf::RenderWindow &);
  void				update();
  const bool			doShot();

    int bite;

};

#endif /* _BOSS_HPP_ */
