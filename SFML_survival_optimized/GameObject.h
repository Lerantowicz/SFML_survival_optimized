#pragma once

#include <SFML/Graphics.hpp>
#include <chrono>


class GameObject
{
public:
	GameObject() = delete;

	GameObject(sf::CircleShape* o_collider, sf::Sprite* o_skin, double o_move_speed = 1, double o_entity_size = 10) : collider(o_collider), skin(o_skin), move_speed(o_move_speed), entity_size(o_entity_size), dead(0)
	{

	}


	virtual void update(sf::Event ev) = 0;

	virtual void draw(sf::RenderWindow& win) = 0;

	virtual void init_game_object() = 0;
	
	virtual inline void collision(GameObject* collided) = 0;

	virtual ~GameObject()
	{
		delete collider;
	}


	double get_speed() const
	{
		return move_speed;
	}

	double get_size() const
	{
		return entity_size;
	}

	void set_speed(double var)
	{
		move_speed = var;
	}

	sf::Vector2f get_position() const
	{
		return coordinates;
	}

	void set_position(sf::Vector2f position)
	{
		coordinates = position;
		collider->setPosition(coordinates);
	}

	bool get_dead() const
	{
		return dead;
	}

	void set_dead()
	{
		dead = true;
	}


protected:
	sf::CircleShape *collider;
	sf::Sprite* skin;

	sf::Vector2f coordinates;

	double move_speed;
	double entity_size;
	bool dead;
};

