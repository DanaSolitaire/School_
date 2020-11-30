#include "UnoWildPick4Card.hxx"

UnoWildPick4Card::UnoWildPick4Card()
	:UnoWildCard()
{
}

UnoWildPick4Card::~UnoWildPick4Card()
{
}

//Returns name of this card as a string
const std::string UnoWildPick4Card::getName()
{
	return "UnoWildPick4Card";
}

//Returns a copy of this card as a ptr
UnoCard * UnoWildPick4Card::clone()
{
	UnoWildPick4Card* temp;
	temp = new UnoWildPick4Card();
	*temp = *this;
	return temp;
}
