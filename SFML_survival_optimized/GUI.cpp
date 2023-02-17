#include "GUI.h"

GUI::GUI(Enemy_controller* o_enemy_controller, Player* o_player) : enemy_controller(o_enemy_controller), player(o_player)
{
	init_objects();
}

void GUI::init_objects()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		throw "Font not found";
	}
	health.setFont(font); // font is a sf::Font
	points.setFont(font); 

	health.setString(std::to_string(player->get_health()));
	points.setString(std::to_string(enemy_controller->get_points()));


	// set the character size
	health.setCharacterSize(24); 
	points.setCharacterSize(24);


	// set the color
	health.setFillColor(sf::Color::Red);
	points.setFillColor(sf::Color::Blue);

	health.setOutlineColor(sf::Color::Black);
	points.setOutlineColor(sf::Color::Black);

	health.setOutlineThickness(1.f);
	points.setOutlineThickness(1.f);



	// set the text style
	health.setStyle(sf::Text::Bold);
	points.setStyle(sf::Text::Bold);

}

void GUI::update(sf::Event ev)
{
	health.setString(std::to_string(player->get_health()));
	points.setString(std::to_string(enemy_controller->get_points()));
}



void GUI::draw(sf::RenderWindow& win)
{
	win.draw(health);
	win.draw(points);
}
