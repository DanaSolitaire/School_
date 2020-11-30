#include "UnoDeck.hxx"

//Constructor uses reset function to create deck
UnoDeck::UnoDeck(int numOfDeck)
{
	reset();
}

UnoDeck::~UnoDeck()
{
}

//Calls the vector call rather than Uno Deck clear funtion to avoid recursion
void UnoDeck::clear()
{
	for (unsigned int i = 0; i < deck.size(); ++i)
	{
			delete deck[i];
			deck.vector::clear();
	}
}

//Creates deck 
void UnoDeck::reset(int numOfDecks)
{
	for (unsigned int i = 0; i < colors.size(); ++i)
	{
		UnoNumCard* zero = new UnoNumCard(colors.at(i), 0);
		deck.push_back(zero);

		for (unsigned int j = 1; j < 10; ++j)
		{
			UnoNumCard* temp = new UnoNumCard(colors.at(i), j);
			UnoNumCard* temp2 = new UnoNumCard(colors.at(i), j);
			deck.push_back(temp);
			deck.push_back(temp2);
		}
		UnoPick2Card* temp = new UnoPick2Card();
		temp->setColor(colors.at(i));
		UnoPick2Card* temp2 = new UnoPick2Card();
		temp2->setColor(colors.at(i));
		deck.push_back(temp);
		deck.push_back(temp2);

		UnoReverseCard* temp3 = new UnoReverseCard();
		temp3->setColor(colors.at(i));
		UnoReverseCard* temp4 = new UnoReverseCard();
		temp4->setColor(colors.at(i));
		deck.push_back(temp3);
		deck.push_back(temp4);

		UnoSkipCard* temp5 = new UnoSkipCard();
		temp5->setColor(colors.at(i));
		UnoSkipCard* temp6 = new UnoSkipCard();
		temp6->setColor(colors.at(i));
		deck.push_back(temp5);
		deck.push_back(temp6);
	}

	for (unsigned int i = 0; i < 4; ++i)
	{
		UnoWildCard* temp = new UnoWildCard();
		deck.push_back(temp);
		UnoWildPick4Card* temp2 = new UnoWildPick4Card();
		deck.push_back(temp2);
	}
}

//Creates a nullptr, sets it to given card ptr and inserts it into the top of the deck
void UnoDeck::addToTop(UnoCard* addCard)
{
	UnoCard* addCardPtr = nullptr;
	addCardPtr = addCard;
	deck.insert(deck.begin(), addCardPtr);	
}

//Creates a nullptr, sets it to given card ptr and inserts it into the top of the bottom
void UnoDeck::addToBottom(UnoCard* addCard)
{ 
	UnoCard* addCardPtr = nullptr;
	addCardPtr = addCard;
	deck.push_back(addCardPtr);
}

//Discards card by deleting memory that card ptr is pointing to and pops it off
void UnoDeck::discardTop()
{
	std::swap(deck.front(), deck.back());
	delete deck.back();				// not to orphan memory
	deck.pop_back();
}

//Discards card by deleting memory that card ptr is pointing to and pops it off
void UnoDeck::discardBottom()
{
	delete deck.back();				// not to orphan memory
	deck.pop_back();
}

//Uses algorithm shuffle and random generator
void UnoDeck::shuffle()
{
	std::shuffle(deck.begin(), deck.end(), std::default_random_engine());
}

//Returns card at given int index as a ptr
UnoCard* UnoDeck::at(int givenIndex) //pointer to uno card at index given 
{
	return deck[givenIndex];
}

//Returns card at the bottom of a deck as a reference
UnoCard& UnoDeck::bottom()
{
	UnoCard& card = *deck.back();
	return card;
}

//Default set to true
bool UnoDeck::isValidPlay(UnoCard* checkCard)
{
	return true;
}

//Displays Uno Cards in deck
void UnoDeck::display()
{
			for (unsigned int i = 0; i < deck.size(); ++i)
			{
				const std::string name = deck[i]->getName();

				if (name == "UnoNumCard")
				{
					std::cout << "|UnoCard: " << deck[i]->getColor() << " " << deck[i]->getName() << " "
						<< static_cast<UnoNumCard*>(deck[i])->getNumber() << "|" << std::endl;
				}

				if (name == "UnoPick2Card")
				{
					std::cout << "|UnoCard: " << deck[i]->getColor() << " " << deck[i]->getName() << "|" << std::endl;
				}

				if (name == "UnoSkipCard")
				{
					std::cout << "|UnoCard: " << deck[i]->getColor() << " " << deck[i]->getName() << "|" << std::endl;
				}

				if (name == "UnoReverseCard")
				{
					std::cout << "|UnoCard: " << deck[i]->getColor() << " " << deck[i]->getName() << "|" << std::endl;
				}

				if (name == "UnoWildCard" || name == "UnoWildPick4Card")
				{
					std::cout << "|UnoCard: " << deck[i]->getColor() << " " << deck[i]->getName() << "|" << std::endl;
				}
		}
	
	std::cout << "Num of cards: " << deck.size() << std::endl << std::endl << std::endl;
}

bool UnoDeck::play(UnoCard* givenCard)
{
	if (isValidPlay(givenCard) == true)
	{
		addToBottom(givenCard);
		return true;
	}
	else
		return false;
}
