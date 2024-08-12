#include "Battery.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Battery::Battery() {
	capacity = NULL;
	voltage = NULL;
	serialNumber = "N/A";
}

Battery::Battery(const string& manufact, const string& userName, int cost, int quantity, int genre, bool lapt, float cap, float volt, const string& serialNum) : Components(manufact, userName, cost, quantity, genre, lapt) {
	capacity = cap;
	voltage = volt;
	serialNumber = serialNum;
}

void Battery::setCapacity(float cap) {
	capacity = cap;
}

float Battery::getCapacity() const { return capacity; }


void Battery::setVoltage(float volt) {
	voltage = volt;
}

float Battery::getVoltage() const { return voltage; }


void Battery::setSerialNumber(const string& sn) {
	serialNumber = sn;
}

string Battery::getSerialNumber() const { return serialNumber; }

string Battery::toString() const {
	ostringstream output;

	Components::toString();
	cout << "Capacity: " << capacity << endl;
	cout << "Voltage: " << voltage << endl;
	cout << "Serial number: " << serialNumber << endl;

	return output.str();
}


