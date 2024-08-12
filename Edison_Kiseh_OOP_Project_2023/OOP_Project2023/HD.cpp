#include "HD.h"
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
HD::HD() {
	size = NULL;
	speed = NULL;
	slot = "N/A";
}


HD::HD(const string& manufact, const string& userName, int cost, int quantity, int genre, bool lapt, int speedd, int sizee, const string& slott) : Components(manufact, userName, cost, quantity, genre, lapt) {
	speed = speedd;
	size = sizee;
	slot = slott;
}

void HD::setSpeed(int speedd) {
	speed = speedd;
}

int HD::getSpeed() const { return speed; }


void HD::setSize(int sizee) {
	size = sizee;
}

int HD::getSize() const { return size; }


void HD::setSlot(const string& slott) {
	slot = slott;
}

string HD::getSlot() const { return slot; }

string HD::toString() const {
	ostringstream output;

	Components::toString();
	cout << "Speed: " << speed << endl;
	cout << "Size: " << size << endl;
	cout << "Slot: " << slot << endl;

	return output.str();
}