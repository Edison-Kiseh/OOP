#include "Components.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//default constructor
Components::Components() {
	manufacturer = "N/A";
	name = "N/A";
	price = NULL;
	stock = NULL;
	type = NULL;
	laptop = NULL;
}

Components::Components(const string& manufact, const string& userName, int cost, int quantity, int genre, bool lapt) {
	manufacturer = manufact;
	name = userName;
	price = cost;
	stock = quantity;
	type = genre;
	laptop = lapt;
}

void Components::setManufacturer(const string& manufact) {
	manufacturer = manufact;
}

string Components::getManufacturer() const { return manufacturer; }


void Components::setName(const string& userName) {
	name = userName;
}

string Components::getName() const { return name; }


void Components::setPrice(int cost) {
	price = cost;
}

int Components::getPrice() const { return price; }


void Components::setStock(int quantity) {
	stock = quantity;
}

int Components::getStock() const { return stock; }


void Components::setType(int genre) {
	type = genre;
}

int Components::getType() const { return type; }


void Components::setLaptop(bool lapt) {
	laptop = lapt;
}

bool Components::getLaptop() const { return laptop; }


string Components::toString() const {
	ostringstream output;

	std::cout << "Manufacturer: " << manufacturer << endl;
	std::cout << "Component name: " << name << endl;
	std::cout << "Price: " << price << endl;
	std::cout << "Stock: " << stock << endl;
	std::cout << "Type: " << type << endl;
	std::cout << "Laptop: " << laptop << endl;

	return output.str();
}


void Components::addUpdateDeleteComponents(Components* compPtr, int action) const {

	if (action == 1 || action == 2 || action == 3) {//all three require similar code so to avoid too much repetition i decided to use them together
		ifstream inputFile("files/components.txt");
		ofstream outputFile("files/updated_components.txt");

		if (!inputFile.is_open() || !outputFile.is_open()) {
			std::cerr << "Error opening files!" << endl;
			exit(-1);
		}

		string line;
		while (getline(inputFile, line)) {
			stringstream iss(line);
			string name;
			int stock = 0;
			float price;

			if (iss >> name >> price >> stock) {
				if (name == compPtr->getName()) {
					if (action == 1) {//adding the component
						stock += compPtr->getStock();
					}
					else if (action == 2) {//updating the component
						std::cout << "Enter the new component price: ";
						cin >> price;
						std::cout << "Enter the component quantity: ";
						cin >> stock;
					}
					else if (action == 3) {//deleting the component
						stock = NULL;
						price = NULL;
					}
				}
			}

			outputFile << name << "\t" << price << "\t" << stock << endl;
		}

		if (action == 1) { std::cout << "\nThe component has been added successfully!\n"; }
		else if (action == 2) { std::cout << "\nThe component has been updated successfully!\n"; }
		else if (action == 3) { std::cout << "\nThe component has been deleted.\n"; }

		inputFile.close();
		outputFile.close();

		const char* filename = "files/components.txt"; // Delete the old file
		std::remove(filename);

		// Renaming the updated file to the original file name
		if (rename("files/updated_components.txt", "files/components.txt") == 0) {
			std::cout << "\nChanges have been made successfully!" << endl;
		}
		else {
			std::cout << "Changes could not be made." << endl;
		}

		delete compPtr;
	}
}


void Components::viewComponentsStock(bool laptop) {
	ifstream inputFile("files/components.txt");

	if (!inputFile.is_open()) {
		cerr << "Error opening file" << std::endl;
		exit(-1);
	}

	string line;
	if (laptop == 0) {
		std::cout << "\nPC components in stock" << endl;
		std::cout << "---------------------" << endl;
	}
	else if (laptop == 1) {
		std::cout << "\nLaptop components in stock" << endl;
		std::cout << "---------------------" << endl;
	}

	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);
		std::string name;
		int stock;
		float price;

		if (iss >> name >> price >> stock) {
			if (laptop == 0) {//if it is a PC component
				if (name != "battery") {//because PCs don't have batteries
					std::cout << "Name: " << name << endl;
					std::cout << "Stock: " << stock << endl;
					std::cout << "Price: " << price << endl;
					std::cout << "------------" << endl;
				}
			}
			else if (laptop == 1) {
				if (name != "monitor") {//i intended for the monitor to be a PC component only
					std::cout << "Name: " << name << endl;
					std::cout << "Stock: " << stock << endl;
					std::cout << "Price: " << price << endl;
					std::cout << "------------" << endl;
				}
			}
 		}

	}

	inputFile.close();
}
