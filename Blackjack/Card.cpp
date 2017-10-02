#include "Card.h"
#include <iostream>


Card::Card(Rank r, Suit s)
	:rank(r), suit(s)
{ }

void Card::print_card()
{
	switch (rank)
	{
	case 0:
		std::cout << "Two";
		break;
	case 1:
		std::cout << "Three";
		break;
	case 2:
		std::cout << "Four";
		break;
	case 3:
		std::cout << "Five";
		break;
	case 4:
		std::cout << "Six";
		break;
	case 5:
		std::cout << "Seven";
		break;
	case 6:
		std::cout << "Eight";
		break;
	case 7:
		std::cout << "Nine";
		break;
	case 8:
		std::cout << "Ten";
		break;
	case 9:
		std::cout << "Jack";
		break;
	case 10:
		std::cout << "Queen";
		break;
	case 11:
		std::cout << "King";
		break;
	case 12:
		std::cout << "Ace";
		break;
	default:
		break;
	}
	std::cout << " of ";
	switch (suit)
	{
	case 0:
		std::cout << "Hearts";
		break;
	case 1:
		std::cout << "Diamonds";
		break;
	case 2:
		std::cout << "Spades";
		break;
	case 3:
		std::cout << "Clubs";
		break;
	default:
		break;
	}
}

bool Card::greater_rank(const Card& c)
{
	if (suit > c.suit)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Card::operator==(const Card& c2) const
{
	return (rank == c2.rank && suit == c2.suit);
}

bool Card::operator!=(const Card& c2) const
{
	return (rank != c2.rank || suit != c2.suit);
}

int Card::Blackjack_Value() // consider: passing an argument
{
	switch (rank)
	{
	case Ace:
	{
		return 1;
		break;
	}
	case Two:
	{
		return 2;
		break;
	}
	case Three:
	{
		return 3;
		break;
	}
	case Four:
	{
		return 4;
		break;
	}
	case Five:
	{
		return 5;
		break;
	}
	case Six:
	{
		return 6;
		break;
	}
	case Seven:
	{
		return 7;
		break;
	}
	case Eight:
	{
		return 8;
		break;
	}
	case Nine:
	{
		return 9;
		break;
	}
	default:
	{
		return 10;
		break;
	}
	}
}