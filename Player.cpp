#include "Player.h"
#include <iostream>

using namespace std;
//#include "Source.cpp"

extern void PlaceCursor(const int x, const int y);

Player::Player()
{
}


Player::~Player()
{
}

void Player::collisionDetect(int xCo, int yCo)
{

}

void Player::draw(int x, int y)
{
	char paddle = 219;

	PlaceCursor(x, y);
	cout << paddle << endl;
	cout << paddle << endl;
	cout << paddle << endl;
	cout << paddle << endl;

}