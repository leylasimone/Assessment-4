#pragma once
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Board.h"
#include <random>
#include <ctime>
using namespace std;
class Game
{
public:
	void Play();
	Game();
private:	
	Player* player1;
	Player* player2;
	Board* board;
	void SetBoard();
	void Start();
	int SelectGameType();
	int ReadInt(string prompt, int min, int max);
	void InitPlayers(int gameType);
	bool IsGameFinished(Player* player);
	bool NewGame();
};

