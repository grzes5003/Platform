#include "Physic.h"



sf::Vector2f Physic::gravity(sf::Vector2f &velocity, float dtime ) {
	velocity += Gravity*dtime;
	return velocity;
}

void Physic::jump( Object & obj ) {

}

sf::Vector2f Physic::updatePosition( Object & obj, float dtime ) {
	sf::Vector2f temp = obj.getPosition();
	temp += obj.velocity * dtime;

	obj.changePosition( temp );
	return temp;
}

void Physic::simulate( Object & obj, float dtime) {
	if(obj.isPhysical()) {
		if( !obj.isStatic )
			gravity( obj.velocity, dtime );
		//
	}
	//update obj
	updatePosition( obj, dtime );
}

int Physic::collision( Object & obj, std::vector<Object>& obj_tab, float dtime ) {
	return 0;
}

Physic::Physic() {
}


Physic::~Physic() {
}
