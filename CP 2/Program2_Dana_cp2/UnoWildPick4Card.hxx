#ifndef UNOWILDPICK4CARD
#define UNOWILDPICK4CARD
#include "UnoWildCard.hxx"


class UnoWildPick4Card :
	public UnoWildCard
{
public:
	UnoWildPick4Card();
	~UnoWildPick4Card();
	const std::string getName();
	UnoCard* clone();
};

#endif