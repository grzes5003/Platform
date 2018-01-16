#include "Physic.h"



sf::Vector2f Physic::gravity( Object & obj, sf::Vector2f &velocity, float dtime ) {
	if(!obj.isCollieded )
		velocity += Gravity*dtime;
	return velocity;
}

void Physic::jump( Object & obj ) {

}

sf::Vector2f Physic::updatePosition( Object & obj, float dtime ) {
	sf::Vector2f temp = obj.getPosition();
	if( obj.velocity.y > 5 )		// if player has too high jump
		obj.velocity.y = 2;
	
	
	temp += obj.velocity * (dtime * SPEED);

	//if( temp.y < -900 ) {			// if player goes out of screen reset 
	//	temp = sf::Vector2f( 0, 0 );
	//}

	obj.changePosition( temp );
	return temp;
}


void Physic::simulate( Object & obj, std::vector<Object>& obj_tab, float dtime, int dontCheckNumb ) {
	if(obj.isPhysical()) {
		if( !obj.isStatic ) {
			collision( obj, obj_tab, dtime );
			gravity( obj, obj.velocity, dtime );
		}
		//
	}
	//update obj
	updatePosition( obj, dtime);
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
	int rightSide=  obj.getPosition().x - obj.getSize().x;

	Object *tempObj;

	bool isCollCheck = false;

	for( unsigned int i = 0; i < obj_tab.size(); i++ ) {	// checking all obj at the scene
		if( dontCheckNumb != i ) {							// check all obj from list but not itself
			tempObj = &obj_tab.at( i );
			//
			if( downSide  <= (tempObj->getPosition().y ) &&
				topSide   >= (tempObj->getPosition().y - tempObj->getSize().y) &&
				leftSide  <= (tempObj->getPosition().x + obj.getSize().x) &&
				rightSide >= (tempObj->getPosition().x - tempObj->getSize().x - obj.getSize().x)
				) 
			{ //collision happend
				if(!obj.isCollieded )
					obj.velocity = sf::Vector2f( 0, 0 );
				isCollCheck = true;
				//obj.isStatic = 1;
			}
		}
	}

	// check if player touches any platform - if he can jump
	if( isCollCheck )
		obj.isCollieded = true;
	else
		obj.isCollieded = false;

	return 0;
}

Physic::Physic() {
}


Physic::~Physic() {
}
