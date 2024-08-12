#pragma once
#include "Components.h"
class HD : public Components
{
public:
	//default constructor
	HD();

	virtual ~HD() = default;//virtual destructor

	HD(const std::string&, const std::string&, int price, int stock, int type, bool laptop, int speed, int size, const std::string&);

	void setSpeed(int speed);
	int getSpeed() const;

	void setSize(int size);
	int getSize() const;

	void setSlot(const std::string&);
	std::string getSlot() const;

	virtual std::string toString() const override;

private:
	int speed;
	int size;
	std::string slot;
};

