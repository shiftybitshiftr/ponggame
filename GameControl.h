#pragma once
#include "Bot.h"
#include <vector>;
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

private:
	Bot bender;
	int vict;
	int score;
	int leaderboard[11];
};

