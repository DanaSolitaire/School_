#include "UnoWildCard.hxx"

UnoWildCard::UnoWildCard()
	:UnoSpecialCard()
{
	color = getColor();
}

UnoWildCard::~UnoWildCard()
{
}

//Returns name of this card as a string
const std::string UnoWildCard::getName()
{
	return "UnoWildCard";
}

//Returns a copy of this card as a ptr
UnoCard* UnoWildCard::clone()
{
	UnoWildCard* temp;
	temp = new UnoWildCard;
	*temp = *this;
	return temp;
}

