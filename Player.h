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

	int speed() { return 0; } // didn't end up using this

	void draw(int x, int y);

	void collisionDetect(int xCo, int yCo); // didn't end up using this, it's all in moveBall

	void setY(int y);

	void setInput(char in);

	void movePlayer();

	int getY();

	char getInput();

	//static void inputThread(void *p_this);  // bugged
	//void receiveInput();                    // bugged

private:
	int posX;
	int posY;
	//int tick; // increment this for every movement (for multithreading)
	char input; // holding player movement command UP or DOWN
};

