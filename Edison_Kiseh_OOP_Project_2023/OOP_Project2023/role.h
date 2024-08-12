#pragma once
#include "Customer.h"
#include "ComputerShop.h"
#include "Case.h"
#include "Invoice.h"
#include "Components.h"
#include "CPU.h"
#include "GPU.h"
#include "HD.h"
#include "MB.h"
#include "Battery.h"
#include "Memory.h"
#include "Monitor.h"
#include "PS.h"


class role {
public:
	void addCustomer(std::string&, std::string&, bool, Customer&, ComputerShop&);
	bool searchCustomer(std::string&);
	void goodbye();
	void enterCustomerDetails(int, std::string&);
	void viewCustomers();
	void updateCustomer(std::string&, std::string&, bool, std::string&);
	void componentAction(int);
	void deleteCustomer(std::string&);
	void viewComponents();
};