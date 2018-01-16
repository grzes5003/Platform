#include "GameManager.h"
#include <ctime>
#include <cstdlib>



void GameManager::generateLvl( std::vector<Object>& tab ) {
	tab.clear();			//make sure no trash in tab from last lvl
	
	int temp_offset;
	int startpnt = -400;

	tab.push_back( Object( sf::Vector2f( 200, 20 ), sf::Color::Blue, sf::Vector2f( -10, -800 ), 1, 1, 0 ) );
	tab.push_back( Object( sf::Vector2f( 100, 20 ), sf::Color::Blue, sf::Vector2f( -300, -700 ), 1, 1, 0 ) );

	for( unsigned int i = 0; i < 30; i++ ) {
		srand( time( NULL ) + i );
		temp_offset = -200 * i;								// if written below doesnt work
		tab.push_back( Object(
			sf::Vector2f( ((rand() % 2) == 0 ? -1 : 1)*(20) + 100, 20 ),
			sf::Color::Blue,
			sf::Vector2f( ((rand() % 2) == 0 ? -1 : 1)*((rand() % 100) + 1) + startpnt + temp_offset,
			((rand() % 2) == 0 ? -1 : 1)*((rand() % 200) + 1) - SCREEN_HEIGHT / 2 )
			, 1, 1, 0 ) );
	}
}

void GameManager::playerDead( Object & player, Camera & camera, std::vector<Object> & tab ) {
	// player points
	// reset camera
	camera.resetCamera( player, tab );
	// generate new world
	generateLvl( tab );
}

void GameManager::gameLoop() {

	sf::RenderWindow window( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "Game" );
	/////////////////////////////////////////////
	
	sf::Clock Clock;
	float fdeltaTime = 0;								// time of one frame
	
	Object player1;
	Camera camera1;

	///////////////////////////////////////////// generate lvl
	std::vector<Object> obj_tab;
	generateLvl( obj_tab );

	/////////////////////////////////////////////
	bool isSpacecClicked = false;
	
	sf::Vector2f priviousPlayerPos( player1.getPosition() );	// to make camera motion (deltaPosition)
	
	///////////////////////////////////////////// game loop
	while( window.isOpen() ) {
		
		Clock.restart();
		sf::Event event;
		while( window.pollEvent( event ) ) {
			if( event.type == sf::Event::Closed )
				window.close();
		}

		/// keyboard input
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed( sf::Keyboard::A ) ) {
				player1.changePosition( sf::Vector2f( player1.getPosition().x + MOVE_SPEED * fdeltaTime * SPEED, player1.getPosition().y ) );
		}
		else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) || sf::Keyboard::isKeyPressed( sf::Keyboard::D ) ) {
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
		
		////////////////////////////////////////////////////// update all static obj
		
		{
			Physic::simulate( player1, obj_tab, fdeltaTime );
			for( unsigned int i = 0; i < obj_tab.size(); i++ ) {
				Physic::simulate( obj_tab.at( i ), obj_tab, fdeltaTime, i );
			}
		}
		
		/////////////////////////////////////////////////////// change camera position

		camera1.updatePosition( player1, obj_tab, sf::Vector2f( -(priviousPlayerPos.x - player1.getPosition().x), 0 ) );

		priviousPlayerPos.x = player1.getPosition().x;		 // update player position
		/////////////////////////////////////////////////////// check player status (if he falls)
		if( player1.getPosition().y < -SCREEN_HEIGHT ) {
			playerDead( player1, camera1, obj_tab );
		}

		/////////////////////////////////////////////////////// draw all obj
		window.clear();
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
