#include "Dialogue.h"



void Dialogue::showDialogue( int dtype, sf::RenderWindow & window ) {
	while( !sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) ){
		if( dtype == 0 ) {		// start window
			text.setString( start );
			text.setPosition( SCREEN_HEIGHT / 2 - 4.5 * fontSize, SCREEN_WIDTH / 2 - fontSize );
		}
		else if( dtype == 1 ) {
			text.setString( restart );
			text.setPosition( SCREEN_HEIGHT / 2 - 5 * fontSize, SCREEN_WIDTH / 2 - fontSize );
		}
		else if( dtype == 2 ) {
			text.setString( win );
			text.setPosition( SCREEN_HEIGHT / 2 - 5 * fontSize, SCREEN_WIDTH / 2 - fontSize );
		}
		else if( dtype == 3 ) {
			text.setString( late );
			text.setPosition( SCREEN_HEIGHT / 2 - 5 * fontSize, SCREEN_WIDTH / 2 - fontSize );
		}
		window.clear();
		window.draw( text );
		window.display();
	}
}

Dialogue::Dialogue() {
	font.loadFromFile( "sprites/font.otf" );
	fontSize = 50;

	text.setFont( font );
	text.setCharacterSize( fontSize );
	text.setFillColor( sf::Color( 128, 128, 0 ) );
	

	start = "To start press space";
	late = "          It's to late \n To restart press space";
	win = "          You Won \n To restart press space";
	restart = "   You broke your leg \n to restart press space";

}


Dialogue::~Dialogue() {
}
