#include "Game.h"

void Game::init_window()
{
	
	window = new sf::RenderWindow(video, "Game1");
	window->setView(*view);
}

void Game::init_variables()
{
	video.height = 1000;
	video.width = 1000;
	window = nullptr;
	player = new Player(new sf::CircleShape(10.f));
	controller = new Enemy_controller(player);
	p_controller = new Projectile_Controller(player, controller, 10000);
	view = new sf::View(sf::Vector2f(0.f,0.f), sf::Vector2f(512.f, 512.f));
	game_interface = new GUI(controller, player);
	cutter = new Cutter(20, player, controller);
}

Game::Game() 
{
	srand(time(NULL));
	init_variables();
	init_window();
	window->setFramerateLimit(60);
	game_interface->set_position_health(player->get_position());
	game_interface->set_position_points(sf::Vector2f(220, 20));


}

Game::~Game()
{
	delete window;
}

void Game::update()
{
	poll_events(); 
	entity_list = controller->get_enemy_list();
	entity_list.push_back(player);
	player->update(ev);
	game_interface->update(ev);
	controller->update(ev);
	entity_collision(&entity_list);
	p_controller->update(ev);
	view->setCenter(player->get_position());
	int temp = view->getSize().x / 8;
	int half_size = view->getSize().x / 2;
	game_interface->set_position_health(view->getCenter() - sf::Vector2f(half_size, -half_size + temp));
	game_interface->set_position_points(view->getCenter() - sf::Vector2f(-half_size + temp, -half_size + temp));
	cutter->update(ev);
}

void Game::render()
{
	window->clear(sf::Color::White);
	player->draw(*window);
	p_controller->draw(*window);
	controller->draw(*window);
	game_interface->draw(*window);
	window->display();
	window->setView(*view);
	window->draw(cutter->line, 2, sf::Lines);
}

const bool Game::get_window_open() const
{
	return window->isOpen();
}

void Game::poll_events()
{
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				window->close();
		default:
			break;
		}
	}
}

void Game::entity_collision(std::list<Entity*>* entity_list)
{
	entity_list->sort(compare());
	std::vector<Entity*> active_list;
	for (auto i = entity_list->begin(); i != entity_list->end(); i++)
	{
		
		active_list.push_back(*i);
		for (auto z = 0; z < active_list.size(); z++)
		{
			
			if ((*i)->get_position().x + (*i)->get_size() > (active_list[z])->get_position().x - (active_list[z])->get_size())
			{
				(*i)->collision(active_list[z]);
					
			}
			else
			{
				active_list.erase(active_list.begin()+z);
			}
		}
		
	}

	

}
