#include "ComputerShop.h"
#include "Components.h"
#include "Customer.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

ComputerShop::ComputerShop() {
	name = "Computer shop";
	address = "Jan Pieter De Nayerlaan 5, Sint-Katelijn-Waver";
}

ComputerShop::ComputerShop(const string& namee, const string& addresss, vector <Components*>& component, vector <Customer>& customer) {
	name = namee;
	address = addresss;
	components = component;
	customers = customer;
}

void ComputerShop::setName(const std::string& namee) {
	name = namee;
}

string ComputerShop::getName() const { return name; }

void ComputerShop::setAddress(const std::string& addresss) {
	address = addresss;
}

string ComputerShop::getAddress() const { return address; }

void ComputerShop::setComponents(std::vector <Components*>& component) {
	components = component;
}

vector <Components*> ComputerShop::getComponents() const { return components; }

void ComputerShop::setCustomers(std::vector <Customer>& customer) {
	customers = customer;
}

vector <Customer> ComputerShop::getCustomers() const {
	return customers; 
}

void ComputerShop::customerReadFile() {

	ifstream inputFile("files/customers.txt", ios::in);

	std::string line;

	std::string name, address;
	bool company = 0;

	while (std::getline(inputFile, line)) {

		std::istringstream iss(line);

		// the file is comma seperated so i needed to clarify here that each field is to be read until a ,
		if (std::getline(iss, name, ',') && std::getline(iss, address, ',') && (iss >> company)) {
			// Add the record to the vector
			Customer data{ name, address, company };
			customers.push_back(data);
		}
		else {
			std::cerr << "Error parsing line: " << line << std::endl;
		}
	}

	// Close the file
	inputFile.close();

	cout << "Customer list" << endl;
	cout << "-------------" << endl;
	for (const auto& customer : customers) {//reading the customer details in to the customers vector in this class
		cout << "Name: " << customer.getName() << endl;
		cout << "Address: " << customer.getAddress() << endl;
		cout << "Company: " << customer.getCompany() << endl;
		cout << "-------------------" << endl;
	}

}

bool ComputerShop::searchCustomer(const string& namee) {

	ifstream inputFile("files/customers.txt", ios::in);

	std::string line;

	std::string name, address;
	bool company = 0;

	while (std::getline(inputFile, line)) {

		std::istringstream iss(line);

		// the file is comma seperated so i needed to clarify here that each field is to be read until a ,
		if (std::getline(iss, name, ',') &&
			std::getline(iss, address, ',') &&
			(iss >> company)) {
			// Add the record to the vector
			Customer data{ name, address, company };
			customers.push_back(data);
		}
		else {
			std::cerr << "Error parsing line: " << line << std::endl;
		}
	}

	inputFile.close();

	for (const auto& customer : customers) {
		if (customer.getName() == namee) {
			return 1;
		}
	}
}


string ComputerShop::toString() const {
	ostringstream output;

	cout << "Shop name: " << name << endl;
	cout << "Address: " << address << endl << endl;
	cout << "Customers" << endl;
	for (Customer cust : customers) {
		cout << "Customer name: " << cust.getName() << endl;
		cout << "Customer address: " << cust.getAddress() << endl;
		cout << "Company member? " << cust.getCompany() << endl;
	}

	return output.str();
}

