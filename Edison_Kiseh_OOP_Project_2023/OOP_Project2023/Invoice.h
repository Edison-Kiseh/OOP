#pragma once
#include "Components.h"
#include "Customer.h"
#include "Company.h"
#include "Components.h"
#include "CPU.h"
#include "GPU.h"
#include "HD.h"
#include "MB.h"
#include "Battery.h"
#include "Memory.h"
#include "Monitor.h"
#include "PS.h"
#include "Case.h"
#include "ComputerShop.h"

#include <vector>

class Invoice
{
public:
	//Default constructor
	Invoice();

	Invoice(int invoiceId, std::vector <Customer>&, std::vector <Components*>&, float totalPrice);

	void setInvoiceId(int invoiceId);
	int getInvoiceId() const;

	void setCustomer(std::vector <Customer>&);
	std::vector <Customer> getCustomer() const;

	void setComponents(std::vector <Components*>&);
	std::vector <Components*> getComponents() const;

	void setTotalPrice(float totalPrice);
	float getTotalPrice() const;

	void writeToFile(std::vector <Components*>&, int, Customer&) const;

	void buildSystem();
	
	void freePtrs(std::vector <Components*>&) const;

	std::string currentTime();

	int searchAndBuyComponents(std::vector <Components*>&, std::string);

private:
	int invoiceId;
	std::vector <Customer> customers;
	std::vector <Components*> components;
	float totalPrice;
	float calculateTotalPrice(std::vector <Components*>&, Customer&);
};

