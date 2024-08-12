#include "PS.h"
#include <iostream>
#include <sstream>

using namespace std;

//default constructor
PS::PS() {
	power = NULL;
	certification = "N/A";
}


PS::PS(const string& manufact, const string& userName, int cost, int quantity, int genre, bool lapt, int pow, const string& certif) : Components(manufact, userName, cost, quantity, genre, lapt) {
	power = pow;
	certification = certif;
}

void PS::setPower(int pow) {
	power = pow;
}

int PS::getPower() const { return power; }


void PS::setCertification(const string& certif) {
	certification = certif;
}

string PS::getCertification() const { return certification; }

string PS::toString() const {
	ostringstream output;

	Components::toString();
	cout << "Power: " << power << endl;
	cout << "Certification: " << certification << endl;

	return output.str();
}

