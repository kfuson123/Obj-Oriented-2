<<<<<<< HEAD
#include "card.hpp"
#include <cassert>
#include <vector>
#include <queue>
#include <iostream>

using Deck = std::vector<Card>;
using Hand = std::queue<Card>;

void deal_one(Deck &d, Hand &h)
{
	if (d.empty())
		throw std::logic_error("empty deck");
	assert(!d.empty())
	Card c = d.back();
	d.pop_back();
	h.push(c);
}

void print(const Deck& deck)
{
  // Range-base for loop.
  int i = 1;
  for (Card c : deck) {
    std::cout << c << ' ';
    if (i % 13 == 0) {
      std::cout << '\n';
      i = 0;
    }
    ++i;
  }
  std::cout << '\n';
}

int main()
{
  Deck d;
  Hand h;
  deal_one(d, h);
  
}

=======
>>>>>>> 79d66c9120d0ea908eba52c82e3cb01d4b73652a

