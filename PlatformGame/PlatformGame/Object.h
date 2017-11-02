#pragma once
#include "Physic.h"
#include "Ridigbody.h"

class Object : public virtual Ridigbody, public virtual Physic
{
	sf::CircleShape *shapeptr;
	//float mass;										// niepotrzebne i suppose
public:
	void drawObj(sf::RenderWindow &window);				// draw an object in window
	void moveObject( pos newpos );						// move to position in pixels
	pos getPosition();									// get positoin of obj in pixels
	Object();
	~Object();
};

