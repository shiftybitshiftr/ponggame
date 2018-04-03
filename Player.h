#pragma once
#include "Shape.h"

class Player :
	public Shape
{
	friend class Ball;
public:
	Player();
	~Player();

	int speed() { return 0; }

	void draw(int x, int y);

	void collisionDetect(int xCo, int yCo);

	void setY(int y);
};

