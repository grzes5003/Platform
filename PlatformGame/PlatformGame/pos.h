#pragma once
struct pos {
	int x;
	int y;
	pos() { y = 0; x = 0; }
	pos( float _x, float _y ) { x = _x; y = _y; }
};