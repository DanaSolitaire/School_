#ifndef UNOCARD
#define UNOCARD
#include <string>
//Base abstract class for all the Uno Card classes
class UnoCard
{
public:
	UnoCard(char Color);
	virtual ~UnoCard();
	void setColor(char Color);
	char getColor();
	virtual const std::string getName() = 0;
	virtual UnoCard* clone() = 0;

protected:
	char color;
};

#endif