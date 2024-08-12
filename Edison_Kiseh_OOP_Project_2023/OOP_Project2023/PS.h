#pragma once
#include "Components.h"
#include <string>

class PS : public Components
{
public:
	//default constructor
	PS();

	virtual ~PS() = default;//virtual destructor

	PS(const std::string&, const std::string&, int price, int stock, int type, bool laptop, int power, const std::string&);

	void setPower(int power);
	int getPower() const;

	void setCertification(const std::string&);
	std::string getCertification() const;

	virtual std::string toString() const override;
	

private:
	int power;
	std::string certification;
};

