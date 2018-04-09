#include "Bot.h"
#include "GameControl.h"
#include <windows.h>

using namespace std;

extern void PlaceCursor(const int x, const int y);

Bot::Bot()
{
	posY = 11;
	posX = 0;

	draw(posX, posY);
}


Bot::~Bot()
{
}

int Bot::getY()
{
	return posY;
}

void Bot::draw(int x, int y)
{
	x = 0;
	char paddle = 219;

	PlaceCursor(x, y);
	cout << paddle << endl;
	cout << paddle << endl;
	cout << paddle << endl;
	cout << paddle << endl;
}

void Bot::difficulty(int a) //Set movement patterns for bot difficulty
{
	//Default difficulty of 1
	if (a == 1)
	{
		//first command to go to bottom of gameplay area
		moveToY(0);
		moveToY(26);
		moveToY(0);
		moveToY(15);
		moveToY(26);
		moveToY(15);
		moveToY(0);
	}
	
	else if( a == 2)
	{
		//Difficulty level 2
		moveToY(15);
		moveToY(26);
		moveToY(0);
		moveToY(7);
		moveToY(20);
		moveToY(15);
	}
	
	else if( a == 3)
	{
		//Difficulty level 3
		moveToY(6);
		moveToY(16);
		moveToY(6);
		moveToY(16);
		moveToY(0);
		moveToY(26);
		moveToY(15);
		moveToY(0);
		moveToY(16);
	}

	else if (a == 4)
	{
		//Difficulty level 4 Hard Mode
		moveToY(20);
		moveToY(10);
		moveToY(15);
		moveToY(8);
		moveToY(22);
		moveToY(15);
		moveToY(0);
		moveToY(15);
		moveToY(20);
		moveToY(10);
	}
	
	if(a < 1)
		{
		cout << "Incorrect Difficulty setting \n";
		cout << "Please enter another Difficulty setting between 1-4\n";
		//options();
		}
	
	if(a > 4)
		{
		cout << "Incorrect Difficulty setting \n";
		cout << "Please choose a Difficulty between 1 and 4\n";
		//options();
		}
}

void Bot::moveToY(int yn)
{
	int i = posY;

	//function to move the paddle until it is in the new position
	while (i != yn)
	{
		if (yn > posY)
		{
			draw(posX, ++i);
		}
		else if (yn < posY)
		{
			draw(posX, --i);
		}
	}
	posY = y;
}

void Bot::move(int ballX, int ballY, int ballDir, int difficulty)
{
	int boardcheck = 0;

	if (difficulty == 1)
	{ 
		boardcheck = 11;
	}
	else if (difficulty == 2)
	{
		boardcheck = 21;
	}
	else if (difficulty == 3)
	{
		boardcheck = 33;
	}
	else if (difficulty == 4)
	{
		boardcheck = 41;
	}


	if (ballX <= boardcheck) // half way across the board check. maybe adjust this for different difficulty settings.
	{
		// ball is going < ^
		if (ballDir == 3)
		{
			// if ball Y is less than our paddle Y and we're below upper bound
			if (ballY < posY && posY > 2)
			{
				// and move 2 spaces. adjust this for different difficulty settings.
				posY -= 2;
			}
			// don't want to phase into the border
			else if (posY > 2)
			{
				posY -= 1;
			}
		}
		else if (ballDir == 4)
		{
			if (ballY > (posY + 3) && posY < 17)
			{
				
					posY += 2;
			}
			// don't want to phase into the border
			else if (posY < 18) 
			{
					posY += 1;
			}
		}
		
	}
	// random movement when past half way point
	else if (ballX >= (boardcheck +1))
	{
		if (ballDir == 2)
		{
			if (posY > 2 && posY < 17)
			{
				posY -= 2;

				posY += 3;
			}
		}
		else if (ballDir == 4)
		{
			if (posY > 2 && posY < 17)
			{
				posY -= 1;

				posY += 3;
			}
		}
	}
}