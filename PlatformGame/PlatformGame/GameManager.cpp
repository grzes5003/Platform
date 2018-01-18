#include "GameManager.h"
#include <ctime>
#include <cstdlib>



void GameManager::showTimer( sf::RenderWindow & window ) {
	timeFromStart -= timer.getElapsedTime().asSeconds()*10;
	// conversion from float to string
	std::ostringstream sstring;
	sstring << "Time to exam: "<< timeFromStart;
	sf::String sTime = std::string( sstring.str() );

	sf::Text text; text.setString( sTime );
	text.setFont( dialogue1.font );
	
	window.draw( text );
}

void GameManager::generateLvl( std::vector<Object>& tab ) {
	tab.clear();			//make sure no trash in tab from last lvl
	
	int temp_offset;
	int startpnt = -400;	// offset from two firsth platforms
	
	levelTime = 70;
	timeFromStart = levelTime;

	tab.push_back( Object( sf::Vector2f( 200, 20 ), sf::Color( 120, 128, 150 ), sf::Vector2f( -10, -800 ), 1, 1, 0 ) );
	tab.push_back( Object( sf::Vector2f( 100, 20 ), sf::Color( 120, 128, 150 ), sf::Vector2f( -300, -700 ), 1, 1, 0 ) );

	for( unsigned int i = 0; i < 30; i++ ) {
		srand( time( NULL ) + i );
		temp_offset = -200 * i;								// if written below doesnt work
		tab.push_back( Object(
			sf::Vector2f( ((rand() % 2) == 0 ? -1 : 1)*(20) + 100, 20 ),
			sf::Color(120,128,150),
			sf::Vector2f( ((rand() % 2) == 0 ? -1 : 1)*((rand() % 100) + 1) + startpnt + temp_offset,
			((rand() % 2) == 0 ? -1 : 1)*((rand() % 200) + 1) - SCREEN_HEIGHT / 2 )
			, 1, 1, 0 ) );
	}
}

void GameManager::playerDead( Object & player, Camera & camera, std::vector<Object> & tab ) {
	// player time
	timer.restart();
	// reset camera
	camera.resetCamera( player, tab );
	// reset bcg
	bcg1.resetPosition();
	// generate new world
	generateLvl( tab );
	// set lvl distance to bcg class
	bcg1.setLevelDistance( abs(tab.at( tab.size() - 1 ).getPosition().x) );
}

void GameManager::gameLoop() {

	sf::Image icon;
	icon.loadFromFile( "sprites/icon.png" );

	sf::RenderWindow window( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "SesjaWarrior v1.0" );
	window.setIcon( icon.getSize().x, icon.getSize().y, icon.getPixelsPtr() );
	/////////////////////////////////////////////
	
	sf::Clock Clock;
	float fdeltaTime = 0;								// time of one frame
	
	int currentAnim = 0;								// var for animation
	bool faceRight = true;								// to define mirror of texture
	
	bool isStart = true;								// status of player (to show start menu)

	Object player1;
	Camera camera1;
	
	

	sf::String	metaString = "META";
	sf::Text	metaText;
	metaText.setFont( dialogue1.font );
	metaText.setCharacterSize( 30 );

	player1.loadTexture();

	///////////////////////////////////////////// generate lvl
	std::vector<Object> obj_tab;
	generateLvl( obj_tab );
	bcg1.setLevelDistance( abs( obj_tab.at( obj_tab.size() - 1 ).getPosition().x ) );

	/////////////////////////////////////////////
	bool isSpacecClicked = false;
	
	sf::Vector2f priviousPlayerPos( player1.getPosition() );	// to make camera motion (deltaPosition)
	

	timer.restart();						   // starting game - restarting timer
	///////////////////////////////////////////// game loop
	while( window.isOpen() ) {

		///////////////////////////////////////// start of game (start window)
		if( isStart ) {
			dialogue1.showDialogue( 0, window );
			isStart = 0;
		}
		/////////////////////////////////////////

		Clock.restart();
		timer.restart();

		sf::Event event;
		while( window.pollEvent( event ) ) {
			if( event.type == sf::Event::Closed )
				window.close();
		}

		/// keyboard input
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed( sf::Keyboard::A ) ) {
				faceRight = false;
				currentAnim = 2;
				player1.changePosition( sf::Vector2f( player1.getPosition().x + MOVE_SPEED * fdeltaTime * SPEED, player1.getPosition().y ) );
		}
		else if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) || sf::Keyboard::isKeyPressed( sf::Keyboard::D ) ) {
				faceRight = true;
				currentAnim = 2;
				player1.changePosition( sf::Vector2f( player1.getPosition().x - MOVE_SPEED * fdeltaTime * SPEED, player1.getPosition().y ) );
		}
		if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) ) {
			if( player1.isCollieded && !isSpacecClicked ) {
				player1.velocity += sf::Vector2f( 0, 5 );
				currentAnim = 1;
			}
			isSpacecClicked = true;
		}
		else {
			isSpacecClicked = false;
		}
		////////////////////////////////////////////////////// idle state
		if( !sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) && !sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) &&
			!sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) && !sf::Keyboard::isKeyPressed( sf::Keyboard::A ) &&
			!sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) && !sf::Keyboard::isKeyPressed( sf::Keyboard::D ) ) {
			currentAnim = 0;
		}

		////////////////////////////////////////////////////// update all static obj
		
		{
			Physic::simulate( player1, obj_tab, fdeltaTime );
			for( unsigned int i = 0; i < obj_tab.size(); i++ ) {
				Physic::simulate( obj_tab.at( i ), obj_tab, fdeltaTime, i );
			}
		}
		
		/////////////////////////////////////////////////////// change camera position

		camera1.updatePosition( player1, obj_tab, bcg1, sf::Vector2f( -(priviousPlayerPos.x - player1.getPosition().x), 0 ) );

		//bcg1.animateTextures( sf::Vector2f( -(priviousPlayerPos.x - player1.getPosition().x), 0 ), fdeltaTime );			 // update bcg positions

		priviousPlayerPos.x = player1.getPosition().x;		 // update player position
		/////////////////////////////////////////////////////// check player status (if he falls, or wins)
		if( player1.getPosition().y < -SCREEN_HEIGHT ) {
			dialogue1.showDialogue( 1, window );
			playerDead( player1, camera1, obj_tab );
		}
		if( player1.getPosition().x <= obj_tab.at( obj_tab.size() - 1 ).getPosition().x ) {
			dialogue1.showDialogue( 2, window );
			playerDead( player1, camera1, obj_tab );
		}
		if( timeFromStart <= 0 ) {
			dialogue1.showDialogue( 3, window );
			playerDead( player1, camera1, obj_tab );
		}
		/////////////////////////////////////////////////////// animate player
		{
			player1.updateAnimation( fdeltaTime, currentAnim, faceRight );
		}
		/////////////////////////////////////////////////////// draw all obj
		window.clear();

		bcg1.displayTextures( window );	
		showTimer( window );

		metaText.setPosition( -obj_tab.at( obj_tab.size() - 1 ).getPosition().x,
			-obj_tab.at( obj_tab.size() - 1 ).getPosition().y + 10 );
		window.draw( metaText );

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
	timeFromStart = 0;
}


GameManager::~GameManager() {
}
