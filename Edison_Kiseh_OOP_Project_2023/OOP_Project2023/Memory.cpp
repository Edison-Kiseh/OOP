#include "Memory.h"
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
Memory::Memory() {
	size = NULL;
	speed = NULL;
}


Memory::Memory(const string& manufact, const string& userName, int cost, int quantity, int genre, bool lapt, int sizee, int speedd) : Components(manufact, userName, cost, quantity, genre, lapt) {
	size = sizee;
	speed = speedd;
}

void Memory::setSize(int sizee) {
	size = sizee;
}

int Memory::getSize() const { return size; }


void Memory::setSpeed(int speedd) {
	speed = speedd;
}

int Memory::getSpeed() const { return speed; }

string Memory::toString() const {
	ostringstream output;

	Components::toString();
	cout << "Size: " << size << endl;
	cout << "Speed: " << speed << endl;

	return output.str();
}