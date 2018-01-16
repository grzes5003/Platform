#include "Camera.h"



Camera::Camera() {
	startPosition = sf::Vector2f( 0, 0 );
	currentOffset = sf::Vector2f( 0, 0 );
	deltaOffset	  = sf::Vector2f( 0, 0 );
}


Camera::~Camera() {
}

sf::Vector2f Camera::updatePosition( Object & player, std::vector<Object>& tab, sf::Vector2f deltaPlayerX ) {
	if( abs( player.getPosition().x ) > (currentOffset.x +(SCREEN_WIDTH / 2)) ) {		// if player goes after middle of the start lvl screen
		// add delta to offset
		currentOffset += deltaPlayerX;
		// change everything pos
		for( unsigned int i = 0; i < tab.size(); i++ ) {
			tab.at( i ).changePosition( tab.at( i ).getPosition() - deltaPlayerX );
		}
		// change player pos to privious 
		player.changePosition( player.getPosition() - deltaPlayerX );
	}
	return sf::Vector2f();
}
