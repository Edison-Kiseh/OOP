#include "Customer.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

Customer::Customer() {
	name = "N/A";
	address = "N/A";
	company = NULL;
}


Customer::Customer(const string& namee, const string& addresss, bool comp) {
	name = namee;
	address = addresss;
	company = comp;
}

void Customer::setName(const string& namee) {
	name = namee;
}

string Customer::getName() const { return name; }


void Customer::setAddress(const string& addresss) {
	address = addresss;
}

string Customer::getAddress() const { return address; }


void Customer::setCompany(bool comp) {
	company = comp;
}

bool Customer::getCompany() const { return company; }

void Customer::customerWriteFile() {

	ofstream outputFile("files/customers.txt", ios::app);

	if (outputFile.is_open()) {
		outputFile << name << ",";
		outputFile << address << ",";
		outputFile << company << endl;
	}
	else {
		cout << "The customers file could not be opened" << endl;
		exit(-1);
	}
	
	outputFile.close();
}

Customer Customer::isCorporate(string& nameSearch) {
	ifstream inputFile("files/customers.txt");
	string line;
	bool found, corporate;
	Customer customer;

	while (getline(inputFile, line)) {
		std::istringstream iss(line);
		std::string address, cor;

		if (getline(iss, name, ',') && getline(iss, address, ',') && getline(iss, cor, ',')) {
			if (nameSearch == name) {
				corporate = stoi(cor);//convert the string to int

				customer.setName(name);
				customer.setAddress(address);
				customer.setCompany(corporate);

				break;
			}
		}
	}

	inputFile.close();
	return customer;
}

string Customer::toString() const {
	ostringstream output;

	cout << "Customer name: " << name << endl;
	cout << "Customer address: " << address << endl;
	cout << "Company: " << company << endl;

	return output.str();
}


