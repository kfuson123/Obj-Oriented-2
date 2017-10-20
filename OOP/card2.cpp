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
};

0b0000'0000
// A playing card (in a standard deck) is a pair of rank and
// suit (see enums above). The representation of a card is:
// 0b00ss'rrrr
// Joker representation:
// 0b1000'000c

struct Card
{
  unsigned char bits;

  Card(Rank r, Suit s)
    : bits((s << 4) | r)
  { }

  Card (Color c)
    :bits(0x80 | c)
  { }

  bool is_joker() const{
    return bits & 0x80;
  }

  bool is_suited() const{
    return !is_joker();
  }

  Rank get_rank() const{
    assert(is_suited());
    return bits & 0x0f;
  }

  Suit get_suit() const{
    assert(is_suited());
    return (Suit)(bits >> 4);
  }

  Color get_color() const{
    if(is_joker())
      return (Color)(bits & 0x01);
    else
      return (Color)(get_suit() >= Hearts);
  }

  void set(Rank r, Suit s)
  {
    *this = Card(r, s);
  }

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
