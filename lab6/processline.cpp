
#include <iostream>
#include <cmath>
#include <limits>
#include <cstring>
#include <cctype>
#include "mystack.h"

using namespace DS;
double process_line(std::istream& ins)
{
	DS::mystack<double> numbers;
	DS::mystack<char> operations;
	char spaceChar = ' ';
	
	while (ins)
	{
		if (isspace(ins.peek()))
			ins.ignore();
		else if (isdigit(ins.peek()))
		{
			numbers.push(ins.get());
		}
		else if (ins.peek() == '*')
		{
			operations.push(ins.get());
		}
		else if (ins.peek() == '-')
		{
			operations.push(ins.get());
		}
		else if (ins.peek() == '+')
		{
			operations.push(ins.get());
		}
		else if (ins.peek() == '/')
		{
			operations.push(ins.get());
		}
	}
	double firstNum, secondNum, temp;
	char operation;
	while (operations.size() != 0)
	{	

		secondNum = numbers.top();
		numbers.pop();				//Removes thing from top == void
		operation = operations.top();
		operations.pop();
		firstNum = numbers.top();
		numbers.pop();

		switch (operation)
		{
		case '*':	temp = firstNum * secondNum;
					numbers.push(temp);
					break;
		
		case '/':	if (secondNum == 0)
						return std::nan("Invaild");
					temp = firstNum / secondNum;
					numbers.push(temp);
					break;
		
		case '-':	temp = firstNum - secondNum;
					numbers.push(temp);
					break;
		case '+':	temp = firstNum + secondNum;
					numbers.push(temp);
					break; 
		}
	}
	return numbers.top();
}