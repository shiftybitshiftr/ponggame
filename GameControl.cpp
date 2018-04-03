#include "GameControl.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <iostream>
//#include "Source.cpp"

using namespace std;

extern void PlaceCursor(const int x, const int y);


GameControl::GameControl()
{
	vict = 10;
	score = 0;

	for (int i = 0; i < 11;i++)
	{
		leaderboard[i] = 0;
	}
}

GameControl::~GameControl()
{
}

//function called when user chooses to start playing the actual game
void GameControl::start()
{

	const char paddle = 219;
	const char ball = 254;

	//values to ensure the paddle does not move offscreen
	int index;
	const int scrBottom = 45;

	//values to catch position of cursor
	int posx = 0;
	int posy = 0;
	//value to hold user input
	int input;
	//boolean value to check whether end program button was pressed and exit program
	bool check = true;

	//check user input
	input = _getch();

	//while loop to continue running unless escape is pressed
	while (check == true)
	{
		//checks that escape key was not pressed
		if (input == 27)
		{
			break;
		}

		//switch statement to check what user input
		switch (_getch()) {

			//user pressed down arrow key
		case 80:

			//makes sure the cursor doesnt go out of bounds in the array
			if (index < scrBottom && index > 0)
			{
				//move on the array of linked lists
				index++;

				//moves stored position of cursor downward 1 unit
				posy = wherey() + 1;


				if (index < scrBottom && index > 0)
				{
					gotoxy(posx, posy);
				}
				else {
					index--;

					//moves stored position of cursor downward 1 unit. This fixes the previous move if the paddle was moved out of bounds
					posy = wherey() - 1;
				}
			}
			break;

			//user pressed up arrow key
		case 72:
			//makes sure the cursor doesnt go out of bounds in the array
			if (index < scrBottom && index > 0)
			{
				//move on the array of linked lists
				index--;

				//moves stored position of cursor upward 1 unit
				posy = wherey() - 1;

				if (index < scrBottom && index > 0)
				{
					gotoxy(posx, posy);
				}
				else {
					index++;

					//moves stored position of cursor downward 1 unit. This fixes the previous move if the paddle was moved out of bounds
					posy = wherey() + 1;
				}
			}
			break;

		default:
			break;
		}
	}
}

//function to load the leaderboard, call this function at the beginning of every game to load the leaderboard list primarily and to show user potential goal to achieve
void GameControl::loadLeaderB()
{
	string fileName = "leaderboard.txt";
	string line;
	int score = 0;
	int i = 0;

	ifstream myFile(fileName);

	while (std::getline(myFile, line) && i < 13)
	{
		std::istringstream iss(line);

		cout << line << endl;		

		if (i > 3)
		{
			iss >> score;

			leaderboard[i] = score;
			
		}
		i++;
	}
	myFile.close();
}

void GameControl::options()
{
	int inp;
	cout << "1. Change Difficulty" << endl;
	cout << "2. Amount of Points for Victory" << endl;
	cout << "Press 9 to return to previous screen." << endl;
	cin >> inp;

	
		if (inp == 1)
		{
			cout << "Choose difficulty 1 through 4" << endl;
			cout << "Press 9 to return to previous screen." << endl;
			cin >> inp;

			cout << inp << " is the new difficulty for the game." <<endl;
			Sleep(2500);

			bender.difficulty(inp);
		}
		else if (inp == 2)
		{
			cout << "Choose amount of Points to win." << endl;
			cout << "Press 9 to return to previous screen." << endl;

			cin >> vict; 
			
			cout << endl << vict << " points required for victory." << endl;
			Sleep(2500);

		}		
		if(inp == 9)
		{
			cout << "Returning to previous menu..." << endl;
		}
}

void GameControl::saveLeaderB()
{
	string fileName = "leaderboard.txt";

	ofstream myFile(fileName);

	myFile << "PONG MASTER DELUXE SUPER TRIPLE DELUXE MASTER EDITION VOLUME 17 Leaderboard!:" << endl << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		myFile << leaderboard[i];
	}

}


//call this function when game ends to input the new score
void GameControl::sortLB()
{
	leaderboard[10] = score;

	//insertion sort algorithm to sort leaderboard and input the new score
	int i, key, j;


	//size of the array being sorted
	int n = 11;

	for (i = 1; i < n; i++)
	{
		key = leaderboard[i];
		j = i - 1;

		/* Move elements of leaderboard[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && leaderboard[j] > key)
		{
			leaderboard[j + 1] = leaderboard[j];
			j = j - 1;
		}
		leaderboard[j + 1] = key;
	}
}

void GameControl::gotoxy(int x, int y) {

	COORD pos = { x, y };

	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(output, pos);

}

int GameControl::wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}
int GameControl::wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}