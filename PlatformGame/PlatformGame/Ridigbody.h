#pragma once
#include <SFML/Graphics.hpp>
#include "pos.h"

class Ridigbody
{
protected:
	bool _isPhysical;				// if physical attributes 1, otherw 0
	pos position;					// position of ridigbody in pixels from left up corner
	float mass;						// mass of the object (if not physical doesnt matter)
public:
	bool isStatic;					// weather can object move or not
	Ridigbody();
	Ridigbody(pos _pos, float _mass) {
		position = _pos;
		mass = _mass;
	}
	bool isPhysical();				// returns weather obj is physical or not
	~Ridigbody();
};

