#pragma once
#include "Components.h"
#include <string>

class MB : public Components
{
public:
	//default constructor
	MB();

	virtual ~MB() = default;//virtual destructor

	MB(const std::string&, const std::string&, int price, int stock, int type, bool laptop, int memorySlots, const std::string&, const std::string&);

	void setMemorySlots(int memorySlots);
	int getMemorySlots() const;

	void setSize(const std::string&);
	std::string getSize() const;

	void setSocket(const std::string&);
	std::string getSocket() const;

	virtual std::string toString() const override;

private:
	int memorySlots;
	std::string size;
	std::string socket;

};

