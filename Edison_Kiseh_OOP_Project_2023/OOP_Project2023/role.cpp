#include "role.h"

#include <iostream>
#include <string>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

void role::enterCustomerDetails(int choice, string& nameToUpdate) {
    string name, address, customerName;
    bool company;
    ComputerShop shop;
    Customer customer;

    cout << "Enter customer details: " << endl;
    cout << "Name: "; 
    getline(cin, name);
    
    cout << "Address: ";
    getline(cin, address);
    cout << "Company: ";
    cin >> company;

    if (choice == 1) {
        addCustomer(name, address, company, customer, shop);
    }
    else if (choice == 2) {
        updateCustomer(name, address, company, nameToUpdate);
    }

}

void role::addCustomer(string& name, string& address, bool company, Customer& customer, ComputerShop& shop) {
    if (shop.searchCustomer(name) == 1) {
        cout << "\nThe customer is already in the system" << endl;
    }
    else {
        customer.setName(name);
        customer.setAddress(address);
        customer.setCompany(company);
        customer.customerWriteFile();
        cout << "\nSuccessfully added customer" << endl;
    }
}

void role::viewCustomers() {
    ComputerShop shop;

    shop.customerReadFile();
}


void role::updateCustomer(string& newName, string& newAddress, bool company, string& nameToUpdate) {
    std::ifstream inputFile("files/customers.txt");
    std::ofstream outputFile("files/updated_customers.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        exit(-1);
    }

    int customerCompany;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name, address, comp;

        if (getline(iss, name, ',') && getline(iss, address, ',') && getline(iss, comp, ',')) {
            if (name == nameToUpdate) {
                // Update the name and address
                name = newName;
                address = newAddress;
                customerCompany = company;
            }
            else {
                customerCompany = stoi(comp);
            }
        }

        outputFile << name << ',' << address << ',' << customerCompany << '\n';
    }

    inputFile.close();
    outputFile.close();

    const char* filename = "files/customers.txt"; // Delete the old file
    std::remove(filename);

    // Renaming the updated file to the original file name
    if (std::rename("files/updated_customers.txt", "files/customers.txt") == 0) {
        std::cout << "\nChanges have been made successfully!" << std::endl;
    }
    else {
        std::cout << "Changes could not be made." << std::endl;
    }
}


void role::deleteCustomer(string& nameSearch) {
    std::ifstream inputFile("files/customers.txt");
    std::ofstream outputFile("files/updated_customers.txt");//temporary file to store the data
    string line;
    bool found;
    Customer customer;
    ComputerShop shop;

    found = shop.searchCustomer(nameSearch);

    if (found == 1) {
        while (getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string address, cor, name;

            if (getline(iss, name, ',') && getline(iss, address, ',') && getline(iss, cor, ',')) {
                if (nameSearch != name) {
                    outputFile << name << "," << address << "," << cor << endl;
                }
            }
        }
        cout << "\nCustomer deleted successfully." << endl;
    }
    else {
        cout << "\nThis customer does not exist in the system." << endl;
    }

    inputFile.close();
    outputFile.close();

    if (found == 1) {
        const char* filename = "files/customers.txt";//delete the old file

        std::remove(filename);

        // Renaming the updated file to the original file name so that it seems that the file was never deleted in the first place
        std::rename("files/updated_customers.txt", "files/customers.txt");
    }
}

void role::componentAction(int action) {
    Components* componentPtr;
    Battery bat;
    Case casee;

    string componentName;
    int quantity = 0;

    if (action == 1) {
        cout << "Enter the name of the component you want to add: ";
        cin >> componentName;
        cout << "How many of these are you willing to add? ";
        cin >> quantity;
    }
    else if (action == 2) {
        cout << "Enter the name of the component you want to update: ";
        cin >> componentName;
    }
    else if (action == 3) {
        cout << "Enter the name of the component you want to delete: ";
        cin >> componentName;
    }

    //creating new components depending on the user choice
    if (componentName == "battery") {
        componentPtr = new Battery("HP", componentName, 50, quantity, 1, 0, 10.0, 10.0, "serial number");
        componentPtr->addUpdateDeleteComponents(componentPtr, action);
    }
    else if (componentName == "case") {
        componentPtr = new Case("HP", componentName, 50, quantity, 1, 1, "black", "200MB", "Aluminium alloy");
        componentPtr->addUpdateDeleteComponents(componentPtr, action);
    }
    else if (componentName == "cpu") {
        componentPtr = new CPU("HP", componentName, 50, quantity, 1, 1, 3, 16, "socket");
        componentPtr->addUpdateDeleteComponents(componentPtr, action);
    }
    else if (componentName == "gpu") {
        componentPtr = new GPU("HP", componentName, 50, quantity, 1, 1, 20, 25);
        componentPtr->addUpdateDeleteComponents(componentPtr, action);
    }
    else if (componentName == "hd") {
        componentPtr = new HD("HP", componentName, 50, quantity, 1, 1, 30, 17, "slot");
        componentPtr->addUpdateDeleteComponents(componentPtr, action);
    }
    else if (componentName == "mb") {
        componentPtr = new MB("HP", componentName, 50, quantity, 1, 1, 17, "socket", "size");
        componentPtr->addUpdateDeleteComponents(componentPtr, action);
    }
    else if (componentName == "memory") {
        componentPtr = new Memory("HP", componentName, 50, quantity, 1, 1, 16, 20);
        componentPtr->addUpdateDeleteComponents(componentPtr, action);
    }
    else if (componentName == "ps") {
        componentPtr = new PS("HP", componentName, 50, quantity, 1, 1, 20, "ceritification");
        componentPtr->addUpdateDeleteComponents(componentPtr, action);
    }
    else if (componentName == "monitor") {
        componentPtr = new Monitor("HP", componentName, 50, quantity, 1, 0, 17, "resolution", "brand");
        componentPtr->addUpdateDeleteComponents(componentPtr, action);
    }
    else {
        cout << "No such component was found" << endl;
    }

}

void role::viewComponents() {
    bool option = 0;

     do
     {
        cout << "Which type of components do you want to view: " << endl;
        cout << "0). PC" << endl;
        cout << "1). Laptop" << endl;
        cin >> option;

        if (option != 0 && option != 1) {
            cout << "Please enter a valid option (0 or 1) " << endl;
        }
    }
    while (option != 0 && option != 1);

    Components* compPtr = new Battery();
    compPtr->viewComponentsStock(option);

    delete compPtr;
}

void role::goodbye() {
    cout << "--------------" << endl;
    cout << "See you later!" << endl;
    cout << "--------------" << endl;
    exit(-1);
}