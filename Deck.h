#pragma once

class Card;

enum Suit
{
	Hearts = 1,
	Clubs,
	Diamonds,
	Spades
};

enum Value
{
	Nine = 9,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};

class Card
{
	public:
		Card() {}

	Suit suit;
	Value value;
	//Player player;
};

struct Deck
{
	Card cards[24];
	int position;

	Deck();
	void Shuffle();
	Card Deal();
};

#include "Player.h"