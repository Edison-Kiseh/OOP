#include "menu.h"
#include "role.h"
#include "Invoice.h"

#include <iostream>

using namespace std;

void menu::options(string title) {
    ComputerShop shop;
    User user;
    Invoice in;
    role role;
    int option, sysType;
    std::string userRole, customerName;

    //userRole = user.getRole();

    if (title == "employee") {
        while (true) {
            cout << "\nWhat do you want to do?" << endl;
            cout << "1). Add new customer" << endl;
            cout << "2). Update an existing customer" << endl;
            cout << "3). Build system" << endl;
            cout << "4). View stock" << endl;
            cout << "5). Customer list" << endl;
            cout << "6). Exit" << endl;

            cin >> option;
            cin.ignore();
            switch (option)
            {
            case 1:
                role.enterCustomerDetails(option, customerName);
                break;
            case 2:
                cout << "Enter the name of the customer you want to update: ";
                getline(cin, customerName);

                if (shop.searchCustomer(customerName) == 1) {
                    role.enterCustomerDetails(option, customerName);
                }
                else {
                    cout << "This customer does not exist" << endl;
                }
                break;
            case 3:
               // cout << "Which kind of system do you want to build?(PC: 0; Laptop: 1; Custom: 2;)\n";
                in.buildSystem();
                break;
            case 4:
                role.viewComponents();
                break;
            case 5:
                role.viewCustomers();
                break;
            case 6:
                role.goodbye();
                break;
            default: cout << "Please make a valid choice!" << endl;
                break;
            }
        }

    }
    else {
        while (true) {
            cout << "\nWhat do you want to do?" << endl;
            cout << "1). Add new customer" << endl;
            cout << "2). Update an existing customer" << endl;
            cout << "3). Delete customer" << endl;
            cout << "4). Add component" << endl;
            cout << "5). Update component" << endl;
            cout << "6). Delete component" << endl;
            cout << "7). View stock" << endl;
            cout << "8). Customer list" << endl;
            cout << "9). Exit" << endl;

            cin >> option;
            cin.ignore();
            int choice;
            switch (option)
            {
            case 1:
                role.enterCustomerDetails(option, customerName);
                break;
            case 2:
                cout << "Enter the name of the customer you want to update: ";
                getline(cin, customerName);

                if (shop.searchCustomer(customerName) == 1) {
                    role.enterCustomerDetails(option, customerName);
                }
                else {
                    cout << "This customer does not exist" << endl;
                }
                break;
            case 3:
                cout << "Enter the name of the customer you want to delete: ";
                getline(cin, customerName);
                role.deleteCustomer(customerName);
                break;
            case 4:
                role.componentAction(choice = 1);
                break;
            case 5:
                role.componentAction(choice = 2);
                break;
            case 6:
                role.componentAction(choice = 3);
                break;
            case 7:
                role.viewComponents();
                break;
            case 8:
                role.viewCustomers();
                break;
            case 9:
                role.goodbye();
                break;
            default: cout << "Please make a valid choice!" << endl;
                break;
            }
        }
    }
    
}