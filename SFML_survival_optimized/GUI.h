#pragma once

#include "Enemy_controller.h"
#include "Player.h"

class GUI
{
public:
	GUI(Enemy_controller* o_enemy_controller, Player* o_player);

	void init_objects();

	void update(sf::Event ev);

	void draw(sf::RenderWindow& win);

	void set_position_health(sf::Vector2f position)
	{
		health.setPosition(position);
	}

	void set_position_points(sf::Vector2f position)
	{
		points.setPosition(position);
	}


private:
	Enemy_controller* enemy_controller;
	Player* player;

	sf::Font font;
	sf::Text health;
	sf::Text points;

};



