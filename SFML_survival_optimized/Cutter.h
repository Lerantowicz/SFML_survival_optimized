#pragma once
#include "Damage_dealer.h"
class Cutter :
    public Damage_dealer
{
public:

    Cutter(unsigned o_damage, Player* player, Enemy_controller* o_e_controller, sf::CircleShape* o_collider = nullptr, sf::Sprite* o_skin = nullptr, double o_move_speed = 2, double o_entity_size = 2);

    void init_game_object()
    {

    }

    inline void collision(GameObject* collided);

    void update(sf::Event ev);

    void draw(sf::RenderWindow& win);

    void animation();

    void to_do();

    sf::Vector2f coordinates_start;
    sf::Vector2f coordinates_end;

    sf::Vertex *line;

    
private:

    bool work;

};

