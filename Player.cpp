#include "Player.h"
#include <vector>
#include <algorithm>

class Player
{
	Card hand[5];

	Card PlayCard(Suit trump, Suit suit)
	{
		std::vector<Card> suited;

		for (int i = 0; i < sizeof(hand); i++)
		{
			if (hand[i].suit == suit)
			{
				suited.push_back(hand[i]);
			}
		}

		return std::max_element(suited[0], suited[suited.size()]);
	}
};