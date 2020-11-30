#ifndef _DIE_CLASS
#define _DIE_CLASS
#include <ctime>
#include <cstdlib>
namespace diens
{
	class Die
	{
	public:
		Die(const unsigned SIZES = 6u);
		~Die();
		void roll();
		unsigned look() const;
		unsigned sides() const;

	protected:
		unsigned numOfSides;
		unsigned value;
	};
}

#endif