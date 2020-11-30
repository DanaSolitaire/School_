#include "Die.hxx"
namespace diens

{
	Die::Die(const unsigned SIDES)
	{
		if (SIDES < 2)
			exit(1);
		numOfSides = SIDES;
		roll();
	}

	Die::~Die()
	{
	}
	 
	void Die::roll() 
	{
		value = rand() % numOfSides;
	}
	unsigned Die::look() const
	{
		return value;
	}
	unsigned Die::sides() const
	{
		return numOfSides;
	}
}
