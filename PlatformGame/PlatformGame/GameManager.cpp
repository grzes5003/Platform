#include "GameManager.h"



void GameManager::gameLoop() {
	sf::Clock Clock;
	float fdeltaTime = 0;								// time of one frame

	sf::RenderWindow window( sf::VideoMode( 200, 900 ), "Game" );
	/////////////////////////////////////////////
	Object player1;
	
	std::vector<Object> obj_tab;
	obj_tab.push_back(Object( sf::Vector2f( 100, 20 ), sf::Color::Blue, sf::Vector2f( 0, -800 ), 1, 1 ));

	/////////////////////////////////////////////
	while( window.isOpen() ) {
		
		Clock.restart();
		sf::Event event;
		while( window.pollEvent( event ) ) {
			if( event.type == sf::Event::Closed )
				window.close();
		}

		///update all obj
		{
			Physic::simulate( player1, obj_tab, fdeltaTime );
			for( unsigned int i = 0; i < obj_tab.size(); i++ ) {
				Physic::simulate( obj_tab.at( i ), obj_tab, fdeltaTime, i );
			}
		}
		


		window.clear();
		///draw all obj
		{
			player1.drawObj( window );
			for( unsigned int i = 0; i < obj_tab.size(); i++ ) {
				obj_tab.at( i ).drawObj( window );
			}
		}
		window.display();
		fdeltaTime = Clock.getElapsedTime().asSeconds();
	
	}
	/////////////////////////////////////////////
}

GameManager::GameManager() {
}


GameManager::~GameManager() {
}
