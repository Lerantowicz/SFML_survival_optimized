#pragma once


#include "GameObject.h"


class Entity : public GameObject
{
private:
	Entity() = delete;


public:
	Entity(sf::CircleShape* o_collider, sf::Sprite* skin, double move_speed = 1, double entity_size = 10, unsigned o_health = 100) : GameObject(o_collider,skin, move_speed, entity_size), health(o_health)
	{

	}
	

	inline void GameObject::collision(GameObject* collided)
	{
		double rad, distance, unit_x, unit_y;
		sf::Vector2f difference;

		if (this == collided)
		{
			return;
		}
		difference = this->coordinates - collided->get_position();
		rad = (this)->get_size() + (collided)->get_size();
		if ((collided)->get_size() > 10 || (this)->get_size() > 10)
		{

		}
		distance = sqrt(difference.x * difference.x + difference.y * difference.y);
		unit_x = difference.x / distance;
		unit_y = difference.y / distance;
		if (distance <= rad)
		{
			this->set_position(collided->get_position() + sf::Vector2f(((rad + collided->get_speed()) * unit_x), ((rad + collided->get_speed()) * unit_y)));
		}


	}

	



	int get_health()
	{
		return health;
	}

	void set_health(int hp)
	{
		if (hp <= 0 )
		{
			dead = true;
		}
		health = hp;
	}

	


	

protected:



	int health;



};




