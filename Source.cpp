#include "GameControl.h"
#include "Ball.h"
#include "Bot.h"
#include "Player.h"

#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

void gameTitle();
void pongArt();
void gameMenu(GameControl x);

extern void PlaceCursor(const int x, const int y);

extern void gotoxy(int x, int y);

extern int wherex();

extern int wherey();

int main()
{
	//system("Pause");
	GameControl GC;
	gameTitle();
	//pongArt();
	gameMenu(GC);

	system("Pause");
	return 0;
}

void gameMenu(GameControl x)
{
	bool gameOn = true;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice;

	while (gameOn != false)
	{
		SetConsoleTextAttribute(hConsole, 10);
		system("CLS");

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

/*void pongArt()
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	system("CLS");

	cout << "       PPPPPPPPPPPPPPPPP        OOOOOOOOO     NNNNNNNN        NNNNNNNN        GGGGGGGGGGGGG" << endl;
	cout << "       P::::::::::::::::P     OO:::::::::OO   N:::::::N       N::::::N     GGG::::::::::::G" << endl;
	cout << "       P::::::PPPPPP:::::P  OO:::::::::::: : OO N::::::::N      N::::::N   GGG::::::::::::G" << endl;
	cout << "       PP:::::P     P:::::PO:::::::OOO:::::::ON:::::::::N     N::::::N  G:::::GGGGGGGG::::G" << endl;
	cout << "         P::::P     P:::::PO::::::O   O::::::ON::::::::::N    N::::::N G:::::G       GGGGGG" << endl;
	cout << "         P::::P     P:::::PO:::::O     O:::::ON:::::::::::N   N::::::NG:::::G              " << endl;
	cout << "         P::::PPPPPP:::::P O:::::O     O:::::ON:::::::N::::N  N::::::NG:::::G              " << endl;
	cout << "         P:::::::::::::PP  O:::::O     O:::::ON::::::N N::::N N::::::NG:::::G    GGGGGGGGGG" << endl;
	cout << "         P::::PPPPPPPPP    O:::::O     O:::::ON::::::N  N::::N:::::::NG:::::G    G::::::::G" << endl;
	cout << "         P::::P            O:::::O     O:::::ON::::::N   N:::::::::::NG:::::G    GGGGG::::G" << endl;
	cout << "         P::::P            O:::::O     O:::::ON::::::N    N::::::::::NG:::::G        G::::G" << endl;
	cout << "         P::::P            O::::::O   O::::::ON::::::N     N:::::::::N G:::::G       G::::G" << endl;
	cout << "       PP::::::PP          O:::::::OOO:::::::ON::::::N      N::::::::N  G:::::GGGGGGGG::::G" << endl;
	cout << "       P::::::::P           OO:::::::::::::OO N::::::N       N:::::::N   GG:::::::::::::::G" << endl;
	cout << "       P::::::::P             OO:::::::::OO   N::::::N        N::::::N     GGG::::::GGG:::G" << endl;
	cout << "       PPPPPPPPPP               OOOOOOOOO     NNNNNNNN         NNNNNNN        GGGGGG   GGGG" << endl;

	Sleep(1500);
}*/

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
		SetConsoleTextAttribute(hConsole, k);
		cout << "PONG MASTER DELUXE SUPER TRIPLE DELUXE MASTER EDITION VOLUME 17" << endl;
		//}
	}
	for (k = 1; k < 100; k++)
	{
		// move our text around
		PlaceCursor(k, k);
		// pick the colorattribute k you want
		SetConsoleTextAttribute(hConsole, k);
		cout << "PONG MASTER DELUXE SUPER TRIPLE DELUXE MASTER EDITION VOLUME 17" << endl;
	}
}