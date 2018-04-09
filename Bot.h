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

	void draw(int x, int y);

	void difficulty(int a);

	void moveToY(int yn);                         // slide animation to move to specified Y coord

	int getY();

	void move(int ballX, int ballY, int ballDir); 
	
    //void collisionDetect(int xCo, int yCo); // it's all in moveBall
	//void tracking(int xCo, int yCo);
    //int speed();

private:

	int posX;
	int posY;
	
};

