#pragma once

#include <iostream>

enum Rank {
	Two = 0,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace,
};

enum Suit {
	Heart = 0,
	Diamond,
	Spade,
	Club,
};

struct Card
{
	Rank rank;
	Suit suit;
	

	std::ostream& operator <<(std::ostream&);

	Card(Rank, Suit);
	void print_card();
	bool greater_rank(const Card&);

	bool operator==(const Card&) const;
	bool operator!=(const Card&) const;

	int Blackjack_Value();

};

