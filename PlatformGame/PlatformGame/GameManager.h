#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Object.h"
#include "Physic.h"
#include "Camera.h"

class GameManager
{
public:

	
	void gameLoop();
	GameManager();
	~GameManager();
};

