#pragma once
#include "Bot.h"
#include "Player.h"
#include <vector>

class GameControl
{
public:
	GameControl();
	~GameControl();

	void saveLeaderB();

	void loadLeaderB();
	
	void options();

	void start();

	void sortLB();

	void DisplayGame(Ball myBall, Player myPlayer, Bot myBot, int x, int y);

	int checkWinCondition(Ball myBall);

	void gotoxy(int x, int y);
	int wherex();
	int wherey();

private:
	char board[30][120];
	Bot bender;
	int vict;
	int playerScore;
	int botScore;
	int leaderboard[11];
};

