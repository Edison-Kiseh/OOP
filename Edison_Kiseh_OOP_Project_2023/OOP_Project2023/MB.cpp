#include "MB.h"
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
MB::MB() {
	socket = "N/A";
	memorySlots = NULL;
	size = "N/A";
}


MB::MB(const string& manufact, const string& userName, int cost, int quantity, int genre, bool lapt, int memSlots, const std::string& sizee, const std::string& sockett) : Components(manufact, userName, cost, quantity, genre, lapt) {
	memorySlots = memSlots;
	size = sizee;
	socket = sockett;
}

void MB::setMemorySlots(int memSlots) {
	memorySlots = memSlots;
}

int MB::getMemorySlots() const { return memorySlots; }


void MB::setSize(const string& sizee) {
	size = sizee;
}

string MB::getSize() const { return size; }


void MB::setSocket(const string& sockett) {
	socket = sockett;
}

string MB::getSocket() const { return socket; }

string MB::toString() const {
	ostringstream output;

	Components::toString();
	cout << "Memory slots: " << memorySlots << endl;
	cout << "Size: " << size << endl;
	cout << "Socket: " << socket << endl;

	return output.str();
}