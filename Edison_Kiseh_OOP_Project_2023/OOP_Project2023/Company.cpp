#include "Company.h"
#include <iostream>
#include <sstream>

using namespace std;

Company::Company() {
	vat = NULL;
	reduction = 10;
	yearlyBuy = NULL;
}

Company::Company(const string& name, const string& address, bool company, int vatt, int reduct, int annualBuy) 
	: Customer(name, address, company) {

	vat = vatt;
	reduction = reduct;
	yearlyBuy = annualBuy;
}

void Company::setVat(int vatt) {
	vat = vatt;
}

int Company::getVat() const { return vat; }


void Company::setReduction(int reduct) {
	reduction = reduct;
}

int Company::getReduction() const { return reduction; }


void Company::setYearlyBuy(int annualBuy) {
	yearlyBuy = annualBuy;
}

int Company::getYearlyBuy() const { return yearlyBuy; }

int Company::calculateReduction() const {
	return (reduction * yearlyBuy); // calculation of the reduction. 
}

string Company::toString() const {
	ostringstream output;

	Customer::toString();
	cout << "VAT: " << vat << endl;
	cout << "Reduction: " << reduction << endl;
	cout << "Yearly buy: " << yearlyBuy << endl;

	return output.str();
}