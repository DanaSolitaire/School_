#ifndef UNOPICK2CARD
#define UNOPICK2CARD
#include "UnoSpecialCard.hxx"
class UnoPick2Card :
	public UnoSpecialCard
{
public:
	UnoPick2Card();
	~UnoPick2Card();
	const std::string getName();
	UnoCard* clone();
};

#endif