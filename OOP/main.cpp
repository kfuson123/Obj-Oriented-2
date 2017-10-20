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

// Effects: 

// Postcondition: deck.size() == original(deck).size() - 1
void deal_one(Deck& d, Hand& h)
{
  assert(!d.empty());
  Deck d0 = d;
  Hand h0 = h;

  // if (d.empty())
  //   throw std::logic_error("empty deck");

  // DO NOT DO THIS. Fails silently.
  // if (d.empty())
  //   return false;

  Card c = d.back();
  d.pop_back();
  h.push(c);
  assert(d.size() == d0.size() - 1);
  assert(std::equal(d.begin(), d.end(), d0.begin()));
  assert(h.size() == h0.size() + 1);
  assert(std::equal(h0.begin(), h0.end(), h.begin()));
  assert(h.back() == d0.back());
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
