#pragma once
#include "Components.h"
class Case : public Components
{
public:
	//default constructor
	Case();

	virtual ~Case() = default;//virtual destructor

	Case(const std::string&, const std::string&, int price, int stock, int type, bool laptop, const std::string&, const std::string&, const std::string&);

	void setColor(const std::string&);
	std::string getColor() const;

	void setMBSize(const std::string&);
	std::string getMBSize() const;

	void setMaterial(const std::string&);
	std::string getMaterial() const;

	virtual std::string toString() const override;

private:
	std::string color;
	std::string MBSize;
	std::string material;
};

