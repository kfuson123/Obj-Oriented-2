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
  int option;
  prng.seed(rng());
  Deck deck;
  Hand player;
  Hand dealer;

  Deck d1 = make_standard_deck();
  shuffle(deck);

  deal_one(deck, player);
  deal_one(deck, dealer);
  deal_one(deck, player);

  std::cout << "Dealer's Hand: " << print(dealer) << std::endl;
  std::cout << "Your hand: " << print(player) << std::endl;

  std::cout << "What would you like do to?" << std::endl;
  cin >> option;
  if(player[0] == player[1])
  {
    switch(option)
    {
      default:
        break;
      case '1':
        deal_one(deck, player);
        break;
      case '2':
        DD();
        break;
      case '3':
        Spilt();
        break;
      case '4':
        Stand();
        break;
    }
  }
  else
  {
    switch(option)
    {
      default:
        break;
      case '1':
        deal_one(deck, player);
        break;
      case '2':
        DD();
        break;
      case '3':
        Stand();
        break;
    }
  }

  
  return 0;
}
