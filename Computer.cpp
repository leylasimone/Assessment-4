#include "Computer.h"

int Computer::num = 1;
Computer::Computer() {
}

void Computer::Init() {
	ostringstream oss;
	oss << num;
	name = "Computer " + oss.str();
	num++;
}


char Computer::MakeSymbol(int i, int j) {
	char s = 'A';
	for (int ii = 0;ii < i;ii++) {
		s++;
		s++;
		s++;
	}
	for (int jj = 0;jj < j;jj++) {
		s++;
	}
	return s;
}
char Computer::GetMove(Board* board)
{
	char sym = symbol == 'X' ? 'O' : 'X';
	char symb = symbol;
	char winning = IntelligentChar(board, sym, symb);
	if (winning != '~')
		return winning;

	symb = symbol == 'X' ? 'O' : 'X';
	sym = symbol;


	winning = IntelligentChar(board, sym, symb);
	if (winning != '~')
		return winning;
	sym = 'A';
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {

			if (board->GetVal(i, j) == sym)
				return MakeSymbol(i, j);
			sym++;
		}
	}
	return 'Q';
}

char Computer::IntelligentChar(Board* board, char sym, char symb) {
	for (int i = 0;i < 3;i++) {
		int val = 0;
		int empty = -1;
		for (int j = 0;j < 3;j++) {
			if (board->GetVal(i, j) == sym)
				val++;
			else if (board->GetVal(i, j) != symb)
				empty = j;
		}

		if (val == 2 && empty != -1) {
			return MakeSymbol(i, empty);
		}

		empty = -1;
		val = 0;
		for (int j = 0;j < 3;j++) {
			if (board->GetVal(j, i) == sym)
				val++;
			else if (board->GetVal(j, i) != symb)
				empty = j;
		}
		if (val == 2 && empty != -1) {
			return MakeSymbol(empty, i);
		}

	}

	int empty = -1;
	int val = 0;
	for (int i = 0;i < 3;i++) {
		if (board->GetVal(i, i) == sym)
			val++;
		else if (board->GetVal(i, i) != symb)
			empty = i;
	}

	if (val == 2 && empty != -1) {
		return MakeSymbol(empty, empty);
	}

	empty = -1;
	val = 0;

	for (int i = 0;i < 3;i++) {
		if (board->GetVal(2 - i, i) == sym)
			val++;
		else if (board->GetVal(2 - i, i) != symb)
			empty = i;
	}

	if (val == 2 && empty != -1) {
		return MakeSymbol(2 - empty, empty);
	}
	return '~';
}
