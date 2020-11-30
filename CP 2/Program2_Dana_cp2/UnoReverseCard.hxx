#ifndef UNOREVERSECARD
#define UNOREVERSECARD
#include "UnoSpecialCard.hxx"
class UnoReverseCard :
	public UnoSpecialCard
{
public:
	UnoReverseCard();
	~UnoReverseCard();
	const std::string getName();
	UnoCard* clone();
};

#endif