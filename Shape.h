#pragma once

// Shape abstract base class. Player, Ball, and Bot will all inherit from it.
class Shape
{
public:
	Shape();
	~Shape();
	
	virtual void draw(int x, int y) = 0;

	//virtual void collisionDetect(int xCo, int yCo) = 0;
	//virtual int speed() = 0;

protected:
	int x , y;
	int color;

};

