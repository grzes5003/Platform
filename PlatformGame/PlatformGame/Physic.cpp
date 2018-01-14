#include "Physic.h"



sf::Vector2f Physic::gravity(sf::Vector2f &velocity, float dtime ) {
	velocity += Gravity*dtime;
	return velocity;
}

void Physic::jump( Object & obj ) {

}

sf::Vector2f Physic::updatePosition( Object & obj, float dtime ) {
	sf::Vector2f temp = obj.getPosition();
	temp += obj.velocity * (dtime * SPEED);

	obj.changePosition( temp );
	return temp;
}

void Physic::simulate( Object & obj, std::vector<Object>& obj_tab, float dtime, int dontCheckNumb ) {
	if(obj.isPhysical()) {
		if( !obj.isStatic ) {
			gravity( obj.velocity, dtime );
			collision( obj, obj_tab, dtime );
		}
		//
	}
	//update obj
	updatePosition( obj, dtime );
}

int Physic::collision( Object & obj, std::vector<Object>& obj_tab, float dtime, int dontCheckNumb ) {
	
	//
	//	pos(x,y) ___________
	//			|			|
	//			|			|
	//			|			|
	//			|			|
	//			------------- pos+size (x,y)
	//
	
	int leftSide =	obj.getPosition().x;
	int topSide  =	obj.getPosition().y;
	int downSide =	obj.getPosition().y - obj.getSize().y;
	int rightSide=  obj.getPosition().x + obj.getSize().x;

	Object *tempObj;

	for( unsigned int i = 0; i < obj_tab.size(); i++ ) {	// checking all obj at the scene
		if( dontCheckNumb != i ) {							// check all obj from list but not itself
			tempObj = &obj_tab.at( i );
			//
			if( downSide  <= (tempObj->getPosition().y ) &&
				topSide   >=  tempObj->getPosition().y - tempObj->getSize().y&&
				leftSide  >=  tempObj->getPosition().x &&
				rightSide <= (tempObj->getPosition().x + tempObj->getSize().x)
				) 
			{ //collision happend
				obj.velocity = sf::Vector2f( 0, 0 );
				obj.isStatic = 1;
			}		
		}
	}
	return 0;
}

Physic::Physic() {
}


Physic::~Physic() {
}
