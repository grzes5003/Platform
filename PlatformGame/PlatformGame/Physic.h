#pragma once
//#define FPS_LIMIT 200.f
#define SCALE 1/100					// one pixel is x cm IRL
#define GRAVITY 10.f
#define PI 3.14f
#include "pos.h"
#include "Object.h"

class Physic
{
	
	static float gravity(sf::Vector2f &velocity, float time);
public:
	
	static void changePosition( Object & obj );
	static void simulate( Object & obj, float time);
	Physic();
	~Physic();
};

