	#pragma once
	#include "Shape.h"
	class Ball :
		public Shape
	{
	public:
		Ball();
		~Ball();

		int speed() { return 0; }
		void draw(int x, int y);

		void collisionDetect(int xCo, int yCo) { } 


	private:

		int prevX, prevY;


	};

