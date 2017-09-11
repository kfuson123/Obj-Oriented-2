// Kyle Fuson
// All rights reserved

// Ranks of a card:
// ace, 2-10, jack, king, and queen.

// Suits of a card are:
// hearts, diamonds, clubs, spades

#include "card.hpp"
#inlcude <iostream>

std::ostream& operator<<(std::ostream& os, Rank r)
{
    switch(r){
        case Ace:
            os << "A";
            break;
    }
    return os;
}
