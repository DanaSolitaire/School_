/*
Program Name: Project 1
Programmer Name: Dana Solitaire
Attempt Number: 1
Purpose: Recreate the account class
Purpose for Update: n/a
Global Variable List: none!
*/

#ifndef ACCOUNT_CLASS_H
#define ACCOUNT_CLASS_H

#include "math.h"		// floor() and pow() functions

namespace DS
{
	class account
	{
	public:

		//account's amount, interestRate, and numOfDays get initialized 
		account(double interestRate);
		~account();

		//Precondition: 
		//user given amount as a double
		//Postcondition: 
		//if user given amount is valid, the account's existing amount is updated
		void deposit(double amount);

		//Precondition: 
		//size_t number of days user wants to advance account by
		//Postcondition:  
		//numOfDays of account is advanced and amount is increased if needed
		void advanceDay(size_t numOfDays);

		//Precondition: 
		//double given amount to withdraw
		//Postcondition: 
		//amount is updated
		void withdraw(double amount);

		//Precondition: 
		//None
		//Postcondition: 
		//account's existing amount is returned as a double
		const double getBalance() const { return amount; }

		//Precondition: 
		//None
		//Postcondition: 
		//account's existing number of days is returned as a size_t
		const size_t getDayNumber() const { return numOfDays; }

	private:
		//Double variable type is needed to ensure values are stored like money is ($00.00)
		//and interest rate as (0.00%) for the advanceDay function
		//numOfDays is size_t to accommodate for large number of days (ie an old account)
		double amount, interestRate;
		size_t numOfDays;

	};
}
#endif;
