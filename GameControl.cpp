#include "GameControl.h"
#include "Player.h"
#include "Ball.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <sstream>
#include <fstream>
#include <iostream>
//#include "Source.cpp"

using namespace std;

extern void SetColor(int);
extern void PlaceCursor(const int x, const int y);
extern void printArt(string fileName);


GameControl::GameControl()
{
	vict = 3;
	playerScore = 0;
	botScore = 0;

	for (int i = 0; i < 11;i++)
	{
		leaderboard[i] = 0;
	}
}

GameControl::~GameControl()
{
}

//move player with switch statement then move bot then move ball and display function at the end then check for win
//function called when user chooses to start playing the actual game

void GameControl::start()
{
	//system("CLS");

	//myBall.setXandY(60,15);
		//22 by 80 is the shape of the box on Win7
		//30 by 120 is shape of box on Win8-10

	//values to ensure the paddle does not move offscreen
	//int index=0;
	//const int scrBottom = 45;

	//values to catch position of cursor
	//int posx = 0;
	//int posy = 0;
	//value to hold user input
	//int input;
	//boolean value to check whether end program button was pressed and exit program
	//bool check = true;

	//check user input
	//input = _getch();
	//one loop which calls the player move function and computer move function and display function
	//while loop to continue running unless escape is pressed
	//while (check == true)
	//{
	//	//checks that escape key was not pressed
	//	if (input == 27)
	//	{
	//		break;
	//	}

	//	//switch statement to check what user input
	//	switch (_getch()) {

	//		//user pressed down arrow key
	//	case 80:

	//		//makes sure the cursor doesnt go out of bounds in the array
	//		if (index < scrBottom && index > 0)
	//		{
	//			//move on the array of linked lists
	//			index++;

	//			//moves stored position of cursor downward 1 unit
	//			posy = wherey() + 1;


	//			if (index < scrBottom && index > 0)
	//			{
	//				gotoxy(posx, posy);
	//			}
	//			else {
	//				index--;

	//				//moves stored position of cursor downward 1 unit. This fixes the previous move if the paddle was moved out of bounds
	//				posy = wherey() - 1;
	//			}
	//		}
	//		break;

	//		//user pressed up arrow key
	//	case 72:
	//		//makes sure the cursor doesnt go out of bounds in the array
	//		if (index < scrBottom && index > 0)
	//		{
	//			//move on the array of linked lists
	//			index--;

	//			//moves stored position of cursor upward 1 unit
	//			posy = wherey() - 1;

	//			if (index < scrBottom && index > 0)
	//			{
	//				gotoxy(posx, posy);
	//			}
	//			else {
	//				index++;

	//				//moves stored position of cursor downward 1 unit. This fixes the previous move if the paddle was moved out of bounds
	//				posy = wherey() + 1;
	//			}
	//		}
	//		break;

	//		

	//	default:
	//		break;
	//	}

	//	myPlayer.setY(posy);

	//	DisplayGame(posx, posy);

	//	myBall.WinCondition(myPlayer, myBot);
	//}

	const char paddle = 219;
	const char ball = 254;
	Ball *myBall = new Ball();
	Player *myPlayer = new Player();
	Bot *myBot = new Bot();

	//boolean value to check whether end program button was pressed and exit program
	bool check = true;
	char checkKey = 0;

	int winner = 0, ballDir, ballX, ballY;

	system("mode 80"); // ensure console width is large enough
	system("CLS");

	// print how many points required to win
	PlaceCursor(30, 11);
	cout << "First to ";
	SetColor(0x0D);
	cout << vict;
	SetColor(10);
	cout << " wins!\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	Sleep(1500);
	//system("pause");

	while (check == true)
	{
		//checkKey = _getch();
		////checks if escape key was pressed
		//if (checkKey == 27)
		//{
		//	break;
		//}

		srand(time(NULL)); 
		ballDir = (rand() % 4) + 1; // seed for random ball starting direction

		srand(time(NULL));
		ballY = (rand() % 10) + 6; // seed for random ball starting posY

		srand(time(NULL));
		ballX = (rand() % 20) + 31; // seed for random ball starting posX

		myBall->setXandYandDir(ballX, ballY, ballDir);
		DisplayGame(*myBall, *myPlayer, *myBot, ballX, ballY); // print game board
		myPlayer->setInput(_getch()); // accept user input

		while (1)
		{
			// probably use these variables instead of directly calling inside each move function. it's hard to understand whats going on in there.
			//int ballX = myBall.getX();
			//int ballY = myBall.getY();
			//int ballDir = myBall.getDir();
			//int playerY = myPlayer.getY();
			//int botY = myBot.getY();

			// move player, ball, and bot
			myPlayer->movePlayer();
			myBot->move(myBall->getX(), myBall->getY(), myBall->getDir()); // passing position and direction of ball
			myBall->moveBall(myPlayer->getY(), myBot->getY());             // passing position of player and bot

			// print updated positions
			DisplayGame(*myBall, *myPlayer, *myBot, ballX, ballY);

			// check if someone has scored, 0 = nobody, 1 = player, 2 = bot
			winner = checkWinCondition(myBall->getX());

			//consider flushing user input stream here

			if (winner != 0) // triggered if some scored a point
			{
				//and here

				if (winner == 1)
				{
					// add 1 to player score
					playerScore++;

					// print "PLAYER SCORED !" 
					system("CLS");
					SetColor(0x0B);
					PlaceCursor(0, 7);
					printArt("pScore.txt");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
					SetColor(10);
					Sleep(1500);
					//system("pause");
				}
				else if (winner == 2)
				{
					// add 1 to bot score
					botScore++;

					// print "BOT SCORED !" 
					system("CLS");
					SetColor(0x0C);
					PlaceCursor(0, 7);
					printArt("bScore.txt");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
					SetColor(10);
					Sleep(1500);
					//system("pause");
				}
				goto checkForVictory; // theres a better way to do this than using goto
			}

		}

		checkForVictory:

			// checking if victory condition has been met
			if (playerScore == vict || botScore == vict)
			{
				system("CLS");
				if (playerScore == vict)
				{
					SetColor(0xB0);
					PlaceCursor(0, 11);
					printArt("pWin.txt");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
					SetColor(10);
					sortLB();
					//system("pause")
					Sleep(3000);
				}
				else
				{
					SetColor(0xC0);
					PlaceCursor(0, 3);
					printArt("bWin.txt");
					cout << "\n\n\n\n";
					SetColor(10);
					sortLB();
					//system("pause");
					Sleep(3000);
				}
				break;
			}
	}
}

int GameControl::checkWinCondition(int xCord)
{
	if (xCord == 79) // computer scored
	{
		return 2;
	}
	if (xCord == 0) // player scored
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// calls player, bot, and ball draw functions, prints game border and updates the scoreboard
void GameControl::DisplayGame(Ball myBall, Player myPlayer, Bot myBot, int posx, int posy)
{
	system("CLS");

	//board size is 22 by 80 or 30 by 130
	int x;
	char ch = 176;

	//start drawing player + bot which just moved
	myPlayer.draw(79, myPlayer.getY());
	myBot.draw(0, myBot.getY());

	//start drawing ball which just moved
	myBall.draw(posx, posy);

	//top and bottom border
	for (x = 0; x < 80; x++)
	{
		PlaceCursor(x, 22);
		cout << ch;
		PlaceCursor(x, 0);
		cout << ch;
	}

	PlaceCursor(5, 0);
	cout << " BOT SCORE: " << botScore << " " << endl;
	PlaceCursor(58, 0);
	cout << " PLAYER SCORE: " << playerScore << " " << endl;

}


//function to load the leaderboard, call this function at the beginning of every game to load the leaderboard list primarily and to show user potential goal to achieve
void GameControl::loadLeaderB()
{
	string fileName = "leaderboard.txt";
	string line;
	int score = 0;
	int i = 0;

	ifstream myFile(fileName);

	cout << "\nPONG MASTER DELUXE SUPER TRIPLE DELUXE MASTER EDITION VOLUME 17 Leaderboard!:" << endl << endl << endl;

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

	//system("pause");
}

void GameControl::options()
{
	int inp;
	cout << "\n1. Change Difficulty" << endl;
	cout << "2. Amount of Points for Victory" << endl;
	cout << "Press 9 to return to previous screen.\n" << endl;
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
			cout << "Press 9 to return to previous screen.\n" << endl;

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
	leaderboard[10] = playerScore;

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
