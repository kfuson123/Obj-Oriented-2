#include "card3.hpp"

#include <iostream>

void
print(Card* c) {
   c->print();
}

void
print(const Deck& d) {
  for (Card* c : d) {
    // Dynamic dispatch. 
    print(c);
  }
}

int main() {

  Deck d {
    new Suited{Ace, Spades},
    new Suited{Two, Spades},
    // ... more cards
    new Joker{Black},
    new Joker{Red},
    new Uno{},
  };

  print(d);

  // d[0]->print();

  // random_shuffle(d.begin(), d.end());


  // FIXME: Delete cards.
}
