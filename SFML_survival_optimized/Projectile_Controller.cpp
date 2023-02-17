#include "Projectile_Controller.h"

void Projectile_Controller::update(sf::Event ev)
{
	std::vector<std::list<Projectile*>::iterator> indexes;
	second = std::chrono::steady_clock::now();
	Entity* k = find_chosen();
	sf::Vector2f  path = k->get_position() - player->get_position();
	float distance = sqrt(path.x * path.x + path.y * path.y);
	sf::Vector2f normalize(path.x / distance, path.y / distance);
	float difference = (std::chrono::duration_cast<std::chrono::milliseconds>(second - first).count());
	if (difference > attack_speed)
	{
		first = std::chrono::steady_clock::now();
		projectile_list.push_back(new Projectile(player->get_position(), nullptr, 10, normalize, new sf::CircleShape(2.f), nullptr));
	}
	for (auto i = projectile_list.begin(); 
		i != projectile_list.end(); i++)
	{
		
		for (auto z = 
			e_controller->get_enemy_listp()->begin(); 
			z != e_controller->get_enemy_listp()->end(); z++)
		{
			(*i)->collision(*z);
		}
	}
	for (auto i = projectile_list.begin(); 
		i != projectile_list.end(); i++)
	{
		if ((*i)->get_dead())
		{
			indexes.push_back(i);
		}
	}
	for (auto i = indexes.begin(); 
		i != indexes.end(); i++)
	{
		delete *(*i);
		*(*i) = nullptr;
		projectile_list.erase(*i);
	}
	for (auto i = projectile_list.begin();
		i != projectile_list.end(); i++)
	{
		(*i)->update(ev);
	}
}

void Projectile_Controller::draw(sf::RenderWindow& win)
{
	for (auto i = projectile_list.begin(); i != projectile_list.end(); i++)
	{
		(*i)->draw(win);
	}
}

Entity* Projectile_Controller::find_chosen()
{
	float min, distance;
	auto list = e_controller->get_enemy_listp();
	std::list<Entity*>::iterator chosen = list->begin();
	sf::Vector2f difference = player->get_position() - (*list->begin())->get_position();
	min = sqrt(difference.x * difference.x + difference.y * difference.y);
	for (auto i = list->begin(); i != list->end(); i++)
	{
		if ((*i) != nullptr)
		{
			difference = player->get_position() - (*i)->get_position();
			distance = sqrt(difference.x * difference.x + difference.y * difference.y);

			if (min > distance)
			{
				min = distance;
				chosen = i;
			}
		}
		
	}
	return *chosen;
}
