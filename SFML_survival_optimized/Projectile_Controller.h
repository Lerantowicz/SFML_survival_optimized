#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <chrono>



#include "Enemy_controller.h"
#include "Player.h"
#include "Projectile.h"

class Projectile_Controller
{
public:
	Projectile_Controller(Player* o_player, Enemy_controller* o_e_controller, unsigned o_attack_speed = 1) : player(o_player), e_controller(o_e_controller), attack_speed(o_attack_speed)
	{
		first = std::chrono::steady_clock::now();
	}


	void update(sf::Event ev);

	void draw(sf::RenderWindow& win);

	Entity* find_chosen();


private:
	float attack_speed;
	Player* player;
	Enemy_controller* e_controller;
	std::list<Projectile*> projectile_list;
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point second, first;
};

