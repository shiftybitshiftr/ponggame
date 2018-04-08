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

	void collisionDetect(int xCo, int yCo); // don't end up using this, it's all in moveBall

	void moveToY(int yn);                   // this used to be the move function, currently not using it

	int getY();

	void move(int ballX, int ballY, int ballDir); // just one difficulty. need to update logic for different difficulties, otherwise just go back to old difficulty settings of random movement.

private:

	int posX;
	int posY;
	
};

