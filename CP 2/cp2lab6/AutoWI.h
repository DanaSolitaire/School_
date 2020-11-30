#pragma once
#include "writingInstrument.h"
class AutoWI :
	public writingInstrument
{
public:
	AutoWI();
	virtual ~AutoWI();
	void activate();
	void deactivate();
	bool isWriting();


};

