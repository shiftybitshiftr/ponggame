#pragma once
#include "Shape.h"
#include "Player.h"
#include "Bot.h"

	class Ball :
		public Shape
	{
		friend class GameControl;
	public:
		Ball();
		~Ball();

		void draw(int x, int y);

		void move(int playerCoord, int botCoord); // moves ball, takes in player Y and bot Y for collision detection

		void setXandYandDir(int xVal, int yVal, int dirVal);

		int getX(); // returns x
		int getY(); // returns y
		int getDir(); // returns direction

		//int speed() { return 0; }
		//void collisionDetect(int xCo, int yCo) { } 
	private:

		int direction;
		int x, y;
	};

