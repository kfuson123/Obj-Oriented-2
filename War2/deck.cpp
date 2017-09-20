#include "deck.hpp"

Deck make_standard_deck()
{
	Deck d 
	{

	}
	return d;
}

Deck deck = make_standard_deck();

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