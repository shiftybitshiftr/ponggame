#pragma once
#include "Bot.h"
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

	void gotoxy(int x, int y);
	int wherex();
	int wherey();

private:
	Bot bender;
	int vict;
	int score;
	int leaderboard[11];
};

