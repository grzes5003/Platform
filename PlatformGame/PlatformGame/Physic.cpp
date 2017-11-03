#include "Physic.h"



float Physic::gravity(sf::Vector2f &velocity, float time ) {
	if( time != 0 ) {
		velocity.y -= (float)(GRAVITY / (time))*SCALE;
	}
	return 0.0f;
}

void Physic::changePosition( Object & obj ) {
	obj.moveObject(pos(obj.getPosition().x + obj.velocity.x, obj.getPosition().y + obj.velocity.y ));
}

void Physic::simulate( Object & obj, float time) {
	if( obj.isPhysical() ) {
		gravity( obj.velocity, time );
		changePosition( obj );
	}
}

Physic::Physic() {
}


Physic::~Physic() {
}
