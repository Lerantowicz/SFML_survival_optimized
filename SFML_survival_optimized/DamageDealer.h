#pragma once
#include "GameObject.h"
class DamageDealer :
    public GameObject
{

    void update();

    void draw();


private:
    unsigned damage;
    unsigned atack_speed;
};

