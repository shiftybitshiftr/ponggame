#include "Bot.h"
//#include "Source.cpp"

using namespace std;

extern void PlaceCursor(const int x, const int y);

Bot::Bot()
{
}


Bot::~Bot()
{
}

void Bot::draw(int x, int y)
{
	char paddle = 219;

	PlaceCursor(x, y);
	cout << paddle << endl;
	cout << paddle << endl;
	cout << paddle << endl;
	cout << paddle << endl;

}

int Bot::speed()
{
	return 0;
}

void Bot::difficulty(int a)
{

}

void Bot::tracking(int x, int y)
{

}

void Bot::collisionDetect(int xCo, int yCo)
{

}