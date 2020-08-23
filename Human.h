#pragma once
#include "Player.h"

#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <conio.h>

using namespace std;
class Human : public Player
{
public:
	Human();
	void Init();
	char GetMove(Board* board);
private:
	char c;
	condition_variable cv;
	void ReadValue();
};

