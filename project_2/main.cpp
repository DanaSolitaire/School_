/*
Program Name: Project 2
Programmer Name: S. Miller
Attempt Number: 1
Purpose: Main tester of program
Purpose for Update: n/a
Global Variable List: none!
*/
#include <iostream>
#include <iomanip>
#include "account2.h"
#include "account2_output.h"
using namespace std;
using namespace DS;

int main() {

	cout << "Account Tester" << std::endl;

	//Create an account with 3.0% interest rate
	account savings(3.00);
	savings.deposit(1.00);
	cout << savings << endl;
	
	//Move up a week
	savings.advanceDay(7);
	cout << savings << endl;
	
	//Deposit $450.55
	savings.deposit(450.55);
	cout << savings << endl;

	//Move up 23 days, should see our first compound
	//However, the average balance not 451.55, since the balance was $1 for 7 of the 30 days
	savings.advanceDay(23);
	cout << savings << endl;

	//Advance a bunch with balance unchanged, two compoudings happen
	savings.advanceDay(65);
	cout << savings << endl;

	//Deposit more
	savings.deposit(1000);
	cout << savings << endl;

	//Advance a bunch with balance unchanged, at least two more interest calculations
	savings.advanceDay(65);
	cout << savings << endl;

	//Will not mutate object, amount must be > 0
	savings.deposit(-1000);
	cout << savings << endl;

	//Will not mutate object, amount must be > 0
	savings.withdraw(-1000);
	cout << savings << endl;

	//Will not mutate object, amount must < balance
	savings.withdraw(-10000);
	cout << savings << endl;

	//lower balance by 50
	savings.withdraw(50);
	cout << savings << endl;

	savings.advanceDay(30);
	cout << savings << endl;

	//Change interest rate to 2.5%
	//Only affects future compounding
	savings.setAPR(2.50);

	savings.advanceDay(30);
	cout << savings << endl;

	//Create an account with .01% interest rate
	account savings2(0.01);
	savings2.deposit(0.30);
	savings2.deposit(0.30);
	savings2.deposit(0.30);
	savings2.deposit(0.10);
	savings2.withdraw(1.00);
	//Should be EXACTLY ZERO
	cout << "Balance with overload (lies due to setprecision 2): " << savings2 << endl;
	cout << "Balance with (setprecision 25): " << setprecision(25) << savings2.getCurrentBalance() << endl;
	if (savings2.getCurrentBalance() != 0) {
		cout << "Rounding error seen, banks need to account for every penny!" << endl;
	}

	//Create an account with .01% interest rate
	account savings3(0.01);
	savings3.deposit(0.30);
	savings3.deposit(0.30);
	savings3.deposit(0.30);
	savings3.deposit(0.10);
	//Should be EXACTLY ONE DOLLAR
	cout << "Balance with overload (lies due to setprecision 2): " << savings3 << endl;
	cout << "Balance with (setprecision 25): " << setprecision(25) << savings3.getCurrentBalance() << endl;
	if (savings3.getCurrentBalance() != 1.00) {
		cout << "Rounding error seen, banks need to account for every penny!" << endl;
	}

	//Project 2 items
	//You may assume that the passed argument is a day number that already passed
	cout << "Balance at day 10 was: $" << savings.getPreviousBalance(10) << endl;
	cout << "Balance at day 20 was: $" << savings.getPreviousBalance(20) << endl;
	
	return 0;
}