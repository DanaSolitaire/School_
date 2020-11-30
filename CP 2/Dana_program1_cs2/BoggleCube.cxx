#include "BoggleCube.hxx"

namespace bogglecubens
{
	BoggleCube::BoggleCube(char* passed_array)
	{
		sideArrayPtr = nullptr;
		sideArrayPtr = new char[7];
	}

	BoggleCube::BoggleCube()
	{
	}


	BoggleCube::~BoggleCube()
	{
		sideArrayPtr = nullptr;
		delete[] sideArrayPtr;
	}

	char BoggleCube::letter()
	{
		return sideArrayPtr[0];
	}

	char BoggleCube::at(unsigned passed_index) const
	{
		return sideArrayPtr[passed_index];
	}

	void BoggleCube::set(char* sideArrayPtr)
	{
		std::copy(sideArrayPtr, sideArrayPtr+6,sideArrayPtr);
	}

	void BoggleCube::randomize()
	{
		std::random_shuffle(sideArrayPtr, sideArrayPtr + 6);
	}
}