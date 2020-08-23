
#pragma once

#include<iostream>
#include <string>
#include "Board.h"

using namespace std;
class Player
{
public:
	char GetSymbol();
	void SetSymbol(char symbol);
	Player();
	virtual void Init();
	virtual char GetMove(Board* board);
	string GetName();
	void WonGame();
	bool IsValid(char c, Board* board);
	int GetTotalGames();
	int GetWonGames();
	void NewGame();


protected:
	string name;
	char symbol;
private:
	int games;
	int won;
};
