#pragma once
#include "Components.h"
class Monitor : public Components
{
public:
	Monitor();

	virtual ~Monitor() = default;

	Monitor(const std::string&, const std::string&, int price, int stock, int type, bool laptop, float size, const std::string&, const std::string&);

	void setSize(float);
	float getSize() const;

	void setResolution(const std::string&);
	std::string getResolution() const;

	void setBrand(const std::string&);
	std::string getBrand() const;

	virtual std::string toString() const override;
private:
	float size;
	std::string resolution;
	std::string brand;
};
