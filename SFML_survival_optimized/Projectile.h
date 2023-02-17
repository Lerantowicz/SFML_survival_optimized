#pragma once


#include "Enemy.h"
#include "Damage_dealer.h"

class Projectile :
    public Damage_dealer
{
public:

    Projectile(sf::Vector2f o_coordinates, Enemy_controller* o_e_controller, unsigned o_damage, sf::Vector2f o_direction, sf::CircleShape* o_collider, sf::Sprite* o_skin, double o_move_speed = 2, double o_entity_size = 2);

    inline void collision(GameObject* collided);

    void update(sf::Event ev);

    void draw(sf::RenderWindow& win);

    void init_game_object();

    void animation()
    {

    }

    void to_do()
    {

    }


private:

    sf::Vector2f direction;
    unsigned life_time = 5;
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point second, first;
};

