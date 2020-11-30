
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS and srand
#include <ctime>	   // assist to seed to pseudo random generator
#include "bag1.h"      // With value_type defined as an int
#include "baglab.h"

using namespace std;
using namespace DS;

int main(int argc, char const *argv[])
{
	srand(time(0));
    bag nums;
    stats bagStats;

    bagStats = cStrArray2Bag(nums, &argv[1], static_cast<size_t>(argc-1));

    cout << endl;

	cout << "All " << argc-1 << " items removed in " << emptyBag(nums, bagStats) << " tries." << endl;

	//Load the bag again
	cStrArray2Bag(nums, &argv[1], static_cast<size_t>(argc-1));
	cout << "All " << argc-1 << " items removed in " << emptyBag(nums) << " tries." << endl;

	return EXIT_SUCCESS;
}

namespace DS {
stats cStrArray2Bag(bag& b, const char* values[], size_t size) {
	stats retVal;
	int num;
	retVal.min = retVal.max = atoi(values[0]);
	b.insert( retVal.min );
	for (size_t argi=1 ; argi < size ; ++argi ) {
		num = atoi(values[argi]);
		b.insert( num );
		if ( num < retVal.min )
			retVal.min = num;
		else if ( num > retVal.max )
			retVal.max = num;
	}
	return retVal;
}
}
