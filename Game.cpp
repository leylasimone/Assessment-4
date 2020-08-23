#include "Game.h"



Game::Game() {
	srand((unsigned int)time(0));
	SetBoard();
}

void Game::SetBoard() {
	this->board = new Board();
}



void Game::Play() {
	int gameType = SelectGameType();
	InitPlayers(gameType);
	cout << "\nPlayer 1: " << player1->GetName() << endl;
	cout << "Player 2: " << player2->GetName() << endl;
	bool newGame;
	char c;
	c = 'a';
	newGame = true;
	do {
		cout << "Starting a new game:\n\n";
		board->print();
		
		Player* current = (rand() % 2 == 1) ? player1 : player2;
		if (c != 'R') {
			player1->NewGame();
			player2->NewGame();
		}
		do {
			current = current == player2 ? player1 : player2;
			c = current->GetMove(board);
			if (c == 'Q') {
				cout << "You decided to quit the game.\n\n";
				break;
			}
			else if (c == 'R') {
				cout << "Restarting the game...\n\n";
				break;
			}
			else if (c == 'L') {
				Player* p = player1 == current ? player2 : player1;
				p->WonGame();
				break;
			}
			cout << current->GetName() << "'s Move: " << c << endl;
			board->SetChar(current->GetSymbol(), c);
			board->print();
		} while (!IsGameFinished(current));
		if (c == 'Q')
			break;
		board = new Board();
		if (c == 'R') {
			continue;
			newGame = true;
		}
		else {
			newGame = NewGame();
		}
		

	} while (newGame);
	
	cout << "\nGame Summary:\n";
	cout << "Total Games: " << player1->GetTotalGames() << "\n";
	cout << " Games won by " << player1->GetName() << ":" << player1->GetWonGames() << "\n";
	cout << " Games won by " << player2->GetName() << ":" << player2->GetWonGames() << "\n";
}

bool Game::IsGameFinished(Player* player) {
	char symbol = player->GetSymbol();
	if (board->HasWon(player->GetSymbol()))
	{
		cout << "\n" << player->GetName() << " has won the game.\n";
		player->WonGame();
		return true;
	}

	char sym = 'A';
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {

			if (board->GetVal(i, j) == sym++)
				return false;
		}
	}
	cout << "The whole grid is filled. \n\n";
	return true;
}

bool Game::NewGame() {
	cout << "\nDo you want to play a new game:\n";
	cout << "  1. Yes\n";
	cout << "  2. No\n";
	return ReadInt("Select your choice: ", 1, 2) == 1;

}
void Game::InitPlayers(int gameType) {
	if (gameType == 1) {
		player1 = new Human();
		player2 = new Human();
	}
	else if (gameType == 2) {
		player1 = new Computer();
		player2 = new Human();
	}
	else if (gameType == 3) {
		player1 = new Computer();
		player2 = new Computer();
	}
	player1->SetSymbol('O');
	player2->SetSymbol('X');
	player1->Init();
	player2->Init();
}


void Game::Start() {

}
int Game::SelectGameType() {
	cout << "Please Select a Game Type" << endl;
	cout << "   1. Human vs Human"<<endl;
	cout << "   2. Computer vs Human"<<endl;
	cout << "   3. Computer vs Computer"<<endl;
	return ReadInt("Please select a choice: ", 1, 3);
}

int Game::ReadInt(string prompt, int min, int max) {
	cout << prompt;
	int val;
	cin >> val;
	if (val >= min && val <= max)
		return val;
	cout << "Please enter a valid value between " << min << " and " << max << "." << endl << endl;
	return ReadInt(prompt, min, max);
}
