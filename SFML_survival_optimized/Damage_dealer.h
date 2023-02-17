#pragma once
//#include "GameObject.h"
#include "Enemy_controller.h"
#include <math.h>
class Damage_dealer :
    public GameObject
{



public:

    
    
    Damage_dealer(unsigned o_damage, Player* o_player, Enemy_controller* o_e_controller, sf::CircleShape* o_collider, sf::Sprite* o_skin, double o_move_speed = 2, double o_entity_size = 2) : GameObject(o_collider, o_skin, o_move_speed, o_entity_size), damage(o_damage), e_controller(o_e_controller), player(o_player)
    {
        
    }

    virtual void init_game_object() = 0;

    virtual inline void collision(GameObject* collided) = 0;

    virtual void update(sf::Event ev) = 0;

    virtual void draw(sf::RenderWindow& win) = 0;

    virtual void animation() = 0;

    //virtual void to_do() = 0;

    sf::Vector2f get_rand_pos(sf::Vector2f start_pos)
    {
        int x = rand() % 101 + 100;
        int y = rand() % 101 + 100;
        int sign = rand() % 2;
        int sign2 = rand() % 2;
        return sf::Vector2f(start_pos.x + (sign == 1 ? x : -x), start_pos.y + (sign2 == 1 ? y : -y));
    }

public:

    std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point second, first;

    const Player* player;

    float attack_speed = 100;
    unsigned damage;

    Enemy_controller* e_controller;

};

