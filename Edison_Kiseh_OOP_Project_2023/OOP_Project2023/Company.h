#pragma once
#include "Customer.h"
class Company : public Customer
{
public:
	//default constructor
	Company();

	Company(const std::string&, const std::string&, bool company, int vat, int reduction, int yearlyBuy);

	void setVat(int vat);
	int getVat() const;

	void setReduction(int reduction);
	int getReduction() const;

	void setYearlyBuy(int yearlyBuy);
	int getYearlyBuy() const;

	std::string toString() const;
private:
	int vat;
	int reduction;
	int yearlyBuy;
	int calculateReduction() const;
};

