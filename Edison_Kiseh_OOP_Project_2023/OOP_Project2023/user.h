#pragma once
#include <string>
#include <fstream>
#include <iostream>

class User {

public:
    User();

    std::string getUsername();
    std::string getPassword();
    std::string getRole();
    bool getStatus();

    void setUsername(std::string inputUsername);
    void setPassword(std::string inputPassword);
    void setRole(std::string inputRole);

    void userWriteToFile(std::string&, std::string&);

private:
    std::string username;
    std::string password;
    std::string role;
};

