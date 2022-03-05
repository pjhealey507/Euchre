#include "Deck.h"
#include <iostream>
#include <vector>
#include <algorithm>

Deck::Deck()
{
	int location = 0;
	for(int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			//Credit riptutorial for static_cast
			cards[location].suit = static_cast<Suit>(i);
			cards[location].value = static_cast<Value>(j);
			location++;
		}
	}

	Shuffle();
}

void Deck::Shuffle()
{
	std::random_shuffle(cards[0], cards[24]);
}


