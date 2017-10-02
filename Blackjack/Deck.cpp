#include "Deck.h"
#include "Card.h"

#include <random>
#include <algorithm>
#include <chrono>

void print_deck(Deck d)
{
	for (auto c : d)
	{
		c.print_card();
		std::cout << std::endl;
	}
}

void shuffle(Deck& d)
{
	unsigned int seed = static_cast<int>(time(0));
	std::shuffle(d.begin(), d.end(), std::default_random_engine(seed));
}