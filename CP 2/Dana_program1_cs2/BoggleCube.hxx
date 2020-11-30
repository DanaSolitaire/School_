#ifndef BOGGLECUBECLASS
#define BOGGLECUBECLASS

#include <cstdlib>
#include <algorithm>

namespace bogglecubens
{
	class BoggleCube
	{
	public:
		BoggleCube(char*);
		BoggleCube();
		~BoggleCube();
		char at(unsigned) const;
		char letter();
		void set(char*);
		void randomize();

	protected:
		char* sideArrayPtr;

	};
}
#endif
