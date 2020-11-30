/*
 *		Name:		Dana Solitaire
 *		Date:		Sept. 9th, 2019
 *		Professor:	Sciabbarrasi
 *		Project:	Lab 1
 *		Purpose:    Creates and displays a shuffled and unshuffled 
 *					deck of cards
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

void displayDeck(const std::string DECK[], const unsigned SIZE);
void shuffleDeck(const std::string DECK[], const unsigned SIZE);
void populateDECK(std::string deck[], const unsigned SIZE, const std::string& FACE = "23456789TJQKA",
				const std::string& SUIT ="CDHS")
int main(void) {
	const unsigned SIZE = 52;
	const std::string DECK[SIZE];
	const std::string SUIT = "CDHS";

	displayDeck(DECK, SIZE);
}
displayDeck(const std::string DECK[], const unsigned SIZE)
{
	std::cout << setw(52) << "tr" << endl;
}
shuffleDeck(std::string DECK[], const unsigned SIZE)
{
}
populateDECK(std::string deck[], const unsigned SIZE, const string& FACE, const string& SUIT)
{
	if (SUIT.length() != 0 or FACE.length() != 0)
	{
		int n = 0;			     //index in DECK array
		while (n <= 52)			 //
		{
			for (int i; i <= SUIT.length(); i++)
			{
				for (int j; j <= FACE.length(); j++)
				{
					deck[n] = FACE[j];
					deck[n] += SUIT[i];
					n++;
				}
			}
		}
	}
}