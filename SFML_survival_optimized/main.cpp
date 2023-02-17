#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

int main()
{
	Game game;
	
	while (game.get_window_open())
	{
		game.update();

		game.render();
		
	}
	

	return 0;
}









