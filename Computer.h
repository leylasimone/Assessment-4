#pragma once
#include "Player.h"
#include<sstream>
class Computer : public Player
{
public:
	Computer();
	void Init();
	char GetMove(Board* board);
private:
	static int num;
	char MakeSymbol(int i, int j);
	char IntelligentChar(Board* board, char sym, char symb);
};

