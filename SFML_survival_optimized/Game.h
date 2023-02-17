#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <algorithm>


#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy_controller.h"
#include "Projectile_Controller.h"
#include "GUI.h"
#include "Cutter.h"

//#include <iostream>

class Game
{

private:

	void init_window();

	void init_variables();

public:


	Game();

	virtual ~Game();

	struct compare{
		bool operator()(Entity* first, Entity* second)
		{
			return first->get_position().x < second->get_position().x;
		}
	};

	void update();

	void render();

	const bool get_window_open() const;

	void poll_events();
	
	void entity_collision(std::list<Entity*>* entity_list);


private:
	sf::RenderWindow* window;
	sf::VideoMode video;
	sf::Event ev;
	sf::View *view;
	
	Enemy_controller* controller;
	Projectile_Controller* p_controller;
	Map *map;
	Player *player;
	std::list<Entity*> entity_list;
	GUI* game_interface;

	Cutter* cutter;

};

