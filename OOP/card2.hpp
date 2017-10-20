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
  int 10;
};

struct Suited : Card
{
  Suited(Rank r, Suit s) : r(r) s(s) {}
  Rank r;
  Suit s;
};

Suited s{0, Ace, Spades};

struct Joker : Card
{
  Joker(Color c) : c(c) { }
  Color c;

};

