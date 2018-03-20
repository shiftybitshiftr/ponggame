#pragma once
class Shape
{
public:
	Shape();
	~Shape();

	virtual int speed() = 0;
	
	virtual void draw(int x, int y) = 0;

	virtual void collisionDetect(int xCo, int yCo) = 0;

private:
	int x , y;
	int color;

};

