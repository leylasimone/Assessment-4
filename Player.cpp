
#include "Player.h"

Player::Player() {
	games = 0;
	won = 0;
	this->symbol = '*';
}

bool Player::IsValid(char c, Board* board) {
	if (c < 'A' || c > 'I') {
		cout << "Input must be between A - I ";
		return false;
	}

	int index = c - 65;
	int iIndex = index / 3;
	int jIndex = index % 3;

	bool val = board->IsFilled(iIndex, jIndex, c);
	if (val) {
		cout << c << " is already filled. Please try again" << endl;
	}
	return !val;
}

string Player::GetName() {
	return this->name;
}

void Player::Init() {

}

void Player::NewGame() {
	games++;
}

char Player::GetMove(Board* board)
{
	return 'A';
}

char Player::GetSymbol() {
	return this->symbol;
}

void Player::SetSymbol(char symbol) {
	this->symbol = symbol;
}
void Player::WonGame() {
	won++;
}

int Player::GetTotalGames() {
	return games;
}
int Player::GetWonGames() {
	return won;
}
