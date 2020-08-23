#pragma once
#include<iostream>

using namespace std;
class Board
{
public:
	void print();
	Board();
	void SetChar(char symbol, char  c);
	bool HasWon(char symbol);
	bool IsFilled(int iIndex, int jIndex, char  c);
	char GetVal(int i, int j);
private:
	char** grid;	
};

