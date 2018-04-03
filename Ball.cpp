#include "Ball.h"
//#include "Source.cpp"
#include <iostream>
using namespace std;

extern void PlaceCursor(const int x, const int y);
Ball::Ball()
{
}

Ball::~Ball()
{
}

bool Ball::WinCondition(Player & xplayer, Bot &yplayer )
{
	
	if (x == 1 || x == 79)
	{
		if (xplayer.y != y && (xplayer.y)+1 != y && (xplayer.y)+2 != y && (xplayer.y)+3 != y)
		{
			return true;
		}
	}
	return false;
}
void Ball::draw(int xVal, int yVal)
{
	char ball = 254; 
	PlaceCursor(x, y);
	cout << ball;
}
void Ball::Move()
{
	int Xcondition = 1;
	int Ycondition = 1;

	if (x == 1)
	{
		Xcondition = 1;
	}
	else if (x == 79)
	{
		Xcondition = 2;
	}
	else if (y == 1)
	{
		Ycondition = 2;
	}
	else if (y == 21)
	{
		Ycondition = 1;
	}
	switch (Ycondition)
	{
	case 1:
		x++;
		break;
	case 2:
		x--;
		break;
	}
	switch (Xcondition)
	{
	case 1:
		y++;
		break;
	case 2:
		y--;
		break;
	}
	
}

void Ball::setXandY(int xVal, int yVal)
{
	x = xVal;
	y = yVal;
}