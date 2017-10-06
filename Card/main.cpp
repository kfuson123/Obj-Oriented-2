#include "card.hpp"

#include <cassert>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>

using Deck = std::vector<Card>;

using Hand = std::queue<Card>;

void print(const Deck& deck)
{
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


// Deal one card from the top of d to the 
// front of the hand h. 
//
// Contract: The deck d shall not be empty.
//
// Precondition: !d.empty() <=> d.size() != 0

// If the deck is empty, throws a logic error.

// Returns true on success, false on failure.
void deal_one(Deck& d, Hand& h)
{
  assert(!d.empty());

  // if (d.empty())
  //   throw std::logic_error("empty deck");

  // DO NOT DO THIS. Fails silently.
  // if (d.empty())
  //   return false;

  Card c = d.back();
  d.pop_back();
  h.push(c);
  // return true;
}



int main()
{
  Deck d;
  Hand h;

  deal_one(d, h);
  assert(h.size() == 1);

  // Called out of contract
  if (!deal_one(d, h)) {
    // What happens if you can't deal?
  }
}
