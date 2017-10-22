#pragma once

#include <cassert>
#include <iosfwd>
#include <vector>

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
  King
};

enum Suit
{
 Spades,
 Clubs,
 Hearts,
 Diamonds,
};

enum Color
{
  Black,
  Red,
};

// Represents the set of all cards.
struct Card
{
  Card(int id)
    : id(id)
  { }

  virtual ~Card() = default;

  int id;
};

// A suited card IS-A card.
//
// (Card is a superclass, Suited is a subclass).
struct Suited : Card // Suited is derived from Card.
{
   Suited(int id, Rank r)
    : Card(id), // Explicitly call the base class constructor.
      rank(r)
  { }
   virtual Rank get_rank() const { return this->rank;}
   Rank rank;
};

struct Spade : Suited
{
  Spade(int id, Rank r)
    : Suited(id, r)
  { }
};

struct Club : Suited
{
  Club(int id, Rank r)
    : Suited(id, r)
  { }
};

struct Heart : Suited
{
  Heart(int id, Rank r)
    : Suited(id, r)
  { }
};

struct Diamond : Suited
{
  Diamond(int id, Rank r)
    : Suited(id, r)
  { }
};


// A joker (card) IS-A card.
struct Joker : Card
{
  Joker(int id, Color c)
    : Card(id), color(c)
  { }

  Color color;
};


// A deck is a sequence of cards.
struct Deck
{
  // A collection heterogeneous objects.
  //
  // NOT a heterogeneous container.
  std::vector<Card*> cards;

  // Don't do this...
  // std::vector<Card&> cards2;
};


