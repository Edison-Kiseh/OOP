#include <string>

#include "user.h"

using namespace std;

std::string User::getUsername() {
    return username;
}

std::string User::getPassword() {
    return password;
}

std::string User::getRole() {
    return role;
}

void User::setUsername(std::string inputUsername) {
    username = inputUsername;
}

void User::setPassword(std::string inputPassword) {
    password = inputPassword;
}

void User::setRole(std::string inputRole) {
    role = inputRole;
}


User::User() {
    password = "password";
}

void User::userWriteToFile(string& username, string& role) {
    fstream inputFile("files/users.txt", ios::app);

    if (inputFile.is_open()) {
        inputFile << "Username: " << username << " Role: " << role << endl;
        inputFile << "----------------------------------" << endl;

        inputFile.close();
    }
    else {
        cout << "Could not open the users.txt file" << endl;
    }
}