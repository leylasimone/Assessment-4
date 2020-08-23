#include "Human.h"

Human::Human()
{
	c = 'a';
}

void Human::ReadValue() {
	c = _getch();
	cv.notify_one();
}
void Human::Init() {
	cout << "Please Enter your name: ";
	cin >> name;
}

char Human::GetMove(Board* board)
{
	
	cout << GetName() << ", Please Enter your Move in 20 seconds: ";
	thread th(&Human::ReadValue, this);
	mutex mtx;
	unique_lock<mutex> lck(mtx);
	bool lost = false;
	while (cv.wait_for(lck, chrono::seconds(20)) == cv_status::timeout) {
		cout << "\nYou Lost... Your 20 seconds are over. Press any key to continue\n";
		c= 'L';
		lost = true;
	}
	th.join();
	
	if (lost)
		return 'L';
	if (c >= 90)
		c = c - 32;
	if (c == 'R' || c == 'Q')
		return c;
	if (IsValid(c, board)) {
		return c;
	}
	else {
		return GetMove(board);
	}
}
