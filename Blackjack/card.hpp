
#pragma once

#include <utility>

#include <iosfwd>

enum Rank
{
  Ace,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
};

enum Suit
{
  Hearts,
  Diamonds,
  Clubs,
  Spades,
};

/// Represents the values of (suited) cards.
class Card
{
public:
  Card() = default;

  Card(Rank r, Suit s)
    : rank(r), suit(s) // member initializer list
  { }

  // Returns the rank of the card.
  Rank get_rank() const { return rank; }

  // Returns the suit of the card.
  Suit get_suit() const { return suit; }

private:
  Rank rank;
  Suit suit;
};

// Equality comparison
bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

// Ordering
bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);

std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Suit s);

