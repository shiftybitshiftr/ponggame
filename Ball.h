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

		int speed() { return 0; } // dont think we end up using this

		void draw(int x, int y);

		void collisionDetect(int xCo, int yCo) { } // collision detection ended up getting written inside moveBall, this is empty

		void moveBall(int playerCoord, int botCoord); // moves ball, takes in player Y and bot Y for collision detection

		void setXandYandDir(int xVal, int yVal, int dirVal);

		int getX(); // returns x
		int getY(); // returns y
		int getDir(); // returns direction

		//int WinCondition(Player x, Bot y);  // ended up putting this in GameControl

	private:

		//int prevX, prevY;
		int direction;
		int x, y;
	};

