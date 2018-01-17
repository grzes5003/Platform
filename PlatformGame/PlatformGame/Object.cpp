#include "Object.h"



void Object::loadTexture() {
	currentImage.x = 0;
	currentImage.y = 0;
	imageCount.x  = 3;
	imageCount.y = 1;
	switchTime = 0.3f;

	texture = new sf::Texture();
	texture->loadFromFile( "C://Users/Grzes/Source/Repos/Platform/PlatformGame/Debug/sprites/idle2.png" );
	texture->setSmooth( true );

	shapeptr->setTexture( texture );

	textureSize = texture->getSize();
	textureSize.x /= imageCount.x;
	textureSize.y /= imageCount.y;

	uvRect.width  = textureSize.x;
	uvRect.height = textureSize.y;
	
	shapeptr->setTextureRect( uvRect );
}

void Object::updateAnimation( float deltaTime ) {
	currentImage.x;
	deltaFromChange += deltaTime;
	
	if( deltaFromChange >= switchTime ) {
		
		deltaFromChange -= switchTime;

		currentImage.x++;

		if( currentImage.x >= imageCount.x ) {
			currentImage.x = 0;
		}
	}
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;

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
	shapeptr = new sf::RectangleShape( sf::Vector2f( 80, 100 ) );			/// for player
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
