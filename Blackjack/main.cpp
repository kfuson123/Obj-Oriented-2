// Kyle Fuson
// All rights reserved
#include "card.hpp"
#include "deck.hpp"
#include "game.hpp"

#include <iostream>
#include <iomanip>
#include <vector>

#include <random>

std::random_device rng;
std::minstd_rand prng;

int main()
{
  prng.seed(rng());


  Deck d1 = make_standard_deck();
  
  return 0;
}
