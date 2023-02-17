#pragma once


#include "Player.h"


class Enemy : public Entity
{
private:
	Enemy() = delete;
	
public:
	
	Enemy(sf::CircleShape* o_shape, const Player* o_player, unsigned o_health = 100, double o_move_speed = 0.3, double o_size = 10.f);

	void update(sf::Event ev);

	void draw(sf::RenderWindow& win);


	void init_game_object();

	
	unsigned points_worth = 10;
	

private:

	const Player* player;

	
};

