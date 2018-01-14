#include "Ridigbody.h"



Ridigbody::Ridigbody() {
	position = sf::Vector2f(); mass = 1; _isPhysical = 1;
	isStatic = false;
	velocity = sf::Vector2f( 0, 0 );
}


bool Ridigbody::isPhysical() {
	return _isPhysical;
}

Ridigbody::~Ridigbody() {
}
