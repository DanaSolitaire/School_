/*
Program Name: Project 1
Programmer Name: Dana Solitaire
Attempt Number: 1
Purpose: Recreate the account class
Purpose for Update: n/a
Global Variable List: none!
*/

#include "account.h"

DS::account::account(double inputInterestRate)
{
	//Sets the interest rate to the one given by user
	//Sets the value of account's amount to zero 
	//Sets the number of days to 1 instead of 0 because calendars start at 1
	interestRate = inputInterestRate / 12.00;
	amount = 0.0;
	numOfDays = 1;
}

DS::account::~account()
{}

void DS::account::deposit(double inputAmount)
{
	//Checks if inputAmount is positive if it is, it is added to account's existing amount
	if (inputAmount > 0)
		amount += inputAmount;
}

void DS::account::advanceDay(size_t inputNumOfDays)
{
	//Mod numOfDays by 30, if this equals one then numOfDays is the first day of the next month (ie 31 for 1st month)
	//This ensures that the interest will not be calculated everytime the function is called unless it is 1st of next month
	//To find the number of months, floor the divison value from numOfDays / 30. This value should be (month number).03
	//Calculate the interest and add the interest value to account's existing amount
	numOfDays += inputNumOfDays;
	//ensures that interest isn't calculated on day 1
	if (numOfDays > 30)
	{
		double months = numOfDays % 30;
		if (months == 1)
		{
			months = floor(numOfDays / 30);
			amount += amount / 2.00 * (pow(1 + (interestRate / 100), months) - 1);
		}
	}
}
	
void DS::account::withdraw(double inputAmount)
{		
	//If amount given is negative, the account's amount will not change
	//If amount is positive, the amount will be removed from the account's amount
	if (inputAmount > 0)
		amount -= inputAmount;
}
