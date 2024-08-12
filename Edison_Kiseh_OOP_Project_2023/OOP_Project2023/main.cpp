#include <iostream>
#include <algorithm>
#include <string>

#include "user.h"
#include "menu.h"

using namespace std;

void authenticateUser(User);

int main(void) {
	User user;
    menu menu;
	
	int choice = 0;
	int loggedIn = 0;

	do {
		cout << "-----Login menu-----" << endl;
		cout << "\t1.Owner" << endl;
		cout << "\t2.Employee" << endl;
		cout << "\t3.Logout" << endl;
		cout << "Make a choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			user.setRole("owner");
			authenticateUser(user);
			loggedIn = 1;
            cout << "\nWelcome owner" << endl;
            cout << "-----------------" << endl;
            menu.options("owner");
			break;
		case 2:
			user.setRole("employee");
			authenticateUser(user);
			loggedIn = 1;
			cout << "\nWelcome employee" << endl;
			cout << "-----------------" << endl;
			menu.options("employee");
			break;
		case 3:
			cout << "See you later!" << endl;
			loggedIn = 0;
			break;
		default:
			cout << "\n\nPlease make a choice between 1, 2 and 3" << endl;
			break;
		}

	} while (choice != 3 && loggedIn != 1);
	
	return 0;
}

void authenticateUser(User user) {
	int attemps = 0;
	string inputPassword = "", inputUsername, role;

	while (attemps <= 3 && inputPassword != user.getPassword()) {
		cin.ignore();
		cout << "Username: ";
		getline(cin,inputUsername);
		cout << "Password: ";
		cin >> inputPassword;
		attemps++;

		//comparing the password to the predefined password in the header file
		if (inputPassword != user.getPassword()) {
			cout << "The password is incorrect" << endl;
		}

		if (inputPassword == user.getPassword()) {
			user.setUsername(inputUsername);
			role = user.getRole();
			user.userWriteToFile(inputUsername, role);//write user info to file
		}
		else if (attemps >= 3) {//exit if the attemps go up to three
			cout << "To many attempts!" << endl;
			exit(-1);
		}
	}
}
