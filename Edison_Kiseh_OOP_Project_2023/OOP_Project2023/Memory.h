#pragma once
#include "Components.h"
class Memory : public Components
{
public:
	//default constructor
	Memory();

	virtual ~Memory() = default;//virtual destructor

	Memory(const std::string&, const std::string&, int price, int stock, int type, bool laptop, int size, int speed);

	void setSize(int size);
	int getSize() const;

	void setSpeed(int speed);
	int getSpeed() const;

	virtual std::string toString() const override;

private:
	int speed;
	int size;
};

