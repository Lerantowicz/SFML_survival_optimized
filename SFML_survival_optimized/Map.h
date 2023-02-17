#include <SFML/Graphics.hpp>
#include "Player.h"

#pragma once
class Map
{
public:
	Map(Player* player, sf::Texture* texture, sf::Vector2f window_size);


	class Tile
	{
	public:
		Tile();



		int** one_tile;
		unsigned tile_size = 60;
	};

	void update();

	void draw(sf::RenderWindow& win);


private:
	Tile* map_array;
	sf::Sprite* map_texture;
	unsigned tiles = 9;
	sf::Vector2f window_size;
	sf::Vector2f starting_points;
	sf::Vector2f ending_points;
	Player* map_player;
	int map_tile_size;

};



