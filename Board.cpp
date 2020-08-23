#include "Board.h"

Board::Board() {
	grid = new char*[3];
	char c = 'A';
	for (int i = 0;i < 3;i++) {
		grid[i] = new char[3];

	}

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			grid[i][j] = c++;
		}
	}
}

char Board::GetVal(int i, int j) {
	return this->grid[i][j];
}

bool Board::IsFilled(int iIndex, int jIndex, char  c) {
	return this->grid[iIndex][jIndex] != c;
}

void Board::SetChar(char symbol, char  c) {

	int index = c - 65;
	int iIndex = index / 3;
	int jIndex = index % 3;

	this->grid[iIndex][jIndex] = symbol;
}
void Board::print() {

	cout << endl<<"Current Board Status :"<<endl;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cout << grid[i][j];
			if (j < 2)
				cout << "|";
		}
		cout << endl;
		cout << "- - - "<<endl;		
	}
}

bool Board::HasWon(char symbol) {
	for (int i = 0;i < 3;i++) {
		char won = true;
		for (int j = 0;j < 3;j++) {
			if (grid[i][j] != symbol)
				won = false;
		}

		if (won)
			return true;
		won = true;
		for (int j = 0;j < 3;j++) {
			if (grid[j][i] != symbol)
				won = false;
		}

		if (won)
			return true;
	}

	if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
		return true;

	return grid[2][0] == symbol && grid[1][1] == symbol && grid[0][2] == symbol;
}