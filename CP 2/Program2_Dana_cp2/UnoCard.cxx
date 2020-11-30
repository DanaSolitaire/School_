#include "UnoCard.hxx"

UnoCard::UnoCard(char givenColor)
{
	setColor(givenColor);
}

UnoCard::~UnoCard()
{
}

//Sets color of card to given color
void UnoCard::setColor(char givenColor)
{
	color = givenColor;
}

//Returns color of card as a char
char UnoCard::getColor()
{
	return color;
}