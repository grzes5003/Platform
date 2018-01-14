#include "Object.h"



void Object::drawObj( sf::RenderWindow & window ) {
	shapeptr->setPosition( -sf::Vector2f( position.x, position.y ) );		// make sure position is most recent
	window.draw( *shapeptr );
}

void Object::changePosition( sf::Vector2f newpos ) {
	position = newpos;
}

sf::Vector2f Object::getSize() {
	return shapeptr->getSize();
}

sf::Vector2f Object::getPosition() {
	return position;
}

Object::Object() {
	shapeptr = new sf::RectangleShape( sf::Vector2f( 50, 50 ) );			/// for player
	shapeptr->setFillColor( sf::Color::Red );
	shapeptr->setPosition( position.x, position.y );
	isCollieded = false;
	isPlayer = 1;
}

Object::Object( sf::RectangleShape sptr ) {									/// doesnt work for some reason
	shapeptr = &sptr;			
	isCollieded = false;
	isPlayer = 0;
}

Object::Object( sf::Vector2f sizee, sf::Color color, sf::Vector2f pos, bool isStat, bool isPhy, bool isPlay ) {	/// for other obj in game
	shapeptr = new sf::RectangleShape( sizee );
	shapeptr->setFillColor( color );
	shapeptr->setPosition( pos );
	position = pos;
	isStatic = isStat;
	_isPhysical = isPhy;
	isCollieded = false;
	isPlayer = isPlay;
}


Object::~Object() {
}
