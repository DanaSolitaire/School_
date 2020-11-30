#include "UnoSkipCard.hxx"

UnoSkipCard::UnoSkipCard()
	:UnoSpecialCard()
{
}

UnoSkipCard::~UnoSkipCard()
{
}

//Returns name of this card as a string
const std::string UnoSkipCard::getName()
{
	return "UnoSkipCard";
}

//Returns a copy of this card as a ptr
UnoCard* UnoSkipCard::clone()
{
	UnoSkipCard* temp;
	temp = new UnoSkipCard;
	*temp = *this;
	return temp;
}