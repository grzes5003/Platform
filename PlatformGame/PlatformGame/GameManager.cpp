#include "GameManager.h"



void GameManager::gameLoop() {
	
	sf::RenderWindow window( sf::VideoMode( 200, 200 ), "Game" );

	Object obj1;

	while( window.isOpen() ) {
		sf::Event event;
		while( window.pollEvent( event ) ) {
			if( event.type == sf::Event::Closed )
				window.close();
		}

		window.clear();
		obj1.drawObj( window );
		window.display();
	}
}

GameManager::GameManager() {
}


GameManager::~GameManager() {
}
