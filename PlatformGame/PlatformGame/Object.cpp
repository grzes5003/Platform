#include "Object.h"



void Object::drawObj( sf::RenderWindow & window ) {
	shapeptr->move( -sf::Vector2f( position.x, position.y ) );		// make sure position is most recent
	window.draw( *shapeptr );
}

void Object::changePosition( sf::Vector2f newpos ) {
	position = newpos;
}

sf::Vector2f Object::getPosition() {
	return position;
}

Object::Object() {
	shapeptr = new sf::RectangleShape( sf::Vector2f( 50, 50 ) );			/// make for test purp 
	shapeptr->setFillColor( sf::Color::Red );
	shapeptr->setPosition( position.x, position.y );
}

Object::Object( sf::RectangleShape sptr ) {									/// doesnt work for some reason
	shapeptr = &sptr;			
}

Object::Object( sf::Vector2f sizee, sf::Color color, sf::Vector2f position, bool isStat, bool isPhy ) {
	shapeptr = new sf::RectangleShape( sizee );
	shapeptr->setFillColor( color );
	shapeptr->setPosition( position );
	isStatic = isStat;
	_isPhysical = isPhy;
}


Object::~Object() {
}
