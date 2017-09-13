// Kyle Fuson
// All rights reserved

// Ranks of a card:
// ace, 2-10, jack, king, and queen.

// Suits of a card are:
// hearts, diamonds, clubs, spades

#include <iostream>
#include "card.hpp"
bool operator==(Card a, Card b)
{
	return a.get_rank() == b.get_rank() && a.get_suit() == b.get_suit();
}

bool operator!=(Card a, Card b)
{
	return !(a == b);
}

std::ostream& operator<<(std::ostream& os, Rank r)
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

std::ostream& operator<<(std::ostream& os, Suit s)
{
    switch (s) {
        case Hearts:
           // os << 'H';
        	os << '\u2665';
            break;
        case Diamonds:
            os << '\u2666';
            break;
        case Clubs:
            os << '\u2663';
            break;
        case Spades:
            os << '\u2660';
            break;
    }
    return os;
}

// int card_value(Card c)
// {
// 	return (c.get_suit() << 4) | c.get_rank();
// }

// constexpr int card_value(Suit s, Rank r)
// {
// 	return (s << 4) | r;
// }

// const char* card_face(Card c)
// {
// 	switch (card_value(c)){
// 		case card_value(Spades, Ace): return '\U0001f0a1';
// 	}
// }

std::ostream&  operator<<(std::ostream& os, Card c)
{
	// return os << card.face(c);
    return os << c.get_rank() << c.get_suit();

}
