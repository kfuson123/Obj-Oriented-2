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

int score(Hand & hand)
{
  int sum = 0;
  Card c;
  Hand tmp_hand;

  while(!hand.empty())
  {
      hand.pop(c);
      c += c;
  }
}

int main()
{
  int option;
  bool stand = false;
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

  while(stand)
  {
  std::cout << "Dealer's Hand: " << print(dealer) << std::endl;
  std::cout << "Your hand: " << print(player) <<  << "Your total: " << sum(player) << std::endl;

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
        sum();
        break;
      case '2':
        DD();
        break;
      case '3':
        stand = true;
        break;
    }
  }
  }

  while(dealerSum)

  
  return 0;
}
