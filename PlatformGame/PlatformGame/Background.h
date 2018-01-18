#pragma once
#include "Object.h"
class Background
{
	sf::Texture texture1, texture2;
	sf::RectangleShape shape1, shape2;

	int levelDistance;
public:
	void loadTexture();
	void displayTextures( sf::RenderWindow & window );
	void animateTextures( sf::Vector2f deltaPosition );
	void setLevelDistance( int lvlD );
	void resetPosition();

	Background();
	~Background();
};

