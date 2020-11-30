/*
 *		Dana Solitaire
 *		Program 2
 *		CP2
 *		Uno Card classes that can be used to simulate Uno game
 *		Base Classes:		UnoCard			UnoSpecial		UnoDeck
 *		Derived Classes:	UnoNumCard		UnoWildCard		UnoSkipCard		UnoReverseCard
 *							UnoWildPick4	UnoPick2Card
 *
*/

#include "UnoReverseCard.hxx"			//Reverse Card
#include "UnoSkipCard.hxx"				//Skip Card
#include "UnoWildCard.hxx"				//Normal Wild Card
#include "UnoWildPick4Card.hxx"			//Pick 4 Wild Card
#include "UnoPick2Card.hxx"				//Pick 2 Card
#include "UnoDeck.hxx"					//Uno Deck
#include "UnoCard.hxx"					//Standard Uno Card

#include <iostream>						//Printing 

int main()
{
	//Creates and displays standard deck
	UnoDeck one;						
	one.display();
	//Shuffles cards and displays shuffled deck
	one.shuffle();
	one.display();
	//Discards top and bottom cards and displays after each function call
	one.discardTop();
	one.display();
	one.discardBottom();
	one.display();
	//Creating a UnoNumCard ptr to insert into deck
	UnoNumCard* insert = new UnoNumCard('R', 4);
	one.addToBottom(insert);
	one.display();
	UnoNumCard* insert2 = new UnoNumCard('G', 9);
	insert2->setColor('G');
	one.addToTop(insert2);
	one.display();
	//Displays the Uno Card at the bottom
	UnoCard& bottom = one.bottom();
	std::cout << "Bottom Card: " << bottom.getName() << std::endl;
	//Displays the Uno Card at given index
	UnoCard* cardHere = one.at(77);
	std::cout << "Card at 77 is: " << cardHere->getName() << std::endl;
	one.play(cardHere);
	one.isValidPlay(insert2);
	//Clears and resets the deck
	one.clear();
	one.reset();

	return 0;
}