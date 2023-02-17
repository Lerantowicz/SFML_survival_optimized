#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <chrono>



#include "Enemy.h"
#include "Player.h"



class Enemy_controller
{
public:
	Enemy_controller(Player* player);

	~Enemy_controller();

	void update(sf::Event ev);

	void draw(sf::RenderWindow& win);

	unsigned get_points()
	{
		return points;
	}

	Enemy* generate_enemy();

	std::list<Entity*>& get_enemy_list()
	{
		return enemy_list;
	}

	std::list<Entity*>* get_enemy_listp()
	{
		return &enemy_list;
	}



private:
	std::list<Entity*> enemy_list;
	unsigned enemy_number_max;
	const Player* player;
	unsigned points;
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point second, first;
};

