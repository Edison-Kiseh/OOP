#pragma once
#include "Components.h"
#include <string>

class GPU : public Components
{
public:
	//default constructor
	GPU();

	virtual ~GPU() = default;//virtual destructor

	GPU(const std::string&, const std::string&, int price, int stock, int type, bool laptop, int power, int busSpeed);

	void setPower(int power);
	int getPower() const;

	void setBusSpeed(int busSpeed);
	int getBusSpeed() const;

	virtual std::string toString() const override;

private:
	int power;
	int busSpeed;
};

 