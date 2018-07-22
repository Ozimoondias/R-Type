//
// Created by agar on 24/01/18.
//

#ifndef CPP_RTYPE_ENTITYMANAGER_HPP
#define CPP_RTYPE_ENTITYMANAGER_HPP

class CoreManager;

#include <list>
#include <memory>
#include <string>
#include <iostream>

#include "Map.hpp"
#include "Shot.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Button.hpp"
#include "Boss.hpp"
#include "Bonus.hpp"
#include "Sound.hpp"

#include "Entity.hpp"

class EntityManager
{

public:

    CoreManager &getCoreManager();

    EntityManager(CoreManager &);
    virtual ~EntityManager(){}

    void    addButton(const std::string &, const int, const int);

    void    addBoss();

    void    addMeteor();

    void    addBonus(const float, const float);

    void    addEnemy();
    void    addEnemyShot(const float, const float, const float);

    void    addPlayer();
    void    addPlayer(const std::string &, const int, const int);

    void    addPlayer2();
    void    addPlayer2(const std::string &, const int, const int);

    void    addPlayerShot();
    void    addPlayer2Shot();

    void    updateMap();

    void    updateBonus();

    void    updateEnemy();
    void    updateEnemyShot();

    void    updatePlayer();
    void    updatePlayerShot();

    void    drawMap();
    void    drawBack();

    void    drawButtonMenu(const int);
    void    updateButtonMenu(const int);
    void    drawButtonSelect(const int);
    void    updateButtonSelect(const int);
    void    drawButtonPause(const int);
    void    updateButtonPause(const int);

    void    drawBonus();

    void    drawEnemy();
    void    drawEnemyShot();

    void    drawPlayer();
    void    drawPlayerShot();

    Map                                     &getMap();
    Back                                    &getBack();

    std::map<std::string, std::unique_ptr<Sound>>
                                            &getSound();

    std::vector<std::unique_ptr<Entity>>    &getBoss();

    std::vector<std::unique_ptr<Entity>>    &getBonus();

    std::vector<std::unique_ptr<Entity>>    &getEnemy();
    std::vector<std::unique_ptr<Entity>>    &getEnemyShot();

    std::vector<std::unique_ptr<Entity>>    &getPlayer();
    std::vector<std::unique_ptr<Entity>>    &getPlayerShot();

    std::vector<std::unique_ptr<Entity>>    &getButtonMenu();
    std::vector<std::unique_ptr<Entity>>    &getButtonSelect();
    std::vector<std::unique_ptr<Entity>>    &getButtonPause();

    sf::Shader          shader;
    sf::Shader          shader2;

    sf::Music           music;

private:

    int                                     shot;

    Map                                     map;
    Back                                    back;

    std::vector<std::unique_ptr<Entity>>    bossi;

    std::vector<std::unique_ptr<Entity>>    bonus;

    std::map<std::string, std::unique_ptr<Sound>>
                                            sound;

    std::vector<std::unique_ptr<Entity>>    enemy;
    std::vector<std::unique_ptr<Entity>>    enemyShot;

    std::vector<std::unique_ptr<Entity>>    player;
    std::vector<std::unique_ptr<Entity>>    playerShot;

    std::vector<std::unique_ptr<Entity>>    buttonMenu;
    std::vector<std::unique_ptr<Entity>>    buttonSelect;
    std::vector<std::unique_ptr<Entity>>    buttonPause;

    CoreManager                             &coreManager;

};

#endif //CPP_RTYPE_ENTITYMANAGER_HPP
