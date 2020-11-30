#ifndef UNOWILDCARD
#define UNOWILDCARD
#include "UnoSpecialCard.hxx"

class UnoWildCard :
	public UnoSpecialCard
{
public:
	UnoWildCard();
	~UnoWildCard();
	const std::string getName();
	UnoCard* clone();
};
#endif
