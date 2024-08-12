#pragma once
#include <string>

class Components
{
public:
	//default constructor
	Components();

	virtual ~Components() = default;

	Components(const std::string&, const std::string&, int price, int stock, int type, bool laptop);

	void setManufacturer(const std::string&);
	std::string getManufacturer() const;

	void setName(const std::string&);
	std::string getName() const;

	void setPrice(int);
	int getPrice() const;

	void setStock(int);
	virtual int getStock() const;

	void setType(int);
	int getType() const;

	void setLaptop(bool laptop);
	bool getLaptop() const;

	virtual std::string toString() const = 0;

	void addUpdateDeleteComponents(Components*, int) const;
	void viewComponentsStock(bool laptop);
	
private:
	std::string manufacturer;
	std::string name;
	int price;
	int stock;
	int type;
	bool laptop;
};

