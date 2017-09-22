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
}

// Represents the values of (suited) cards.
struct SuitedCard
{
  Rank rank;
  Suit suit;
};

struct JokerCard
{
  Color color;
};

// This is the union
union CardImpl
{
  SuitedCard sc;
  JokerCard jc;
};

// CardImpl c; // Default constructs c
// c.sc = {Nine, Spades}; // sc is the active member of the union

// SuitedCard sc = c.sc; // OK: reads the active member

// JokerCard jc = c.sc; // Error: Reads an inactive member.

// Discriminated union
struct Card
{
    bool suited; // Discriminator
    CardImpl impl;
};

// // Equality comparison
// bool operator==(Card a, Card b);
// bool operator!=(Card a, Card b);

// // Ordering
// bool operator<(Card a, Card b);
// bool operator>(Card a, Card b);
// bool operator<=(Card a, Card b);
// bool operator>=(Card a, Card b);

// std::ostream& operator<<(std::ostream& os, Card c);
// std::ostream& operator<<(std::ostream& os, Rank r);
// std::ostream& operator<<(std::ostream& os, Suit s);
