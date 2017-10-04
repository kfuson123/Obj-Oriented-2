<<<<<<< HEAD
ma once

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

enum Color
{
  Black,
  Red,
};

/// Represents the values of (suited) cards.
struct SuitedCard
{
  Rank rank;
  Suit suit;
};

struct JokerCard
{
  Color color;
};


// This is a union type.
union CardImpl
{
  SuitedCard sc;
  JokerCard jc;
};

enum CardKind {
  Suited,
  Joker
};


// Discriminated union.
struct Card
{
  CardKind kind; // discriminator 
  CardImpl impl;
};



#if 0
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
#endif
=======

>>>>>>> 79d66c9120d0ea908eba52c82e3cb01d4b73652a
