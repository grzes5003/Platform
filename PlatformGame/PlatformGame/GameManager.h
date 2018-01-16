#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Object.h"
#include "Physic.h"
#include "Camera.h"

class GameManager
{
	void generateLvl( std::vector<Object> & tab);
	void playerDead( Object & player, Camera & camera, std::vector<Object> & tab );
public:	
	void gameLoop();
	GameManager();
	~GameManager();
};

