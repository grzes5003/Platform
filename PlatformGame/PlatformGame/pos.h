#pragma once

#define SCREEN_WIDTH	900
#define SCREEN_HEIGHT	900


struct pos {
	int x;
	int y;
	pos() { y = 0; x = 0; }
	pos( float _x, float _y ) { x = _x; y = _y; }
};