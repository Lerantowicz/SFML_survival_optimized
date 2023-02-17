#pragma once
#include "Player.h"
#include "Enemy_controller.h"
#include "DamageDealer.h"

class Power_up_controller
{

private:
	float attack_speed = 100;
	Player* player;
	Enemy_controller* e_controller;
	std::list<DamageDealer*> power_ups;
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point second, first;
};

