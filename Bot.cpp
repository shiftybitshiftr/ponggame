#include "Bot.h"
//#include "Source.cpp"

using namespace std;

extern void PlaceCursor(const int x, const int y);

Bot::Bot()
{
	posY = 15;
	posX = 119;

	draw(posX, posY);

}


Bot::~Bot()
{
}

void Bot::draw(int x, int y)
{
	x = 119;
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

void Bot::difficulty(int a) //Set movement patterns for bot difficulty
{
	//Default difficulty of 1
	if (a == 1)
	{
		//first command to go to bottom of gameplay area
		moveBot(0);
		moveBot(26);
		moveBot(0);
		moveBot(15);
		moveBot(26);
		moveBot(15);
		moveBot(0);
	}
	
	else if( a == 2)
	{
		//Difficulty level 2
		moveBot(15);
		moveBot(26);
		moveBot(0);
		moveBot(7);
		moveBot(20);
		moveBot(15);
	}
	
	else if( a == 3);
	{
		//Difficulty level 3
		moveBot(6);
		moveBot(16);
		moveBot(6);
		moveBot(16);
		moveBot(0);
		moveBot(26);
		moveBot(15);
		moveBot(0);
		moveBot(16);
	}
	
	else( a == 4);
	{
		//Difficulty level 4 Hard Mode
		moveBot(20);
		moveBot(10);
		moveBot(15);
		moveBot(8);
		moveBot(22);
		moveBot(15);
		moveBot(0);
		moveBot(15);
		moveBot(20);
		moveBot(10);
	}
	
	if(a < 1)
		{
		cout << "Incorrect Difficulty setting \n";
		cout << "Please enter another Difficulty setting imbetween 1-4\n";
		options();
		}
	
	if(a > 4)
		{
		cout << "Incorrect Difficulty setting \n";
		cout << "Please choose a Difficulty between 1 and 4\n";
		options();
		}
}

void Bot::tracking(int x, int y)
{
	
}

void Bot::collisionDetect(int xCo, int yCo)
{

}

void Bot::moveBot(int yn)
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
