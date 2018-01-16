#pragma once
#include "Object.h"

class Camera
{
private:
	sf::Vector2f startPosition;
	sf::Vector2f currentOffset;		// current camera offset 
	sf::Vector2f deltaOffset;		// change in position from last frame
public:
	Camera();
	~Camera();

	sf::Vector2f updatePosition(Object & player, std::vector<Object> & tab, sf::Vector2f deltaPlayerX);
};

