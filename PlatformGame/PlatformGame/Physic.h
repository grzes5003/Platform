#pragma once

#define SPEED 200				// one pixel is x cm IRL
#define PI 3.14f
#include "pos.h"
#include "Object.h"
const sf::Vector2f Gravity( 0, -10 );

class Physic
{
	
	static sf::Vector2f gravity(sf::Vector2f &velocity, float dtime);
public:
	
	static void jump( Object & obj );
	static sf::Vector2f updatePosition( Object & obj, float dtime );
	static void simulate( Object & obj, std::vector<Object>& obj_tab, float dtime, int  = -1 );	// last - if greater than -1, its index number
	static int collision( Object & obj, std::vector<Object> & obj_tab, float dtime, int = -1 );	// same there
	Physic();
	~Physic();
};

