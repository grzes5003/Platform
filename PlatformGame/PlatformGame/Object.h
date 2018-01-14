#pragma once
//#include "Physic.h"
#include "Ridigbody.h"

///antialiasing
//sf::ContextSettings SETTING; ///(todo)

class Object : public virtual Ridigbody
{
	sf::RectangleShape *shapeptr;
	//float mass;										// niepotrzebne i suppose
public:
	void drawObj(sf::RenderWindow &window);				// draw an object in window
	void changePosition( sf::Vector2f newpos );						// move to position in pixels
	sf::Vector2f getPosition();									// get positoin of obj in pixels
	Object();
	Object( sf::RectangleShape sptr );
	Object( sf::Vector2f sizee, sf::Color color, sf::Vector2f position, bool isStat, bool isPhy );
	~Object();
};

