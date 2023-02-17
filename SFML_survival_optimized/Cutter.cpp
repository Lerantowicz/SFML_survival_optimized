#include "Cutter.h"

Cutter::Cutter(unsigned o_damage, Player* o_player, Enemy_controller* o_e_controller, sf::CircleShape* o_collider, sf::Sprite* o_skin, double o_move_speed, double o_entity_size) : Damage_dealer(o_damage, o_player, o_e_controller, o_collider, o_skin, o_move_speed, o_entity_size)
{
    first = std::chrono::steady_clock::now();
    attack_speed = 10;
    line = new sf::Vertex[2];
}

inline void Cutter::collision(GameObject* collided)
{
	/*double rad, distance, unit_x, unit_y;
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
	}*/
    Enemy* temp = dynamic_cast<Enemy*>(collided);

    if (temp != nullptr && player != nullptr)
    {



        coordinates_start = get_rand_pos(player->get_position());
        coordinates_end = get_rand_pos(coordinates_start);

        if (work)
        {
            line[0] = sf::Vertex(coordinates_start, sf::Color::Black);
            line[1] = sf::Vertex(coordinates_end, sf::Color::Black);
            work = 0;
        }
        
        
        double x1 = coordinates_start.x;
        double y1 = coordinates_start.y;
        double x2 = coordinates_end.x;
        double y2 = coordinates_end.y;

        double xc = temp->get_position().x;
        double yc = temp->get_position().y;

        double r = temp->get_size();

        double m = (y2 - y1) / (x2 - x1);
        double b = y1 - m * x1;
        // Step 2: Determine the coordinates of the circle's center
        // xc and yc are the x and y coordinates of the circle's center
        // r is the radius of the circle

        // Step 3: Substitute the equation of the line into the equation for a circle
        double A = 1 + pow(m, 2);
        double B = 2 * (m * b - m * yc - xc);
        double C = pow(xc, 2) + pow(b - yc, 2) - pow(r, 2);

        // Step 4: Simplify the equation and solve for x using the quadratic formula
        double discriminant = pow(B, 2) - 4 * A * C;

        if (discriminant < 0) {
            // The line does not intersect the circle
            return;
        }
        else {
            double x1_intersect = (-B + sqrt(discriminant)) / (2 * A);
            double x2_intersect = (-B - sqrt(discriminant)) / (2 * A);

            // Step 5: Check if the value(s) of x obtained in step 4 are within the range of the x-coordinates of the line's start and end points
            if (x1_intersect >= std::min(x1, x2) && x1_intersect <= std::max(x1, x2)) {
                // The line crosses the circle
                temp->set_health(temp->get_health() - damage);
            }
            else if (x2_intersect >= std::min(x1, x2) && x2_intersect <= std::max(x1, x2)) {
                // The line crosses the circle
                temp->set_health(temp->get_health() - damage);
            }
            else {
                // The line does not intersect the circle
                return;
            }
        }
    }
}

void Cutter::update(sf::Event ev)
{

    second = std::chrono::steady_clock::now();



    float difference = (std::chrono::duration_cast<std::chrono::milliseconds>(second - first).count());
    if (difference > attack_speed)
    {
        work = 1;
        for (auto z =
            e_controller->get_enemy_listp()->begin();
            z != e_controller->get_enemy_listp()->end(); z++)
        {
            collision(*z);
        }
        first = std::chrono::steady_clock::now();
    }

}

void Cutter::draw(sf::RenderWindow& win)
{
}

void Cutter::animation()
{
}



void Cutter::to_do()
{
	
}
