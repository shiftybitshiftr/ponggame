#pragma once
#include "Shape.h"

class Player :
	public Shape
{
public:
	Player();
	~Player();

	int speed() { return 0; }

	void draw(int x, int y);

	void collisionDetect(int xCo, int yCo);

};

