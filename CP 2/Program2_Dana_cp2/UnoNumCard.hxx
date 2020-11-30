#ifndef UNO_NUM_CARD
#define UNO_NUM_CARD
#include "UnoCard.hxx"
#include <string>								//Used for name variable

class UnoNumCard :
	public UnoCard
{
public:
	UnoNumCard(char Color, int Number);
	~UnoNumCard();
	void setNumber(int Number);
	int getNumber();
	const std::string getName();
	UnoCard* clone();

protected:
	int number;
};

#endif;