/*
Program Name: Project 2
Programmer Name: Dana Solitaire
Attempt Number: 1
Purpose: Recreate the account class using dynamic arrays
Purpose for Update: n/a
Global Variable List: none!
*/

#include "account2.h"

DS::account::account(double inputInterestRate)
{
	//Sets the interest rate to the one given by user
	//Sets the value of account's amount to zero 
	//Sets the number of days to 1 instead of 0 because calendars start at 1
	interestRate = inputInterestRate;
	amount = 0.0;
	numOfDays = 1;
	//creates a 1 size array to hold inital amount given
	dailyBalanceptr = new double[1];
}

DS::account::~account()
{
	delete[] dailyBalanceptr;
}

void DS::account::deposit(double inputAmount)
{
	//Checks if inputAmount is positive if it is, it is added to account's existing amount
	if (inputAmount > 0)
		amount += inputAmount;

	//Checks if it is the first day of the account, if so the amount at index 0 is only updated
	if (numOfDays == 1)
	{
		dailyBalanceptr[0] = amount;
	}
	//adds new amount to last element which is the daily balance for the current day
	else
		dailyBalanceptr[-1] = amount;
}

void DS::account::advanceDay(size_t inputNumOfDays)
{
	//Mod numOfDays by 30, if this equals one then numOfDays is the first day of the next month (ie 31 for 1st month)
	//This ensures that the interest will not be calculated everytime the function is called unless it is 1st of next month
	//To find the number of months, floor the divison value from numOfDays / 30. This value should be (month number).03
	//Calculate the interest and add the interest value to account's existing amount.
	//This amount is added to the end of the array ie. day 31 or index 30
	//If interest isn't calculated, the new larger array will repeat the same value for the other days
	
	//create a temp ptr that points to new larger array
	double *temp = new double[numOfDays + inputNumOfDays];
	std::copy(dailyBalanceptr, dailyBalanceptr + inputNumOfDays, temp);
	//dailyBalanceptr is updated to now point a new larger array
	dailyBalanceptr = temp;
	size_t i = 0;
	for (i = numOfDays; i < numOfDays + inputNumOfDays; ++i)
	{
		//Inserts lastest static amount for the remaining days
		temp[i] = amount;
	}
	numOfDays += inputNumOfDays;
	double months = numOfDays % 30;

	//Ensures that interest isn't calculated on day 1
	if (numOfDays > 30)
	{ 
		if (months == 1)
		{
			months = floor(numOfDays / 30);
			amount += amount / 2.00 * (pow(1 + (interestRate / 100), months) - 1);
			dailyBalanceptr[-1] = amount;
		}
	}
}

void DS::account::withdraw(double inputAmount)
{
	//If amount given is negative, the account's amount will not change
	//If amount is positive, the amount will be removed from the account's amount
	if (inputAmount > 0)
		amount -= inputAmount;
	//if it is day 1, the first index has amount updated
	if (numOfDays == 1)
		dailyBalanceptr[0] = amount;
	//else last element, which should be the current day, amount is updated 
	else
		dailyBalanceptr[-1] = amount;
}

//Updates interest rate
const void DS::account::setAPR(double givenInterestRate)
{
	interestRate = givenInterestRate;
}

//Returns the current balance which should be the last element in array
const double DS::account::getCurrentBalance() const
{
	//Checks if it is day one, if so it will return index 0 value
	if (numOfDays == 1)
		return dailyBalanceptr[0];
	else
		return dailyBalanceptr[numOfDays-1];
}

//Returns balance on given day
const double DS::account::getPreviousBalance(size_t inputDay) const
{
	if (inputDay <= numOfDays)
		return dailyBalanceptr[inputDay - 1];
	else
		return 0.00;
}