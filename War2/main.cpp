// Kyle Fuson
// All rights reserved
#include "card.hpp"
#include "deck.hpp"

#include <iostream>
#include <iomanip>
#include <vector>

#include <random>

std::random_device rng;
std::minstd_rand prng;


// Deck of cards
// - which cards? suited (standard?) cards. jokers?
// - how many cards? how many decks?
// - ???

// Players
// - How many players? usually 2.
// - No strategy
// - per-player acquisition strategy...
// - names?
// - hand (stack/queue of cards)

// Spoils pile
// - determines how cards are picked up?

// Game options
// - deck specification/size
// - aces low or high
// - acquisition rules (spoils)
//   - winner's first
//   - loser's first
//   - sorted (ascending/descending)
//   - shuffled
//   - partially shuffled (per war)
//   - interspersed per war
// - number of sacrifices (1, 3, more?)
// - negotiable sacrifice (possibly 0)
// - incremental sacrifice
//    - global or local counter?

int main()
{
  prng.seed(rng());


  Deck d1 = make_standard_deck();
  Deck d2 = make_standard_deck();
  Deck d3 = make_combined_deck(d1, d2);

  print(d3);
  shuffle(d3);
  print(d3);

  // constexpr int runs = 10'000;
  // int total = 0;
  // for (int i = 0; i < runs; ++i) {
  //   Game g;
  //   total += g.play();
  // }
  // std::cout << double(total) / double(runs) << '\n';

#if 0






  // Game deck (not sure which or how many cards).
  // Contains 2*n cards.
  Deck deck;
  deck.shuffle();

  Player p1;
  Player p2;

  // Split the deck.
  deal(deck, p1, deck.size() / 2);
  deal(deck, p2, deck.size());

  // Round-robin dealing.
  while (!deck.empty()) {
    deal_one(deck, p1);
    deal_one(deck, p2);
  }

  // Interesting alternative syntax.
  deal(deck, {p1, p2});

  // Very object-oriented.
  //
  // Creates an artificial dependency from Deck to Player.
  // Inhibit reusability of the Deck class.
  // deck.deal(p1, deck.size() / 2);
  // deck.deal(p2, deck.size());

  // The spoils pile.
  Pile spoils;

  while (true) {
    if (p1.empty()) {
      if (p2.empty())
        std::cout << "TIE\n";
      else
        std::cout << "P2 WINS\n";
      break;
    }
    else if (p2.empty()) {
      std::cout << "P1 WINS\n";
      break;
    }

    Card c1 = p1.take();
    Card c2 = p2.take();

    spoils.add(c1);
    spoils.add(c2);

    if (c1 > c2) {
      give(p1, spoils);
    }
    else if (c2 > c1) {
      give(p2, spoils);
    }
    else {
      // TODO: Need to check number of cards.
      // TODO: Number of sacrifices...
      // TODO: Negotiate sacrifices...

      // WAR!
      spoils.add(p1.take());
      spoils.add(p2.take());
      continue;      
    }
    assert(spoils.empty());
  }
#endif
  return 0;
}
