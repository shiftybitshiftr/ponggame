#include "GameControl.h"
#include "Ball.h"
#include "Bot.h"
#include "Player.h"

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

void gameTitle();
void pongArt();
void gameMenu(GameControl x);

extern void SetColor(int);
extern void PlaceCursor(const int x, const int y);
extern void printArt(string fileName);

//extern void gotoxy(int x, int y);
//extern int wherex();
//extern int wherey();

int main()
{
	GameControl GC;
	gameTitle();
	pongArt();
	gameMenu(GC);

	//system("Pause");
	return 0;
}

void gameMenu(GameControl x)
{
	bool gameOn = true;
	int choice;

	while (gameOn != false)
	{
		SetColor(10);
		system("CLS");
		system("mode 130");

		PlaceCursor(30, 4);
		cout << "PONG MASTER DELUXE SUPER TRIPLE DELUXE MASTER EDITION VOLUME 17" << endl;
		PlaceCursor(33, 5);
		cout << "OF THE PONG BIBLICAL TRILOGY NUMBER 2: ELECTRIC BOOGALOO" << endl;

		PlaceCursor(22, 7);
		cout << "******************************************************************************" << endl;

		PlaceCursor(50, 10);
		cout << " 1 - START\n";

		PlaceCursor(50, 11);
		cout << " 2 - SETTINGS\n";

		PlaceCursor(50, 12);
		cout << " 3 - HIGHSCORES\n";

		PlaceCursor(50, 13);
		cout << " 4 - EXIT\n";

		cout << " \n\nType your choice and press enter: ";
		cin >> choice;

		if (choice == 2)
		{
			x.options();
		}
		else if (choice == 3)
		{			
			x.loadLeaderB();
			Sleep(3500);
		}
		else if (choice == 1)
		{
			x.start();
			system("Pause");
		}

		
		if (choice == 4)
		{
			gameOn = false;
		}
	}

}

extern void PlaceCursor(const int x, const int y)
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD PlaceCursorHere;
	PlaceCursorHere.X = x;
	PlaceCursorHere.Y = y;

	SetConsoleCursorPosition(hConsole, PlaceCursorHere);
	return;
}

void pongArt()
{
	SetColor(10);
	system("CLS");
	PlaceCursor(0, 5);
	printArt("pongArt.txt");
	Sleep(1500);
}

void gameTitle()
{
	int k;
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (k = 1; k < 500; k++)
	{
		//int n;
		//for (n = 1; n < 10; n++)
		//{
		// move our text around
		PlaceCursor(k, k);
		// pick the colorattribute k you want
		SetColor(k);
		cout << "PONG MASTER DELUXE SUPER TRIPLE DELUXE MASTER EDITION VOLUME 17" << endl;
		//}
	}
	for (k = 1; k < 100; k++)
	{
		// move our text around
		PlaceCursor(k, k);
		// pick the colorattribute k you want
		SetColor(k);
		cout << "PONG MASTER DELUXE SUPER TRIPLE DELUXE MASTER EDITION VOLUME 17" << endl;
	}
}

void SetColor(int value) // Wrapper function for windows set console color
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

// Reads ASCII art from file and print
void printArt(string fileName)
{
	std::ifstream f(fileName);

	if (f.is_open())
		cout << f.rdbuf();
	cout << "\n";
}