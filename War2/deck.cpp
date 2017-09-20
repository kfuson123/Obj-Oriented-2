#include "deck.hpp"

#include <iostream>
#include <algorithm>
#include <random>

Deck make_standard_deck()
{
	Deck d 
	{
		{Ace, Spades},
		{Two, Spades},
		{Three, Spades},
		{Four, Spades},
		{Five, Spades},
		{Six, Spades},
		{Seven, Spades},
		{Eight, Spades},
		{Nine, Spades},
		{Ten, Spades},
		{Jack, Spades},
		{Queen, Spades},
		{King, Spades},
		{Ace, Hearts},
		{Two, Hearts},
	};
	return d;
}

// Deck deck = make_standard_deck();
Deck make_combined_deck(const Deck& d1, const Deck& d2)
{
	Deck d;
	d.insert(d.end(), d1.begin(), d1.end());
	d.insert(d1.end)
}

void shuffle(Deck& d)
{
	// Function local extern variable.
	extren std::minstd_rand prng;

	std::shuffle(d.begin(), d.end(), prng);
}

void print(const Deck& deck)
{
	// Range-base for loop.
  int i = 1;
  for (Card c : deck) 
  {
    std::cout << c << ' ';
    if (i % 13 == 0) 
    {
      std::cout << '\n';
      i = 0;
    }
    ++i;
  }
  std::cout << '\n';
}