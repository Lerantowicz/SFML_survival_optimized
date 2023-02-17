#include "Enemy_controller.h"

Enemy_controller::Enemy_controller(Player* player) : enemy_number_max(100)
{
	first = std::chrono::steady_clock::now();
	start = std::chrono::steady_clock::now();
	this->player = player;
	for (size_t i = 0; i < enemy_number_max; i++)
	{
		enemy_list.push_back(nullptr);
	}
	for (auto i = enemy_list.begin(); i != enemy_list.end(); i++)
	{
		if ((*i) == nullptr)
		{
			(*i) = generate_enemy();
		}
	}
}

Enemy_controller::~Enemy_controller()
{
	for (auto i = enemy_list.begin(); i != enemy_list.end(); i++)
	{
		if ((*i) != nullptr)
		{
			delete (*i);
		}
		
	}
}

void Enemy_controller::update(sf::Event ev)
{
	second = std::chrono::steady_clock::now();
	if (std::chrono::duration_cast<std::chrono::seconds>(second - first).count() > 5)
	{
		first = second;
		auto z = enemy_list.begin();
		for (size_t i = 0; i < rand() % enemy_list.size(); i++)
		{
			z++;
		}
		if (*z != nullptr)
		{
			delete (*z);
			(*z) = nullptr;
		}

	}
	

	for (auto i = enemy_list.begin(); 
		i != enemy_list.end(); i++)
	{
		if ((*i)!= nullptr)
		{
			if ((*i)->get_dead())
			{
				points += dynamic_cast<Enemy*>(*i)->points_worth;
				delete (*i);
				(*i) = nullptr; 
				// erase instead of delete
			}
		}
		if ((*i) == nullptr)
		{
			(*i) = generate_enemy();
		}
	}
	for (auto i = enemy_list.begin(); 
		i != enemy_list.end(); i++)
	{
		(*i)->update(ev);
	}

	

	
}

void Enemy_controller::draw(sf::RenderWindow& win)
{
	for (auto i = enemy_list.begin(); i != enemy_list.end(); i++)
	{
		if ((*i) != nullptr)
		{
			(*i)->draw(win);
		}
	}
}

Enemy* Enemy_controller::generate_enemy()
{
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	int adder = (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() );
	return new Enemy(new sf::CircleShape(10.f + adder), player, 100U, 0.3 + double(adder / 100), double(10.f + adder));
}


