#include "Player.h"


Player::Player(sf::CircleShape* o_shape, unsigned o_health, double o_move_speed, double o_size) : Entity(o_shape, nullptr, o_move_speed, o_size, o_health)
{
	
	set_position(sf::Vector2f(0, 0));
	init_game_object();
}



void Player::update(sf::Event ev)
{
	if (ev.type == sf::Event::KeyPressed)
	{
		if (ev.key.code == sf::Keyboard::Up) {
			button_state |= 1 << 0;
		}
		else if (ev.key.code == sf::Keyboard::Down) {
			button_state |= 1 << 1;
		}
		if (ev.key.code == sf::Keyboard::Left) {
			button_state |= 1 << 2;
		}
		else if (ev.key.code == sf::Keyboard::Right) {
			button_state |= 1 << 3;
		}

	}
	if (ev.type == sf::Event::KeyReleased)
	{
		if (ev.key.code == sf::Keyboard::Up) {
			button_state &= !(1 << 0);
		}
		else if (ev.key.code == sf::Keyboard::Down) {
			button_state &= !(1 << 1);
		}
		if (ev.key.code == sf::Keyboard::Left) {
			button_state &= !(1 << 2);
		}
		else if (ev.key.code == sf::Keyboard::Right) {
			button_state &= !(1 << 3);
		}
	}
	if (button_state & (1<<0))
	{
		coordinates.y -= move_speed;
		
	}
	else if (button_state & (1 << 1))
	{
		coordinates.y += move_speed;
	}
	if (button_state & (1 << 2))
	{
		coordinates.x -= move_speed;
	}
	else if (button_state & (1 << 3))
	{
		coordinates.x += move_speed;
	}
	collider->setPosition(coordinates.x, coordinates.y);
}

void Player::draw(sf::RenderWindow& win)
{
	win.draw(*collider);
}

void Player::init_game_object()
{

	collider->setOrigin(sf::Vector2f(entity_size, entity_size));
	collider->setPosition(coordinates);
	collider->setFillColor(sf::Color::White);
	collider->setOutlineColor(sf::Color::Black);
	collider->setOutlineThickness(1.f);
	
}


