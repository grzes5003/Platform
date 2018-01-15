#include "GameManager.h"
#include <ctime>
#include <cstdlib>

#define SCREEN_WIDTH	900
#define SCREEN_HEIGHT	900

void GameManager::gameLoop() {
	sf::Clock Clock;
	float fdeltaTime = 0;								// time of one frame

	sf::RenderWindow window( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "Game" );
	/////////////////////////////////////////////
	Object player1;
	
	std::vector<Object> obj_tab;
	obj_tab.push_back(Object( sf::Vector2f( 2000, 20 ), sf::Color::Blue, sf::Vector2f( -10, -800 ), 1, 1, 0 ));
	obj_tab.push_back( Object( sf::Vector2f( 100, 20 ), sf::Color::Blue, sf::Vector2f( -300, -700 ), 1, 1, 0 ) );

	/// level generator
	int startpnt = -400; int temp_offset;
	for( unsigned int i = 0; i < 30; i++ ) {
		srand( time( NULL ) + i);
		temp_offset = -200 * i;								// if written below doesnt work
		obj_tab.push_back( Object(
			sf::Vector2f( (( rand() % 2 ) == 0 ? -1 : 1)*(20)+100, 20 ),
			sf::Color::Blue,
			sf::Vector2f( (( rand() % 2 ) == 0 ? -1 : 1)*( ( rand() % 100 ) + 1 ) + startpnt + temp_offset,
						((rand() % 2) == 0 ? -1 : 1)*((rand() % 200) + 1) - SCREEN_HEIGHT/2 )
			, 1, 1, 0 ) );
	}

	/////////////////////////////////////////////
	bool isSpacecClicked = false;
	sf::Vector2f cameraOffset( 0, 0 );
	sf::Vector2f priviousPlayerPos( player1.getPosition() );
	/////////////////////////////////////////////
	while( window.isOpen() ) {
		
		Clock.restart();
		sf::Event event;
		while( window.pollEvent( event ) ) {
			if( event.type == sf::Event::Closed )
				window.close();
		}

		/// keyboard input
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed( sf::Keyboard::A ) ) {
			//if( sf::Keyboard::isKeyPressed( sf::Keyboard::LShift ) && player1.isCollieded )
			//	player1.changePosition( sf::Vector2f( player1.getPosition().x + MOVE_SPEED * fdeltaTime * SPEED * SPEED_BOOST, player1.getPosition().y ) );
			//else
				player1.changePosition( sf::Vector2f( player1.getPosition().x + MOVE_SPEED * fdeltaTime * SPEED, player1.getPosition().y ) );
		}
		else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) || sf::Keyboard::isKeyPressed( sf::Keyboard::D ) ) {
			//if( sf::Keyboard::isKeyPressed( sf::Keyboard::LShift ) && player1.isCollieded )
			//	player1.changePosition( sf::Vector2f( player1.getPosition().x - MOVE_SPEED * fdeltaTime * SPEED * SPEED_BOOST, player1.getPosition().y ) );
			//else
				player1.changePosition( sf::Vector2f( player1.getPosition().x - MOVE_SPEED * fdeltaTime * SPEED, player1.getPosition().y ) );
		}
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) ) {
			if( player1.isCollieded && !isSpacecClicked )
				player1.velocity += sf::Vector2f( 0, 5 );
			isSpacecClicked = true;
		}
		else {
			isSpacecClicked = false;
		}
		///update all obj
		{
			Physic::simulate( player1, obj_tab, fdeltaTime );
			for( unsigned int i = 0; i < obj_tab.size(); i++ ) {
				Physic::simulate( obj_tab.at( i ), obj_tab, fdeltaTime, i );
			}
		}
		
		/// change camera position
		{
			if( player1.getPosition().x < (-SCREEN_WIDTH / 2 + 0.1*SCREEN_WIDTH) ) {
				cameraOffset.x = (priviousPlayerPos.x - player1.getPosition().x);
			}
			else
				cameraOffset.x = 0;
			for( unsigned int i = 0; i < obj_tab.size(); i++ ) {
				Physic::updatePositionToCamera( obj_tab.at( i ), cameraOffset, fdeltaTime );
			}
			priviousPlayerPos.x = player1.getPosition().x;
		}
		///
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
