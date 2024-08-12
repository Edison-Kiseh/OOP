#define _CRT_SECURE_NO_WARNINGS

#include "Invoice.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

Invoice::Invoice() {
	invoiceId = NULL;
	totalPrice = NULL;
}

Invoice::Invoice(int invoiceIdd, std::vector <Customer>& customer, std::vector <Components*>& component, float totalCost) {
	invoiceId = invoiceIdd;
	customers = customer;
	components = component;
	totalPrice = totalCost;
}

void Invoice::setInvoiceId(int invoiceIdd) {
	invoiceId = invoiceIdd;
}

int Invoice::getInvoiceId() const { return invoiceId; }


void Invoice::setCustomer(std::vector <Customer>& customer) {
	customers = customer;
}

vector <Customer> Invoice::getCustomer() const { return customers; }

void Invoice::setComponents(std::vector <Components*>& component) {
	components = component;
}

vector <Components*> Invoice::getComponents() const { return components; }

void Invoice::setTotalPrice(float totalCost) {
	totalPrice = totalCost;
}

float Invoice::getTotalPrice() const { return totalPrice; }


float Invoice::calculateTotalPrice(std::vector <Components*>& components, Customer& customer) {
	float total = 0.0, discount = 0.0;
	Company comp;

	// Applying a discount and different prices for corporate customers
	if (customer.getCompany() == 1) {
		for (const auto& component : components) {
			total += component->getPrice() - comp.getReduction();
		}

		discount = (total / 100) * comp.getReduction();
		total = (total - discount);  
	}
	else {//none corporate customers
		for (const auto& component : components) {
			total += component->getPrice();
		}
	}

	return total;
}

void Invoice::writeToFile(std::vector <Components*>& components, int price, Customer& customer) const {
	Invoice in; 
	Company comp;
	ofstream outputFile("files/invoice.txt", ios::app);

	if (outputFile.is_open()) {
		outputFile << "\nInvoice for " << customer.getName() << endl;
		outputFile << "-----------------------" << endl;
		
		if (customer.getCompany() == 1) {
			for (const auto& line : components) {
				outputFile << line->getName() << ": " << line->getPrice() - comp.getReduction() << '\n';
			}
		}
		else {
			for (const auto& line : components) {
				outputFile << line->getName() << ": " << line->getPrice() << '\n';
			}
		}

		outputFile << "The total is: " << price << endl;
		outputFile << in.currentTime() << endl;
		outputFile << "------------------------" << endl;
	}
	else {
		cout << "The file could not be opened";
		exit(-1);
	}

	cout << "-------------------------------------" << endl;
	cout << "Invoice has been created successfully" << endl;

	cout << "-------------------------------------" << endl;

	freePtrs(components); //freeing all the component pointers
	outputFile.close();
}

void Invoice::buildSystem() {
	string compType, name;
    Invoice in;
	int price = 0, option, found;
	Customer customer;
	ComputerShop shop;
	bool find, corporate;

	cout << "For which customer do you want to build this system? ";
	getline(cin, name);

	find = shop.searchCustomer(name);

	if (find == 1) {
		cout << "\nSelect the components that you want to buy: " << endl;
		do{
			cout << "------------------------" << endl;
			cout << "1). Case" << endl;
			cout << "2). CPU" << endl;
			cout << "3). GPU" << endl;
			cout << "4). Battery" << endl;
			cout << "5). HD" << endl;
			cout << "6). MB" << endl;
			cout << "7). Memory" << endl;
			cout << "8). PS" << endl;
			cout << "9). Monitor" << endl;
			cout << "10). Proceed to check out" << endl;
			cout << "------------------------" << endl;

			cin >> option;

			//building the system
			//first checking if the components are in stock
			switch (option)
			{
			case 1: found = in.searchAndBuyComponents(components, "case");
					if(found == 1){ components.push_back(new Case("HP", "Case", 50, 1, 1, 0, "black", "200MB", "Aluminium alloy")); cout << "\nComponent added!\n"; break; }
					else { cout << "\nThis component is no longer in stock\n"; break; }

			case 2: found = in.searchAndBuyComponents(components, "cpu");
					if (found == 1) { components.push_back(new CPU("HP", "CPU", 50, 1, 1, 0, 3, 16, "socket")); cout << "\nComponent added!\n"; break; }
					else { cout << "\nThis component is no longer in stock\n"; break; }
					
			case 3: found = in.searchAndBuyComponents(components, "gpu");
					if (found == 1) { components.push_back(new GPU("HP", "GPU", 50, 1, 1, 0, 20, 25)); cout << "\nComponent added!\n"; break; }
					else { cout << "\nThis component is no longer in stock\n"; break; }

			case 4: found = in.searchAndBuyComponents(components, "battery");
					if (found == 1) { components.push_back(new Battery("HP", "PS", 50, 1, 1, 1, 20, 3.3, "Serial number")); cout << "\nComponent added!\n"; break; }
					else { cout << "\nThis component is no longer in stock\n"; break; }
					
			case 5: found = in.searchAndBuyComponents(components, "hd");
					if (found == 1) { components.push_back(new HD("HP", "HD", 50, 1, 1, 0, 30, 17, "slot")); cout << "\nComponent added!\n"; break; }
					else { cout << "\nThis component is no longer in stock\n"; break; }
					
			case 6: found = in.searchAndBuyComponents(components, "mb");
					if (found == 1) { components.push_back(new MB("HP", "MB", 50, 1, 1, 0, 17, "socket", "size")); cout << "\nComponent added!\n"; break; }
					else { cout << "\nThis component is no longer in stock\n"; break; }
					
			case 7: found = in.searchAndBuyComponents(components, "memory");
					if (found == 1) { components.push_back(new Memory("HP", "Memory", 50, 1, 1, 0, 16, 20)); break; cout << "\nComponent added!\n"; }
					else { cout << "\nThis component is no longer in stock\n"; break; }
					
			case 8: found = in.searchAndBuyComponents(components, "ps");
					if (found == 1) { components.push_back(new PS("HP", "PS", 50, 1, 1, 0, 20, "ceritification")); break; cout << "\nComponent added!\n"; }
					else { cout << "\nThis component is no longer in stock\n"; break; }
					
			case 9: found = in.searchAndBuyComponents(components, "monitor");
					if (found == 1) { components.push_back(new Monitor("HP", "Monitor", 50, 1, 1, 0, 17, "resolution", "brand")); break; cout << "\nComponent added!\n"; }
					else { cout << "\nThis component is no longer in stock\n"; break; }
					
			case 10: cout << "Thanks for visiting us!" << endl; break;
			default: cout << "Please enter a valid option (1-10)" << endl;
				break;
			}

		} while (option != 10);
	
		
		customer = customer.isCorporate(name);//check if the customer is corporate

		price = calculateTotalPrice(components, customer);

		in.writeToFile(components, price, customer);

	}

	else {
		cout << "This customer doesn't exist in the system" << endl;
	}
}

string Invoice::currentTime() {
	string date;
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	std::tm* timeInfo = std::localtime(&currentTime);
	std::stringstream dateString;

	dateString << "Transaction done on the: " << timeInfo->tm_mon + 1 << "/" << timeInfo->tm_mday << "/" << timeInfo->tm_year + 1900 << " at: " << timeInfo->tm_hour << ":" << timeInfo->tm_min << ":" << timeInfo->tm_sec << endl;

	date = dateString.str();

	return date;
}


void Invoice::freePtrs(std::vector <Components*>& components) const {
	for (const auto& componentPtr : components) {//delete the component pointers
		delete componentPtr;
	}
}

//performing the buying of components as in reducing the amount of components bought by the customer from the stock
//and telling the customer if the component is in stock or not
int Invoice::searchAndBuyComponents(std::vector <Components*>& components, string componentName) {
	ifstream inputFile("files/components.txt");
	ofstream outputFile("files/updated_components.txt");

	if (!inputFile.is_open() || !outputFile.is_open()) {
		cerr << "Error opening file" << std::endl;
		exit(-1);
	}

	string line;
	int found = 0;
	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);
		std::string name;
		int stock;
		float price;

		if (iss >> name >> price >> stock) {
			if (name == componentName) {
				if (stock == 0) {
					found = 0;
				}
				else {
					stock -= 1;
					found = 1;
				}
			}
		}
		outputFile << name << "\t" << price << "\t" << stock << endl;
	}

	inputFile.close();
	outputFile.close();

	const char* filename = "files/components.txt";//delete the old file

	std::remove(filename);

	std::rename("files/updated_components.txt", "files/components.txt");

	return found;
}