#pragma once
#include "Shape.h"
class Bot :
	public Shape
{
public:
	Bot();
	~Bot();

	int speed();

	void draw(int x, int y);

	void difficulty(int a);

	void tracking(int xCo, int yCo);

	void collisionDetect(int xCo, int yCo);


};

