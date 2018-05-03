#include "Player.h"
#include <iostream>
#include <conio.h>
#include <process.h>
#include <windows.h>

using namespace std;

extern void PlaceCursor(const int x, const int y);

Player::Player()
{
	posY = 11;
	posX = 79;

	draw(posX, posY);
}


Player::~Player()
{
}

void Player::setInput(char in)
{
	input = in;
}

char Player::getInput()
{
	return input;
}

int Player::getY()
{
	return posY;
}

void Player::setY(int yVal)
{
	y = yVal;
}
void Player::draw(int x, int y)
{
	x = 79;
	char paddle = 219;

	PlaceCursor(x, y);
	cout << paddle << endl;
	PlaceCursor(x, y+1);
	cout << paddle << endl;
	PlaceCursor(x, y+2);
	cout << paddle << endl;
	PlaceCursor(x, y+3);
	cout << paddle << endl;

}

void Player::move()
{
	/* multithreading issues: 
	_beginthread can only accept a normal function pointer, not a pointer to class member, which means that Incoming must be either a regular function or a static class member
	there are workarounds. figuring that out. 
	
	WORST CASE: put it into a normal function?? make a setY?? */

	//tick = 0;
	////This is the handle to our thread that the system gives us when thread is created
	//HANDLE threadHandle;

	////Creates our thread, pass static_run function and whole object as parameter
	////See: https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/beginthread-beginthreadex
	//myhandleA = (HANDLE)_beginthread(&Player::inputThread, 0, this);

	////Waits until the our thread is in the signaled state or the time-out interval elapses
	////See: https://msdn.microsoft.com/en-us/library/windows/desktop/ms687032(v=vs.85).aspx
	//WaitForSingleObject(threadHandle, 50);

	//if (tick == 1)
	//{
		// 72 is up, 80 is down
		//if (this->input == 0xE0) // nothing in input yet
		//{
		if (_kbhit())
		{
			this->input = _getch();
			switch (this->input)
			{
			case 72: // UP arrow
				if (posY > 2)
				{
					posY -= 2;
				}
				else if (posY > 1)
				{
					posY -= 1;
				}
				break;
			case 80: // DOWN arrow
				if (posY < 17)
				{
					posY += 2;
				}
				else if (posY < 18)
				{
					posY += 1;
				}
				break;
			}
		}
		//}
	//}
}

////_beginthread only accepts a normal function pointer (not pointer to class member) so this must be static
//void Player::inputThread(void *p_this)
//{
//	// we'll pass this instance of the player object as a paramter to the static function
//	Player* p_Player = static_cast<Player*>(p_this);
//	p_Player->receiveInput(); // non static member function that gets our input
//}

//void Player::receiveInput()
//{
//	input = _getch();
//	tick++;
//}
