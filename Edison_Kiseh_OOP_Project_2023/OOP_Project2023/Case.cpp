#include "Case.h"
#include <iostream>
#include <sstream>

using namespace std;

Case::Case() {
	material = "N/A";
	color = "N/A";
	MBSize = "N/A";
}

Case::Case(const string& manufact, const string& userName, int cost, int quantity, int genre, bool lapt, const string& materiall, const string& MBSizee, const string& colorr) : Components(manufact, userName, cost, quantity, genre, lapt) {
	material = materiall;
	color = colorr;
	MBSize = MBSizee;
}

void Case::setColor(const string& colorr) {
	color = colorr;
}

string Case::getColor() const { return color; }


void Case::setMBSize(const string& MBSizee) {
	MBSize = MBSizee;
}

string Case::getMBSize() const { return MBSize; }


void Case::setMaterial(const string& materiall) {
	material = materiall;
}

string Case::getMaterial() const { return material; }

string Case::toString() const {
	ostringstream output;

	Components::toString();
	cout << "Color: " << color << endl;
	cout << "Material: " << material << endl;
	cout << "MBSize: " << MBSize << endl;

	return output.str();
}
