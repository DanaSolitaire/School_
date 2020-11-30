#include "writingInstrument.h"

writingInstrument::writingInstrument(const std::string & name, bool state)
	:myName(name), on(state)
{
}

writingInstrument::writingInstrument()
	:myName("none")
{
}

writingInstrument::~writingInstrument()
{
}
