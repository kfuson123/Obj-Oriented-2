#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>

#include "card.hpp"

std::random_device rng;
std::minstd_rand prng;

void print_deck(const std::vector<Card>& deck)
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

bool card_greater(Card a, Card b) {
  return a > b;
}


// Deck of cards
// -which cards? suited cards(normal cards). Jokers??
// -how many cards? how many decks?
// -???

// Players
// -How many players? usually 2?
// -No strategy
// -Per player accquisiton strategy......
// -names?
// -hand (queue of cards)

// Game Option
// -deck specification/size
// -aces low or high
// -accquistion of cards (spoils)
//  -winner's first
// 	-loser's first
// 	-sorted
// 	-shuffled
// 	-interspersed per war
// -number of sacrifices (1, 3, ?)
// -negotiable sacrifice? (possibly 0)
// -incremental sacrifice?
// 	-global or local counter?

int main()
{
	prng.seed(rng());
	// Game deck
	Deck deck;
	deck.shuffle();

	Player p1;
	Player p2;

	// Splits the deck
	deal(deck, p1, deck.size()/2);
	deal(deck, p2, deck.size());

	// Round robin
	while(!deck.empty())
	{
		deal_one(deck, p1);
		deal_one(deck, p2);
	}

	// Very object oriented
	// Creates an artificial dependency from deck to player and limit reusability
	// deck.deal(deck, p1, deck.size()/2);
	// deck.deal(deck, p2, deck.size());

	Pile spoils;
	
	while(true)
	{

		if(p1.empty())
		{
			if(p2.empty())
				std::cout << "TIE\n";
			
			else
				std::cout << "P2 WINS\n";
			break;
		}
		else if(p2.empty())
		{
			std::cout << "P1 WINS\n";
			break;
		}


		Card c1 = p1.take(); 
		Card c2 = p2.take();

		spoils.add(c1);
		spoils.add(c2);

		if(c1 > c2)
		{
			give(p1, spoils);
		}
		else if (c2 > c1)
		{
			give(p2, spoils);
		}
		else
		{
			// WAR
			spoils.add(p1.take());
			spoils.add(p2.take());
			continue;
		}
		assert(spoils.empty());
	}





	std::vector<Card> deck;
    deck.reserve5(52);
    for (int s = Hearts; s<= Spades; ++s){
        for (int r = Ace; r<= King; ++r){
            Card c{static_cast<Rank>(r), static_cast<Suit>(s)};
            deck.push_back(c);
            //Creates a card.
        }
    }
     print_deck(deck);


    std::shuffle(deck.begin(), deck.end(), prng);
      print_deck(deck);



    std::sort(deck.begin(), deck.end());

    // Rank r1 = Two;
    // Rank r2 = Ace;
    // std::cout << (r1 == r2) << "\n";
    // std::cout << (r1 < r2) << "\n";

    // // Widening conversion. This is oka.
    // int n = Jack;
    // std::cout << n << "\n";

    // // Narrowing conversion. Loses information. This instance it doesn't work as it cannot convert.
    // //Rank r3 = 4;// error cannot convert.
    // //Initialized some cards
    // Card c1{Ace, Spades};
    // Card c2{Four, Hearts};

    // //Declaration, invokes a constuctor to initialize an object (c3)
    // Card c3 = c1;
    // //Assignment(expression)
    // c3 = c2;

    // We should be able to do this.
    // Card c;
    // Create a deck of cards.
}
