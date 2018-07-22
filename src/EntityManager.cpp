//
// Created by agar on 24/01/18.
//

#include <CoreManager.hpp>
#include "EntityManager.hpp"

EntityManager::EntityManager(CoreManager &manager)
        :   coreManager(manager)
{
    shot = 1;

    sound.insert(std::pair<std::string, std::unique_ptr<Sound>>("SHOT", std::unique_ptr<Sound>(new Sound("../media/scifi054.wav"))));
    sound.insert(std::pair<std::string, std::unique_ptr<Sound>>("ENEMY", std::unique_ptr<Sound>(new Sound("../media/scifi072.wav"))));

    buttonMenu.push_back(std::unique_ptr<Entity>(std::unique_ptr<Button>(new Button("../media/1.png", 0, 450))));
    buttonMenu.push_back(std::unique_ptr<Entity>(std::unique_ptr<Button>(new Button("../media/2.png", 0, 650))));
    buttonMenu.push_back(std::unique_ptr<Entity>(std::unique_ptr<Button>(new Button("../media/3.png", 0, 850))));

    buttonSelect.push_back(std::unique_ptr<Entity>(std::unique_ptr<Button>(new Button("../media/SELECT1.png", 0, 0))));
    buttonSelect.push_back(std::unique_ptr<Entity>(std::unique_ptr<Button>(new Button("../media/SELECT2.png", 0, 0))));
    buttonSelect.push_back(std::unique_ptr<Entity>(std::unique_ptr<Button>(new Button("../media/SELECT3.png", 0, 0))));

    buttonPause.push_back(std::unique_ptr<Entity>(std::unique_ptr<Button>(new Button("../media/6.png", 0, 200))));
    buttonPause.push_back(std::unique_ptr<Entity>(std::unique_ptr<Button>(new Button("../media/4.png", 0, 450))));
    buttonPause.push_back(std::unique_ptr<Entity>(std::unique_ptr<Button>(new Button("../media/5.png", 0, 600))));
    buttonPause.push_back(std::unique_ptr<Entity>(std::unique_ptr<Button>(new Button("../media/3.png", 0, 750))));

    shader.loadFromFile("../media/example_001.frag", sf::Shader::Fragment);
    shader2.loadFromFile("../media/example_004.frag", sf::Shader::Fragment);
}

CoreManager &EntityManager::getCoreManager()
{
    return (coreManager);
}

std::vector<std::unique_ptr<Entity>>      &EntityManager::getButtonMenu()
{
    return (buttonMenu);
}

std::vector<std::unique_ptr<Entity>>      &EntityManager::getButtonSelect()
{
    return (buttonSelect);
}

std::vector<std::unique_ptr<Entity>>      &EntityManager::getButtonPause()
{
    return (buttonPause);
}

std::vector<std::unique_ptr<Entity>>    &EntityManager::getBonus()
{
    return (bonus);
}

std::vector<std::unique_ptr<Entity>>    &EntityManager::getPlayer()
{
    return (player);
}

std::vector<std::unique_ptr<Entity>>    &EntityManager::getPlayerShot()
{
    return (playerShot);
}

std::vector<std::unique_ptr<Entity>>    &EntityManager::getEnemy()
{
    return (enemy);
}

std::vector<std::unique_ptr<Entity>>    &EntityManager::getBoss()
{
    return (bossi);
}

std::vector<std::unique_ptr<Entity>>    &EntityManager::getEnemyShot()
{
    return (enemyShot);
}

Map     &EntityManager::getMap()
{
    return (map);
}

Back    &EntityManager::getBack()
{
    return (back);
}

void    EntityManager::addBoss()
{
    bossi.push_back(std::unique_ptr<Entity>(new Boss(player[0])));
}

void    EntityManager::addEnemy()
{
    int i = rand() % 100;
    std::string	texture = "../media/ENEMY";
    std::string	last_texture = "../media/ENEMY" + std::to_string(rand() % 4 + 1) + ".png";
    
    if (!sound.find("ENEMY")->second->Run())
        sound.find("ENEMY")->second->Play();
    if (i < 80)
      {
        //enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/ENEMY.png", 2000, 400 + (i), 2, 5, 1)));
	enemy.push_back(std::unique_ptr<Entity>(new Enemy(last_texture, 2000, 400 + (i), 2, 5, 1)));
        return;
      }
    if (i < 90)
      {
	enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/ENEMY6.png", 2000, 300 + (i), 2, 5, 1)));
	enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/ENEMY6.png", 2000, 600 + (i), 2, 5, 1)));
      //enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/enemySolo4.png", 2000, 300 + (i), 2, 5, 1)));
        //enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/enemySolo4.png", 2000, 600 + (i), 2, 5, 1)));
        return;
    }
    if (i < 100) {
      enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/ESCADRON.png", 2000, 300, 1, 10, 2)));
      enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/ESCADRON.png", 1920, 400, 1, 10, 2)));
      enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/ESCADRON.png", 1840, 500, 1, 10, 2)));
      enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/ESCADRON.png", 1920, 600, 1, 10, 2)));
      enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/ESCADRON.png", 2000, 699, 1, 10, 2)));
      return;
    }
}

void    EntityManager::addMeteor()
{
    enemy.push_back(std::unique_ptr<Entity>(new Enemy("../media/METEOR.png", 2000, 600, 2, 5, 3)));
}

void    EntityManager::addEnemyShot(const float x, const float y, const float type)
{
  enemyShot.push_back(std::unique_ptr<Entity>(new Shot("../media/ENEMYSHOT.png", x, y + 20, -20, 5, 0)));
}

void    EntityManager::addBonus(const float x, const float y)
{
  int randNum = rand() % ((3 - 1) + 1) + 1;

  switch (randNum)
    {
    case 1:
      bonus.push_back(std::unique_ptr<Entity>(new Bonus("../media/SPEED.png", x, y, 1)));
      break;
    case 2:
      bonus.push_back(std::unique_ptr<Entity>(new Bonus("../media/LIFE.png", x, y, 2)));
      break;
    case 3:
      bonus.push_back(std::unique_ptr<Entity>(new Bonus("../media/SCORE.png", x, y, 3)));
      break;
    }
}

void    EntityManager::addPlayer()
{
    shot = 1;
    player.push_back(std::unique_ptr<Entity>(new Player("../media/playerSolo.png", 0, 450, 7, 5)));
}

void    EntityManager::addPlayer(const std::string &str, const int speed, const int life)
{
    shot = 1;
    player.push_back(std::unique_ptr<Entity>(new Player(str, 0, 450, speed, life)));
}

void    EntityManager::addPlayerShot()
{
    sound.find("SHOT")->second->Play();

    switch (shot)
    {
        case 1:
        {
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5, 25, 0.9, 0)));
        }
            break;
        case 2:
        {
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5 - 40, 20, 0.9, 0)));
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5 + 40, 20, 0.9, 0)));
        }
            break;
        case 3:
        {
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5 - 50, 20, 0.9, 0)));
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80 + 30,
                             player[0]->getSprite().getPosition().y + 27.5, 20, 0.9, 0)));
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5 + 50, 20, 0.9, 0)));
        }
            break;
        case 4:
        {
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5, 20, 0.9, -1)));
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5, 20, 0.9, 0)));
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5, 20, 0.9, 1)));
        }
        case 5:
        {
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5, 20, 0.9, -2)));
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5, 20, 0.9, -1)));
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5, 20, 0.9, 0)));
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5, 20, 0.9, 1)));
            playerShot.push_back(std::unique_ptr<Entity>(
                    new Shot("../media/SHOT.png",
                             player[0]->getSprite().getPosition().x + 80,
                             player[0]->getSprite().getPosition().y + 27.5, 20, 0.9, 2)));
        }
            break;
    }
}

void    EntityManager::updateBonus()
{
    for (int i = 0; i < bonus.size(); ++i)
    {
        bonus[i]->update();
        if (bonus[i]->getSprite().getGlobalBounds().intersects(player[0]->getSprite().getGlobalBounds()))
            bonus[i]->setAlive(false);
    }
}

void    EntityManager::updateEnemy()
{
    for (int i = 0; i < enemy.size(); ++i)
    {
        enemy[i]->update();
        if (enemy[i]->doShot())
            addEnemyShot(enemy[i]->getSprite().getPosition().x, enemy[i]->getSprite().getPosition().y, enemy[i]->getSpeed());
        else if (enemy[i]->getSprite().getGlobalBounds().intersects(player[0]->getSprite().getGlobalBounds()))
        {
            enemy[i]->setAlive(false);
            player[0]->setPv(player[0]->getPv() - 1);
            if (player[0]->getPv() <= 0)
                coreManager.stateManager.changeState(StateManager::OVER);
        }
    }
    for (int y = 0; y < bossi.size(); ++y)
    {
        bossi[y]->update();
    }
}

void    EntityManager::updateEnemyShot()
{
    for (int i = 0; i < enemyShot.size(); ++i)
    {
        enemyShot[i]->update();
        if (enemyShot[i]->getSprite().getGlobalBounds().intersects(player[0]->getSprite().getGlobalBounds()))
        {
            enemyShot[i]->setAlive(false);
            player[0]->setPv(player[0]->getPv() - 1);
            if (player[0]->getPv() <= 0)
                coreManager.stateManager.changeState(StateManager::OVER);
        }
    }
}

void    EntityManager::updateMap()
{
    map.update();
}

void    EntityManager::drawBack()
{
    shader.setUniform("time", coreManager.stateManager._clock.getElapsedTime().asSeconds() / 20);
    back.draw(coreManager.graphicsManager.getwindow(), shader);
}

void    EntityManager::drawMap()
{
    map.draw(coreManager.graphicsManager.getwindow());
}

void    EntityManager::drawButtonMenu(const int i)
{
    for (int y = 0; y < buttonMenu.size(); ++y)
    {
        if (y != i)
            buttonMenu[y]->draw(coreManager.graphicsManager.getwindow());
    }
}

void    EntityManager::updateButtonMenu(const int i)
{
    coreManager.graphicsManager.getwindow().draw(buttonMenu[i]->getSprite(), &shader);
}

void    EntityManager::drawButtonSelect(const int i)
{
    for (int y = 0; y < buttonSelect.size(); ++y)
    {
        if (y == i)
            coreManager.graphicsManager.getwindow().draw(buttonSelect[y]->getSprite(), &shader2);
    }
}

void    EntityManager::updateButtonSelect(const int i)
{
    coreManager.graphicsManager.getwindow().draw(buttonSelect[i]->getSprite(), &shader);
}

void    EntityManager::drawButtonPause(const int i)
{
    for (int y = 0; y < buttonPause.size(); ++y)
    {
        if (y != i)
            buttonPause[y]->draw(coreManager.graphicsManager.getwindow());
    }
}

void    EntityManager::updateButtonPause(const int i)
{
    coreManager.graphicsManager.getwindow().draw(buttonPause[i]->getSprite(), &shader);
}

void    EntityManager::updatePlayer()
{
    for (int y = 0; y < player.size(); ++y)
        player[y]->update();
}

void    EntityManager::updatePlayerShot()
{
    for (int i = 0; i < playerShot.size(); ++i)
    {
        playerShot[i]->update();
        for (int y = 0; y < bossi.size(); ++y)
        {
            std::unique_ptr<Boss> &test = reinterpret_cast<std::unique_ptr<Boss>&>(bossi[y]);
            std::cout << "circle" << test->GetBossCircles().size() << std::endl;
            std::cout << "boss" << bossi.size() << std::endl;

            for (int o = 0; o < test->GetBossCircles().size(); ++o)
            {
                if (test->GetBossCircles()[o].getGlobalBounds().intersects(playerShot[i]->getSprite().getGlobalBounds()))
                {
                    playerShot[i]->setAlive(false);
                    test->takeDamages();
                }
            }
        }
        for (int y = 0; y < enemy.size(); ++y)
            if (enemy[y]->getSprite().getGlobalBounds().intersects(playerShot[i]->getSprite().getGlobalBounds()))
            {
                enemy[y]->setPv(enemy[y]->getPv() - 1);
                if (enemy[y]->getPv() <= 0)
                {
                    enemy[y]->setAlive(false);
                    if ((rand() % ((100 - 1) + 1) + 1) >= 80)
                        addBonus(enemy[y]->getSprite().getPosition().x, enemy[y]->getSprite().getPosition().y);
                    player[0]->setScore(player[0]->getScore()+1);
                }
                playerShot[i]->setAlive(false);
            }
    }
}

void    EntityManager::drawPlayer()
{
    for (int y = 0; y < player.size(); ++y)
    {
        if (player[y]->getAlive())
            player[y]->draw(coreManager.graphicsManager.getwindow());
    }
}

void    EntityManager::drawBonus()
{
    for (int i = 0; i < bonus.size(); ++i)
    {
        if (bonus[i]->getAlive())
            bonus[i]->draw(coreManager.graphicsManager.getwindow());
        else
        {
            std::unique_ptr<Bonus> &test = reinterpret_cast<std::unique_ptr<Bonus>&>(bonus[i]);
            if (test->getBonus(player[0]))
            {
                int i = rand() % (5 - 1 + 1) + 1;
                shot = i;
            }
            delete bonus[i].release();
            delete test.release();
            bonus.erase(bonus.begin() + i);
        }
    }
}

void    EntityManager::drawEnemy()
{
    for (int i = 0; i < enemy.size(); ++i)
    {
        if (enemy[i]->getAlive())
            enemy[i]->draw(coreManager.graphicsManager.getwindow());
        else
        {
            delete enemy[i].release();
            enemy.erase(enemy.begin() + i);
        }
    }
    for (int y = 0; y < bossi.size(); ++y)
    {
        bossi[y]->draw(coreManager.graphicsManager.getwindow());
    }
}

void    EntityManager::drawEnemyShot()
{
    for (int i = 0; i < enemyShot.size(); ++i)
    {
        if (enemyShot[i]->getAlive())
            enemyShot[i]->draw(coreManager.graphicsManager.getwindow());
        else
        {
            delete enemyShot[i].release();
            enemyShot.erase(enemyShot.begin() + i);
        }
    }
}

void    EntityManager::drawPlayerShot()
{
    for (int i = 0; i < playerShot.size(); ++i)
    {
        if (playerShot[i]->getAlive())
            playerShot[i]->draw(coreManager.graphicsManager.getwindow());
        else
        {
            delete playerShot[i].release();
            playerShot.erase(playerShot.begin() + i);
        }
    }
}
