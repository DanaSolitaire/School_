#include "AutoWI.h"


AutoWI::AutoWI()
{
}


AutoWI::~AutoWI()
{
}

void AutoWI::activate()
{
	on = true;
}

void AutoWI::deactivate()
{
	on = false;
}

bool AutoWI::isWriting()
{
	return on;
}
