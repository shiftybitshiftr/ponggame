#pragma once
#include "Shape.h"
#include <iostream>

class Bot :
	public Shape
{
	friend class Ball;
public:
	Bot();
	~Bot();

	int speed();

	void draw(int x, int y);

	void difficulty(int a);

	void tracking(int xCo, int yCo);

	void collisionDetect(int xCo, int yCo);

	
};

