#pragma once
#include <SFML/Graphics.hpp>
#include "pos.h"

class Ridigbody
{
protected:
	bool _isPhysical;				// if physical attributes 1, otherw 0
	sf::Vector2f position;					// position of ridigbody in pixels from left up corner
	float mass;						// mass of the object (if not physical doesnt matter)
public:
	sf::Vector2f velocity;
	bool isStatic;					// weather can object move or not
	Ridigbody();
	Ridigbody(sf::Vector2f _pos, float _mass) {
		position = _pos;
		mass = _mass;
		isStatic = false;
		velocity = sf::Vector2f(0, 0);
	}
	bool isPhysical();				// returns weather obj is physical or not
	~Ridigbody();
};

