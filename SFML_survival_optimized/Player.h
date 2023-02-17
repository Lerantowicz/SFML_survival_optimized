#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Player : public Entity
{
public:
	Player(sf::CircleShape* shape, unsigned health = 100, double move_speed = 1, double size = 10.f);



	void update(sf::Event ev);

	void draw(sf::RenderWindow& win);

	void init_game_object();


	
private:
	uint_fast8_t button_state;

};

