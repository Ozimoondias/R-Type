#include "CoreManager.hpp"
#include "Boss.hpp"
#include "GameState.hpp"

#define BOSS_ATTACK_SPEED 4500000

Boss::Boss(std::unique_ptr<Entity> &player)
{
  chomp.setRadius(150);
  chomp.setOutlineColor(sf::Color::Red);
  chomp.setOutlineThickness(5);
  chomp.setPosition(1050, 450);

    bite = false;

  chomp.setFillColor(sf::Color::Red);
  this->life = 4;

  this->berserk_mode = 1;
  this->up_down_attack = static_cast<int>(Etat::up);
  this->linking_one_two = 0;
  this->boss_circles.push_back(chomp);
}

int                     Boss::GetPosX()
{
  sf::Vector2f          posx = this->chomp.getPosition();

  return (posx.x);
}

int                     Boss::GetPosY()
{
  sf::Vector2f          posy = this->chomp.getPosition();

  return (posy.y);
}

int                     Boss::Which_Zone() const
{
  if (this->attack_y >= 0 && this->attack_y < 250)
    return 1;
  if (this->attack_y >= 250 && this->attack_y <= 550) // zone 2 milieu
    return 2;
  if (this->attack_y <= 800 && this->attack_y > 550) // zone 3 bas
    return 3;
  return 0;
}

int                     Boss::ComingBack()
{
  int                   onplayer = 0;
  sf::Vector2f          pos = chomp.getPosition();
  int                   tempo_life = this->life;

  this->up_down_attack = static_cast<int>(Etat::comeback);
  if (this->up_down_attack == static_cast<int>(Etat::up))
    return 0;

  if (this->zone == 1)
    {
      if (this->GetPosY() < 450 && this->GetPosX() < 1050)
        {
          this->chomp.setPosition(pos.x + 20, pos.y + 6);
          onplayer++;
        }
    }
  else if (this->zone == 2)
    {
      if (this->GetPosX() < 1050)
        {
          this->chomp.setPosition(pos.x + 20, pos.y);
          onplayer++;
        }
    }
  else if (this->zone == 3)
    {
      if (this->GetPosX() < 1050)
        {
          this->chomp.setPosition(pos.x + 20, pos.y - 6);
          onplayer++;
        }
    }
  this->life = tempo_life;
  if (onplayer == 0)
    {
      this->up_down_attack = static_cast<int>(Etat::up);
      return (0);
    }
  return (1);
}

int                     Boss::Attack()
{
  int                   onplayer = 0;
  sf::Vector2f          pos = this->chomp.getPosition();
  int           tempo_life = this->GetLife();

  if (this->up_down_attack == static_cast<int>(Etat::comeback))
    {
      return 0;
    }
  this->zone = this->Which_Zone();

  if (this->zone == 1)
    {
      if (this->GetPosX() > -100)
        {
          this->chomp.setPosition(pos.x - 20, pos.y - 6);
          onplayer++;
        }
    }
  else if (this->zone == 2)
    {
      if (this->GetPosX() > -100)
        {
          this->chomp.setPosition(pos.x - 20, pos.y);
          onplayer++;
        }
    }
  else if (this->zone == 3)
    {
      if (this->GetPosX() > -100)
        {
          this->chomp.setPosition(pos.x - 20, pos.y + 6);
          onplayer++;
        }
    }
  this->life = tempo_life;
  if (onplayer == 0)
    {
      this->up_down_attack = static_cast<int>(Etat::comeback);
      return (0);
    }
  return (1);
}

void                  Boss::MeteoriteStrike()
{
  this->first_meteor.setPosition(250, 950);
  this->first_meteor.setOrigin({200, 300});
  this->first_meteor.setRadius(100);
  this->first_meteor.setOutlineColor(sf::Color::Red);
  this->first_meteor.setOutlineThickness(5);
  this->transform1.rotate(-4.0 * this->berserk_mode, 700, 650);

  this->second_meteor.setPosition(650, 69);
  this->second_meteor.setOrigin({10, 20});
  this->second_meteor.setRadius(100);
  this->second_meteor.setOutlineColor(sf::Color::Red);
  this->second_meteor.setOutlineThickness(5);
  this->transform2.rotate(3.0 * this->berserk_mode, 500, 400);

  this->third_meteor.setPosition(350, 350);
  this->third_meteor.setOrigin({10, 20});
  this->third_meteor.setRadius(100);
  this->third_meteor.setOutlineColor(sf::Color::Red);
  this->third_meteor.setOutlineThickness(5);
  this->transform3.rotate(1.0 * this->berserk_mode, 900, 50);
}

void                    Boss::Link_Patterns()
{
  sf::Time              elapsed = this->clock.getElapsedTime();
  static int            tempo = 0;
  sf::Vector2f          pos = chomp.getPosition();

  if (pos.y <= 900)
    {
      this->chomp.setPosition(pos.x, pos.y + 4);
      return;
    }

  if (tempo % 2 == 1)
    this->chomp.setPosition(this->chomp.getPosition().x, this->chomp.getPosition().x + 3);
  else if (tempo % 3 == 0)
    this->chomp.setPosition(this->chomp.getPosition().x, this->chomp.getPosition().x - 3);
  tempo++;
  if (elapsed.asMicroseconds() >= 2500000)
    this->linking_one_two = 1;
}

void                    Boss::SecondPattern()
{
  if (this->linking_one_two == 0)
    {
      this->Link_Patterns();
      return ;
    }
  
  sf::Vector2f  pos = chomp.getPosition();
  sf::Time      elapsed = this->clock.getElapsedTime();

    if (!bite)
    {
        bite = true;
        this->boss_circles.push_back(first_meteor);
        this->boss_circles.push_back(second_meteor);
        this->boss_circles.push_back(third_meteor);
    }

  if (this->up_down_attack == static_cast<int>(Etat::up))
    {
      if (pos.y >= 600)
        this->up_down_attack = static_cast<int>(Etat::down);
      else
        chomp.setPosition(pos.x, pos.y + 3);
    }
  if (this->up_down_attack == static_cast<int>(Etat::down))
    {
      if (pos.y <= 15)
        this->up_down_attack = static_cast<int>(Etat::up);
      else
        chomp.setPosition(pos.x, pos.y - 3);
    }
  if (this->berserk_mode == 1)
    {
      if (elapsed.asMicroseconds() >= 25000000)
        {
          this->berserk_mode = this->berserk_mode * -1;
          clock.restart();
        }
    }
  this->MeteoriteStrike();
}

//void                    BossState::FirstPattern(Player player)
void                    Boss::FirstPattern()
{
  sf::Vector2f  pos = chomp.getPosition();
  sf::Time      elapsed = this->clock.getElapsedTime();

  if (elapsed.asMicroseconds() >= 6300000)
    this->clock.restart();
  if (elapsed.asMicroseconds() >= BOSS_ATTACK_SPEED && elapsed.asMicroseconds() <= 5500000
      && up_down_attack != static_cast<int>(Etat::attack) && pos.y >= 300 && pos.y <= 340)
    {
      //this->attack_x = player.GetPosX();
      //this->attack_y = player.GetPosY();
      this->attack_x = 600;
      this->attack_y = 600;
      this->up_down_attack = static_cast<int>(Etat::attack);
    }
  if (up_down_attack == static_cast<int>(Etat::attack) ||
      up_down_attack == static_cast<int>(Etat::comeback))
    {
      if (this->Attack() == 1)
        return;
      if (this->ComingBack() == 1)
        return;
      this->up_down_attack = static_cast<int>(Etat::up);
      this->clock.restart();
    }
  else
    {
      if (this->up_down_attack == static_cast<int>(Etat::up))
	{
          if (pos.y >= 600)
            this->up_down_attack = static_cast<int>(Etat::down);
          else
            chomp.setPosition(pos.x, pos.y + 8);
	}
      if (this->up_down_attack == static_cast<int>(Etat::down))
	{
          if (pos.y <= 15)
            this->up_down_attack = static_cast<int>(Etat::up);
          else
            chomp.setPosition(pos.x, pos.y - 8);
        }
    }
}

// ----------------------------------------------------------------------------------------

void		Boss::update()
{
  std::cout << "Le constructeur n'est pas call" << std::endl;
  if (this->GetLife() > 200)
    {
      std::cout << "call first pattern" << std::endl;
      this->FirstPattern();
    }
  else
    this->SecondPattern();
  if (this->GetLife() <= 0)
    {
      std::cout << "WIN !" << std::endl;
    }
}

void		Boss::draw(sf::RenderWindow &window)
{
    std::cout << "la je vais draw" << std::endl;

    window.draw(GetChomp());
    if (bite)
    {
        window.draw(this->GetFirstMeteorite(), this->GetFirstTransform());
        window.draw(this->GetSecondMeteorite(), this->GetSecondTransform());
        window.draw(this->GetThirdMeteorite(), this->GetThirdTransform());
    }
}

const bool  Boss::doShot()
{
  return (false);
}
