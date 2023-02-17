#include "Projectile.h"

inline void Projectile::collision(GameObject* collided)
{
	double rad, distance, unit_x, unit_y;
	sf::Vector2f difference;
	Enemy* temp = dynamic_cast<Enemy*>(collided);
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
		temp->set_health(temp->get_health() - damage);
		set_dead();
	}


}

Projectile::Projectile(sf::Vector2f o_coordinates, Enemy_controller* o_e_controller, unsigned o_damage, sf::Vector2f o_direction, sf::CircleShape* o_collider, sf::Sprite* o_skin, double o_move_speed, double o_entity_size) : Damage_dealer(o_damage, nullptr, o_e_controller, o_collider, o_skin, o_move_speed, o_entity_size), direction(o_direction)
{
	first = std::chrono::steady_clock::now();
	set_position(o_coordinates);
	init_game_object();
}

void Projectile::update(sf::Event ev)
{
	second = std::chrono::steady_clock::now();
	coordinates.x += move_speed * direction.x;
	coordinates.y += move_speed * direction.y;


	collider->setPosition(coordinates.x, coordinates.y);
	int difference = (std::chrono::duration_cast<std::chrono::seconds>(second - first).count());
	if (difference > 5)
	{
		dead = 1;
	}
}

void Projectile::draw(sf::RenderWindow& win)
{
	win.draw(*collider);
}


void Projectile::init_game_object()
{
	dead = 0;
	collider->setOrigin(sf::Vector2f(entity_size, entity_size));
	collider->setPosition(coordinates);
	collider->setFillColor(sf::Color::Red);
	collider->setOutlineColor(sf::Color::Black);
	collider->setOutlineThickness(1.f);
}