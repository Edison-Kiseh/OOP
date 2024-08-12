#pragma once
#include "Components.h"
class CPU : public Components
{
public:
	//default constructor
	CPU();

	virtual ~CPU() = default;//virtual destructor

	CPU(const std::string&, const std::string&, int price, int stock, int type, bool laptop, int speed, int cores, const std::string&);

	void setSpeed(int speed);
	int getSpeed() const;

	void setCores(int cores);
	int getCores() const;

	void setSocket(const std::string&);
	std::string getSocket() const;

	virtual std::string toString() const override;

private:
	int speed;
	int cores;
	std::string socket;
};

