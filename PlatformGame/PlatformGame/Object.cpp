#include "Object.h"



void Object::drawObj( sf::RenderWindow & window ) {
	window.draw( *shapeptr );
}

void Object::moveObject( pos newpos ) {
}

pos Object::getPosition() {
	return position;
}

Object::Object() {
	shapeptr = new sf::CircleShape( 80.f );			/// make for test purp 
	shapeptr->setFillColor( sf::Color::Red );
	shapeptr->setPosition( position.x, position.y );
}


Object::~Object() {
}
