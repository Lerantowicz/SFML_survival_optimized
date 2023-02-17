#include "Map.h"
#include "Player.h"

Map::Map(Player* player, sf::Texture* texture, sf::Vector2f window_size)
{
	this->window_size = window_size;
	starting_points = sf::Vector2f(660,660);
	ending_points = sf::Vector2f(1980,1980);
	map_tile_size = ending_points.x / 60;
	map_array = new Tile[tiles];
	map_player = player;
	map_texture = new sf::Sprite(*texture, sf::IntRect(starting_points.x, starting_points.y, window_size.x, window_size.y));
}

void Map::update()
{
	int x = map_player->get_x();
	int y = map_player->get_y();
	if (x != 0 || y != 0)
	{
		if (x > 0)
		{
			starting_points.x += map_tile_size;
			
		}
		else if (x < 0)
		{
			starting_points.x -= map_tile_size;

		}
		if (y > 0)
		{
			starting_points.y += map_tile_size;
		}
		else if (y < 0)
		{
			starting_points.y -= map_tile_size;
		}
		map_player->set_x(0);
		map_player->set_y(0);
		map_texture->setTextureRect(sf::IntRect(starting_points.x, starting_points.y, window_size.x, window_size.y));
	}
}

void Map::draw(sf::RenderWindow &win)
{
	win.draw(*map_texture);
}

Map::Tile::Tile()
{
	one_tile = new int* [tile_size];
	for (size_t i = 0; i < tile_size; i++)
	{
		one_tile[i] = new int[tile_size];
	}
}



