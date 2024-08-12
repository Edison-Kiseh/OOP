#include "CPU.h"
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
CPU::CPU() {
	speed = NULL;
	cores = NULL;
	socket = "N/A";
}


CPU::CPU(const string& manufact, const string& userName, int cost, int quantity, int genre, bool lapt, int speedd, int coress, const string& sockett) : Components(manufact, userName, cost, quantity, genre, lapt) {
	speed = speedd;
	cores = coress;
	socket = sockett;
}

void CPU::setSpeed(int speedd) {
	speed = speedd;
}

int CPU::getSpeed() const { return speed; }


void CPU::setCores(int coress) {
	cores = coress;
}

int CPU::getCores() const { return cores; }


void CPU::setSocket(const string& sockett) {
	socket = sockett;
}

string CPU::getSocket() const { return socket; }

string CPU::toString() const {
	ostringstream output;

	Components::toString();
	cout << "Speed: " << speed << endl;
	cout << "Cores: " << cores << endl;
	cout << "Socket: " << socket << endl;

	return output.str();
}