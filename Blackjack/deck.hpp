#include "card.hpp"
#include "game.hpp"
#include <vector>

// Pragmatic approach.
// Don't write a class if you don't have to.
using Deck = std::vector<Card>;
using Hand = std::vector<Card>;
Deck make_standard_deck();

Deck make_combined_deck(const Deck& d1, const Deck& d2);

void shuffle(Deck& d);

template<class T>
void print(T& d);

// Very object oriented.
// struct Deck
// {
// 	Deck() { ... };

// 	void shuffle();

// 	std::vector<Card> cards;
// };
