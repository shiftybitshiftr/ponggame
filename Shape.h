#pragma once
class Shape
{
public:
	Shape()
	{
		x = 0;
		y = 0;
		color = 0;
	}
	~Shape();

	virtual int speed() = 0;
	
	virtual void draw(int x, int y) = 0;

	virtual void collisionDetect(int xCo, int yCo) = 0;

private:
	int x , y;
	int color;

};

