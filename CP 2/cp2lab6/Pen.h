#ifndef _PENCLASS
#define _PENCLASS

#include "AssistedWI.h"
#include <string>
class Pen :
	public AssistedWI
{
public:
	Pen(const std::string& color = "none");
	~Pen();
	void setColor(const std::string& givenColor);
	const std::string& getColor(const std::string& givenColor);
	const std::string& getName();
	void activate();
	void deactivate();

private:
	const std::string& color;
};

#endif