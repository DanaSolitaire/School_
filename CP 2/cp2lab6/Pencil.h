#pragma once
#include "AssistedWI.h"
#include <string>
class Pencil :
	public AssistedWI
{
public:
	Pencil(const std::string& color);
	~Pencil();
	void activate();
	void deactivate();
	bool isWriting();
	const std::string& getName();
	void setName(const std::string& name);


};

