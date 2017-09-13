// Kyle Fuson
// All rights reserved

// Ranks of a card:
// ace, 2-10, jack, king, and queen.

// Suits of a card are:
// hearts, diamonds, clubs, spades

#include <iostream>

std::ostream&
operator<<(std::ostream& os, Rank r)
{
    switch (r) {
        case Ace:
            os << 'A';
            break;
        case Two:
            os << '2';
            break;
        case Three:
            os << '3';
            break;
        case Four:
            os << '4';
            break;
        case Five:
            os << '5';
            break;
        case Six:
            os << '6';
            break;
        case Seven:
            os << '7';
            break;
        case Eight:
            os << '8';
            break;
        case Nine:
            os << '9';
            break;
        case Ten:
            os << 'T';
            break;
        case Jack:
            os << 'J';
            break;
        case Queen:
            os << 'Q';
            break;
        case King:
            os << 'K';
            break;
    }
    return os;
}

std::ostream&
operator<<(std::ostream& os, Suit s)
{
    switch (s) {
        case Hearts:
            os << 'H';
            break;
        case Diamonds:
            os << 'D';
            break;
        case Clubs:
            os << 'C';
            break;
        case Spades:
            os << 'S';
            break;
    }
    return os;
}

std::ostream& 
operator<<(std::ostream& os, Card c)
{
    return os << c.get_rank() << c.get_suit();
}
