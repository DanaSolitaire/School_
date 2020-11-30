#include "UnoPick2Card.hxx"

UnoPick2Card::UnoPick2Card()
	:UnoSpecialCard()
{
}


UnoPick2Card::~UnoPick2Card()
{
}

//Returns name of card as a string
const std::string UnoPick2Card::getName()
{
	return "UnoPick2Card";
}

//Returns a copy of this card as a ptr
UnoCard* UnoPick2Card::clone()
{
	UnoPick2Card* temp;
	temp = new UnoPick2Card;
	*temp = *this;
	return temp;
}