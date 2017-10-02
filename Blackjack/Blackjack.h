#pragma once

#include "Card.h"
#include "Deck.h"

struct Blackjack {
	int Number_of_Decks;
	int Number_of_Cards;
	Deck d;

	// constructors
	Blackjack();

	// functions
	int evaluate_hand(Deck); // checks score of given Hand
	void print_hand(Deck); // prints cards in a hand
	void run_game(); // what it says it does
};

void print_winner(int, int);
