#include "UnoReverseCard.hxx"

UnoReverseCard::UnoReverseCard()
	:UnoSpecialCard()
{
}

UnoReverseCard::~UnoReverseCard()
{
}

//Returns name of this card as a string
const std::string UnoReverseCard::getName()
{
	return "UnoReverseCard";
}

//Returns a copy of this card as a ptr
UnoCard * UnoReverseCard::clone()
{
	UnoReverseCard* temp;
	temp = new UnoReverseCard();
	*temp = *this;
	return temp;
}
