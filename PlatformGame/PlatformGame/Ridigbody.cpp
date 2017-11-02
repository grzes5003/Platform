#include "Ridigbody.h"



Ridigbody::Ridigbody() {
	position = pos(); mass = 1; _isPhysical = 1;
	isStatic = false;
}


bool Ridigbody::isPhysical() {
	return _isPhysical;
}

Ridigbody::~Ridigbody() {
}
