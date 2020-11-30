/*
Program Name: Project 2
Programmer Name: S. Miller
Attempt Number: 1
Purpose: overload of the insertion to output account in predictable fashion
Purpose for Update: n/a
Global Variable List: none!
*/


#ifndef PROJECT_SAVINGS_ACCOUNT_OUTPUT_H
#define PROJECT_SAVINGS_ACCOUNT_OUTPUT_H

#include <ostream>
#include <iomanip>

namespace DS {
	//Precondition: None
	//Postcondition: Output to stream, in the format of
	// day: DAYNUM, balance: $x.xx
	std::ostream &operator<<(std::ostream &, const account &);

	std::ostream &operator<<(std::ostream &os, const account &account) {
		os << "day: "
			<< account.getDayNumber()
			<< ", balance: $"
			<< std::fixed
			<< std::setprecision(2)
			<< account.getCurrentBalance();
		return os;
	}
}
#endif //PROJECT_SAVINGS_ACCOUNT_OUTPUT_H