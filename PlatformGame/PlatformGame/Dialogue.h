#pragma once
#include "Object.h"

class Dialogue
{
public:
	sf::Font font;
	sf::Text text;

	void showDialogue( int dtype, sf::RenderWindow & window );
private:
	sf::String start, restart, win;
	int fontSize;
public:
	Dialogue();
	~Dialogue();
};

