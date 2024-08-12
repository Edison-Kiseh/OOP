#include "Monitor.h"
#include <iostream>
#include <sstream>

using namespace std;

Monitor::Monitor() {
	size = NULL;
	resolution = "N/A";
	brand = "N/A";
}

Monitor::Monitor(const string& manufact, const string& userName, int cost, int quantity, int genre, bool lapt, float sizee, const string& res, const string& mark) : Components(manufact, userName, cost, quantity, genre, lapt) {
	size = sizee;
	resolution = res;
	brand = mark;
}

void Monitor::setSize(float sizee) {
	size = sizee;
}

float Monitor::getSize() const { return size; }


void Monitor::setResolution(const string& res) {
	resolution = res;
}

string Monitor::getResolution() const { return resolution; }

void Monitor::setBrand(const string& mark) {
	brand = mark;
}

string Monitor::getBrand() const { return brand; }


string Monitor::toString() const {
	ostringstream output;

	Components::toString();
	cout << "Size: " << size << endl;
	cout << "Resolution: " << resolution << endl;
	cout << "Brand: " << brand << endl;

	return output.str();
}