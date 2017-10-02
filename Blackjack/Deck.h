#pragma once

#include "Card.h"
#include <vector>

using Deck = std::vector<Card>;


void print_deck(Deck);

void shuffle(Deck&);