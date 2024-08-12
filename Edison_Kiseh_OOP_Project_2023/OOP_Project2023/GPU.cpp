#include "GPU.h"
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
GPU::GPU() {
	power = NULL;
	busSpeed = NULL;
}


GPU::GPU(const string& manufact, const string& userName, int cost, int quantity, int genre, bool lapt, int pow, int speed) : Components(manufact, userName, cost, quantity, genre, lapt) {
	power = pow;
	busSpeed = speed;

}

void GPU::setPower(int pow) {
	power = pow;
}

int GPU::getPower() const { return power; }


void GPU::setBusSpeed(int speed) {
	busSpeed = speed;
}

int GPU::getBusSpeed() const { return busSpeed; }

string GPU::toString() const {
	ostringstream output;

	Components::toString();
	cout << "Power: " << power << endl;
	cout << "Bus speed: " << busSpeed << endl;

	return output.str();
}