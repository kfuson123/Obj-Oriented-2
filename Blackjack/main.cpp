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

void Split(Deck& deck, Hand& player, Hand& split_hand)
{
  Card c;
  player.pop_back(c);
  split_hand.push_back(c);
  deal_one(deck, player);
  deal_one(deck, spilt_hand);
}



int main()
{
  int option;
  bool stand;
  prng.seed(rng());
  Deck deck;
  Hand player;
  Hand dealer;
  Hand splitHand;

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
        stand = false;
        break;
      case '1':
        deal_one(deck, player);
        break;
      case '2':
        DD();
        break;
      case '3':
        Split(deck, player, splitHand);
        break;
      case '4':
        stand = true;
        break;
    }
  }
  else
  {
    switch(option)
    {
      default:
        stand = false;
        break;
      case '1':
        deal_one(deck, player);
        break;
      case '2':
        DD();
        break;
      case '3':
        stand = true;
        break;
    }
  }

  
  return 0;
}
