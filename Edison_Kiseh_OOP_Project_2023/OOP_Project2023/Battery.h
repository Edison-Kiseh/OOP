#pragma once
#include "Components.h"
class Battery : public Components
{
public:
	Battery();

	virtual ~Battery() = default;

	Battery(const std::string&, const std::string&, int price, int stock, int type, bool laptop, float capacity, float voltage, const std::string&);

	void setCapacity(float);
	float getCapacity() const;

	void setVoltage(float);
	float getVoltage() const;

	void setSerialNumber(const std::string&);
	std::string getSerialNumber() const;

	virtual std::string toString() const override;

	//virtual int getStock() const override;
	
private:
	float capacity;
	float voltage;
	std::string serialNumber;
};

