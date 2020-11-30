#ifndef UNODECK
#define UNODECK

#include <algorithm>			//shuffle function 
#include <vector>				//container for card pointers
#include <iostream>				//used in void display() 		
#include <random>				//used for shuffle random seed
#include "UnoNumCard.hxx"
#include "UnoCard.hxx"
#include "UnoReverseCard.hxx"
#include "UnoSkipCard.hxx"
#include "UnoWildCard.hxx"
#include "UnoWildPick4Card.hxx"
#include "UnoPick2Card.hxx"


class UnoDeck
{
public:
	UnoDeck(int NUMOFDECKS = 1);
	~UnoDeck();
	void clear(); // while loop to derefence each pointer
	void reset(int NUMOFDECKS = 1); //
	void addToTop(UnoCard*); //
	void addToBottom(UnoCard*); //
	void discardTop();
	void discardBottom();
	bool play(UnoCard*);
	void shuffle();
	UnoCard* at(int givenIndex);
	UnoCard& bottom();
	bool isValidPlay(UnoCard*);
	void display();

private:
	int numOfDeck;
	std::vector<UnoCard*> deck;
	std::vector<char> colors = { 'R', 'Y', 'B','G' };

};

#endif
