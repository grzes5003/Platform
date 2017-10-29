#pragma once
#include "Physic.h"
#include "Ridigbody.h"

class Object : public virtual Ridigbody, public virtual Physic
{
	sf::CircleShape *shapeptr;
	float mass;
public:
	void moveObject( pos newpos );						// move to position in pixels
	pos getPosition();									// get positoin of obj in pixels
	Object() { 
		shapeptr = new sf::CircleShape( 80.f );
		shapeptr->setFillColor( sf::Color::Red );
		shapeptr->setPosition(position.x, position.y);
	}
	~Object();
};

