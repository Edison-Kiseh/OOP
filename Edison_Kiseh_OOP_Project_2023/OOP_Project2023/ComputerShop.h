#pragma once
#include <string>
#include <vector>
#include "Components.h"
#include "Customer.h"

class ComputerShop
{
public:
	//default constructor
	ComputerShop();

	ComputerShop(const std::string&, const std::string&, std::vector <Components*>&, std::vector <Customer>&);

	void setName(const std::string&);
	std::string getName() const;

	void setAddress(const std::string&);
	std::string getAddress() const;

	void setComponents(std::vector <Components*>&);
	std::vector <Components*> getComponents() const;

	void setCustomers(std::vector <Customer>&);
	std::vector <Customer> getCustomers() const;

	std::string toString() const;
	void customerReadFile();

	bool searchCustomer(const std::string&);
private:
	std::string name;
	std::string address;
	std::vector <Components*> components;
	std::vector <Customer> customers;
};

