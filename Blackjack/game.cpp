#include "game.hpp"

void Split(Deck& deck, Hand& player, Hand& split_hand)
{
  Card c;
  player.pop_back(c);
  split_hand.push_back(c);
  deal_one(deck, player);
  deal_one(deck, spilt_hand);
}
