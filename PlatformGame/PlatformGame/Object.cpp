#include "Object.h"



void Object::loadTexture() {
	currentImage.x = 0;
	currentImage.y = 0;
	imageCount.x  = 3;
	imageCount.y = 3;
	switchTime = 0.3f;

	texture = new sf::Texture();
	//C://Users/Grzes/Source/Repos/Platform/PlatformGame/Debug/
	texture->loadFromFile( "sprites/sprites_final.png" ); // TODO change to relative dir
	texture->setSmooth( true );

	shapeptr->setTexture( texture );

	textureSize = texture->getSize();
	textureSize.x /= imageCount.x;
	textureSize.y /= imageCount.y;

	uvRect.width  = textureSize.x;
	uvRect.height = textureSize.y;
	
	shapeptr->setTextureRect( uvRect );
}

void Object::updateAnimation( float deltaTime, int animType, bool faceRight ) {
	//
	//	0 - idle anim
	//	1 - jump anim
	//	2 - run  anim
	//
	currentImage.x;
	deltaFromChange += deltaTime;

	if( animType == 0 ) {
		currentImage.y = 0;
	}
	else if( animType == 1 ) {
		currentImage.y = 1;
	}
	else {
		currentImage.y = 2;
	}
	
	if( deltaFromChange >= switchTime ) {
		
		deltaFromChange -= switchTime;

		currentImage.x++;

		if( currentImage.x >= imageCount.x ) {
			currentImage.x = 0;
		}
	}

	uvRect.top = currentImage.y * uvRect.height;

	if( faceRight ) {
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs( uvRect.width );
	}
	else {
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs( uvRect.width );
	}

	shapeptr->setTextureRect( uvRect );
}

void Object::drawObj( sf::RenderWindow & window ) {
	shapeptr->setPosition( -sf::Vector2f( position.x, position.y ) );		// make sure position is most recent
	window.draw( *shapeptr );
}

void Object::changePosition( sf::Vector2f newpos ) {
	position = newpos;
}

sf::Vector2f Object::getSize() {
	return shapeptr->getSize();
}

sf::Vector2f Object::getPosition() {
	return position;
}

Object::Object() {
	shapeptr = new sf::RectangleShape( sf::Vector2f( 50, 100 ) );			/// for player
	shapeptr->setPosition( position.x, position.y );
	isCollieded = false;
	isPlayer = 1;
}

Object::Object( sf::RectangleShape sptr ) {									/// doesnt work for some reason
	shapeptr = &sptr;			
	isCollieded = false;
	isPlayer = 0;
}

Object::Object( sf::Vector2f sizee, sf::Color color, sf::Vector2f pos, bool isStat, bool isPhy, bool isPlay ) {	/// for other obj in game
	shapeptr = new sf::RectangleShape( sizee );
	shapeptr->setFillColor( color );
	shapeptr->setPosition( pos );
	position = pos;
	isStatic = isStat;
	_isPhysical = isPhy;
	isCollieded = false;
	isPlayer = isPlay;
}


Object::~Object() {
}
