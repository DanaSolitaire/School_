// FILE: lab01.cpp
// From Chapter 3 of Data Structures and Other Objects (Second Edition)
// ________________________________________________________________________
//
// This file has been modified to work with Microsoft Visual C++ 6.0,
// as described in www.cs.colorado.edu/~main/vc6.html
// ________________________________________________________________________
//
// CLASS IMPLEMENTED: baglab (see baglab.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used;
//   2. For an empty bag, we do not care what is stored in any of data; for a
//      non-empty bag the items in the bag are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.

// Programmer: Dana Solitaire
#include <cassert>  //For assert
#include <cstdlib>  //For rand
#include "bag1.h"
#include "baglab.h"

namespace DS {
	bag::value_type bag::grab_random()
	{
		//Remove a random item in the bag
		//used capacity
		size_t x;
		x = std::rand() % (CAPACITY - used + 1) + 1;
		if (erase_one(x) == true)
			erase(x);
		return value_type();
	}

	size_t emptyBag(DS::bag& nums, const DS::stats& bagStats) {
		//Implement assuming grab_random does NOT exist
		//Use stats struct to know the max and min
		//Use cstdlib's rand for random function
		size_t x, i;
		size_t count = 0;
		for (i = 0; i < nums.size(); ++i)
		{
			x = std::rand() % (bagStats.max - bagStats.min + 1) + 1;
			if (nums.erase_one(x) == true)
				nums.erase(x);
			++count;
		}
		return count;
	}

	size_t emptyBag(DS::bag& nums) {
		//Implement assuming member grab_random exist
		size_t i;
		size_t count = 0;
		for (i = 0; i < nums.size(); ++i)
		{
			nums.grab_random();
			++count;
		}
		return count;
	}

} //End of DS namespace

