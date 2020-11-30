#include "UnoNumCard.hxx"

UnoNumCard::UnoNumCard(char Color, int Number)
	:UnoCard(Color)
{
	setNumber(Number);
}

UnoNumCard::~UnoNumCard()
{
}

//Sets card's number to given int number
void UnoNumCard::setNumber(int givenNumber)
{
	number = givenNumber;
}

//Returns card's number as an int
int UnoNumCard::getNumber()
{
	return number;
}

//Returns name of this card as a string
const std::string UnoNumCard::getName()
{
	return "UnoNumCard";
}

//Returns a copy of this card as a ptr
UnoCard* UnoNumCard::clone()
{
	UnoNumCard* temp;
	temp = new UnoNumCard('R',0);
	*temp = *this;
	return temp;
}