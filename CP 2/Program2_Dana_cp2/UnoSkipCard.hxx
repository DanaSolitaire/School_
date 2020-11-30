#ifndef UNOSKIPCARD
#define UNOSKIPCARD
#include "UnoSpecialCard.hxx"
class UnoSkipCard :
	public UnoSpecialCard
{
public:
	UnoSkipCard();
	~UnoSkipCard();
	const std::string getName();
	UnoCard* clone();
};

#endif