#pragma once
#include <string>
class writingInstrument
{
public:
	writingInstrument(const std::string& name, bool state = false);
	writingInstrument();
	virtual ~writingInstrument();
	virtual void setName(const std::string& name) = 0;
	virtual void activate() = 0;
	virtual void deactivate() = 0;
	virtual bool isWriting() = 0;
	virtual const std::string& getName() = 0;

protected:
	bool on;
	const std::string& myName;
};

