#pragma once
#include "writingInstrument.h"
#include <string>

class AssistedWI :
	public writingInstrument
{
public:
	AssistedWI();
	~AssistedWI();
	void setColor(const std::string& givenColor);
	const std::string& getColor(const std::string& givenColor);
	const std::string& getName();
	void activate();
	void deactivate();

protected:

};

