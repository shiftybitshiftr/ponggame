#pragma once
#include "Shape.h"
#include <iostream>

class Player :
	public Shape
{
	friend class Ball;

public:
	Player();
	~Player();

	void draw(int x, int y);

	void setY(int y);

	void setInput(char in);

	void move();

	int getY();

	char getInput();

	//static void inputThread(void *p_this);  
	//void receiveInput(); 

	//int speed() { return 0; }
	//void collisionDetect(int xCo, int yCo);

private:
	int posX;
	int posY;
	
	char input; // holding player movement command UP or DOWN
	//int tick; // increment this for every movement (for multithreading)
};

