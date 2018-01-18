#include "Background.h"



void Background::loadTexture() {
	if( !texture1.loadFromFile( "C://Users/Grzes/Source/Repos/Platform/PlatformGame/Debug/sprites/agh2_big.png" ) ) {
		int i = 6; 
		i = 8;
	}
	texture2.loadFromFile( "C://Users/Grzes/Source/Repos/Platform/PlatformGame/Debug/sprites/trees_big.png" );

	texture2.setSmooth( true );
	texture1.setSmooth( true );

	texture1.setRepeated( true );
	texture2.setRepeated( true );

	shape1 = sf::RectangleShape( sf::Vector2f( texture1.getSize() ) );
	shape2 = sf::RectangleShape( sf::Vector2f( texture2.getSize().x, texture2.getSize().y/2 ) );

	shape2.setPosition( 0, SCREEN_HEIGHT / 2 );

	shape1.setTexture( &texture1 );
	shape2.setTexture( &texture2 );
}

void Background::displayTextures( sf::RenderWindow & window ) {
	window.draw( shape1 );
	window.draw( shape2 );
}

void Background::animateTextures( sf::Vector2f deltaPosition ) {
	sf::Vector2f currentPos = shape1.getPosition();

	shape1.setPosition( sf::Vector2f( (currentPos.x + (deltaPosition.x / levelDistance)*texture1.getSize().x),
		currentPos.y ));

	currentPos = shape2.getPosition();
	shape2.setPosition( sf::Vector2f( (currentPos.x + (deltaPosition.x / levelDistance)*texture2.getSize().x),
		currentPos.y ) );
}

void Background::setLevelDistance( int lvlD ) {
	levelDistance = lvlD;
}

void Background::resetPosition() {
	shape1.setPosition( 0, 0 );
	shape2.setPosition( 0, SCREEN_HEIGHT/2 );
}

Background::Background() {
	loadTexture();
}


Background::~Background() {
}
