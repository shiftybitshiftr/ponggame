#pragma once
#include "Shape.h"
#include <iostream>

class Player :
	public Shape
{
	friend class Ball;
	//friend class GameControl;

public:
	Player();
	~Player();

	int speed() { return 0; }

	void draw(int x, int y);

	void collisionDetect(int xCo, int yCo); // don't end up using this, it's all in moveBall

	void setY(int y);

	void movePlayer();

	int getY();

	void setInput(char in);

	//static void inputThread(void *p_this);  // bugged
	//void receiveInput();                    // bugged

private:
	int posX;
	int posY;
	int tick; // increment this for every movement
	char input; // holding player movement command UP or DOWN
};

