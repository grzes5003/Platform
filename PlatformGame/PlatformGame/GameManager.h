#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Object.h"
#include "Physic.h"
#include "Camera.h"
#include "Dialogue.h"
#include "Background.h"
#include <sstream>

class GameManager
{
	Background bcg1;
	Dialogue dialogue1;

	float levelTime;		// time to finish level
	sf::Clock timer;
	float timeFromStart;

	void showTimer(sf::RenderWindow & window);
	void generateLvl( std::vector<Object> & tab);
	void playerDead( Object & player, Camera & camera, std::vector<Object> & tab );
public:	
	void gameLoop();
	GameManager();
	~GameManager();
};

