#include "Enemy.h"






Enemy::Enemy(sf::CircleShape* o_shape, const Player* o_player, unsigned o_health, double o_move_speed, double o_size ) : Entity(o_shape,nullptr, o_move_speed, o_size, o_health), player(o_player)
{
	init_game_object();
}



void Enemy::update(sf::Event ev)
{
	sf::Vector2f position = player->get_position() - coordinates;

	if (position.x > 0)
	{
		coordinates.x += move_speed;
	}
	else if (position.x < 0)
	{
		coordinates.x -= move_speed;
	}
	else
	{

	}
	if (position.y > 0)
	{
		coordinates.y += move_speed;
	}
	else if (position.y < 0)
	{
		coordinates.y -= move_speed;
	}
	else
	{

	}






	collider->setPosition(coordinates.x, coordinates.y);
}

void Enemy::draw(sf::RenderWindow& win)
{
	win.draw(*collider);
}



void Enemy::init_game_object()
{
	int x = rand() % 101 + 100;
	int y = rand() % 101 + 100;
	int sign = rand() % 2;
	int sign2 = rand() % 2;
	coordinates = sf::Vector2f(player->get_position().x + (sign == 1 ? x : -x), player->get_position().y + (sign2 == 1 ? y : -y));
	collider = new sf::CircleShape(entity_size);
	collider->setOrigin(sf::Vector2f(entity_size, entity_size));
	collider->setPosition(coordinates);
	collider->setFillColor(sf::Color::Blue);
	collider->setOutlineColor(sf::Color::Black);
	collider->setOutlineThickness(1.f);
}

