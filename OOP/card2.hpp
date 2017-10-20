#include <utility>

#include <iosfwd>

enum Rank // An enumeration type
{
  Ace, // An enumerator
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
// A playing card (in a standard deck) is a pair of rank and
// suit (see enums above).
struct Card
{
};

struct Suited : Card
{
  Suited(Rank r) : r(r) {}
  Rank r;
  // Suit s;
};


struct Spades : Suited
{
  using Suited::Suited;
};

struct Clubs : Suited
{

};

struct Hearts : Suited
{

};

struct Diamonds : Suited
{

};

struct Joker : Card
{
  Joker(Color c) : c(c) { }
  Color c;

};


