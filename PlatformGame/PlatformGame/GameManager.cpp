#include "GameManager.h"



void GameManager::gameLoop() {
	sf::Clock Clock;
	float timeElapsed = 0;								// time of one frame

	sf::RenderWindow window( sf::VideoMode( 200, 900 ), "Game" );

	Object obj1;

	while( window.isOpen() ) {
		sf::Event event;
		while( window.pollEvent( event ) ) {
			if( event.type == sf::Event::Closed )
				window.close();
		}

		window.clear();
		Physic::simulate( obj1, timeElapsed );
		obj1.drawObj( window );
		window.display();
		timeElapsed = Clock.getElapsedTime().asMilliseconds();
		Clock.restart();
	}
}

GameManager::GameManager() {
}


GameManager::~GameManager() {
}
