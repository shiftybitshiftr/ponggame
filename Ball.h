	#pragma once
	#include "Shape.h"
#include "Player.h"
#include "Bot.h"
	class Ball :
		public Shape
	{
	public:
		Ball();
		~Ball();

		int speed() { return 0; }
		void draw(int x, int y);

		void collisionDetect(int xCo, int yCo) { } 
		void Move();
		void setXandY(int xVal, int yVal);
		bool WinCondition(Player & x, Bot & y);
	private:

		//int prevX, prevY;


	};

