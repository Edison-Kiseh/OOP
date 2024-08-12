#pragma once
#include <string>
#include <vector>

class Customer
{
public:
	//default constructor
	Customer();

	Customer(const std::string&, const std::string&, bool company);

	void setName(const std::string&);
	std::string getName() const;

	void setAddress(const std::string&) ;
	std::string getAddress() const;

	void setCompany(bool company);
	bool getCompany() const;

	std::string toString() const;

	void customerWriteFile();
	//void customerReadFile();
	void addUpdateDeleteCustomers(Customer*, int);
	Customer isCorporate(std::string&);

private:
	std::string name;
	std::string address;
	bool company;
};

