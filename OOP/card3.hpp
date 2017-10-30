#pragma once

#include <iostream>
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
  King,
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

struct Card
{
  // // Virtual keyword associates the behavior with the
  // // dynamic type of the object.
  // virtual void print() const {
  //   throw std::logic_error("i don't know what you want");
  // }
  
  // Pure virtual function
  virtual void print() const = 0;
};


struct Suited : Card
{
  Suited(Rank r, Suit s) 
    : rank(r), suit(s) 
  { }

  // Override the behavior in a derived class. (not overwrite).
  void print() const override {
    std::cout << rank << ' ' << suit << '\n';
  }

  Rank rank;
  Suit suit;
};

struct Joker : Card
{
  Joker(Color c)
    : color(c)
  { }

  virtual void print() const {
    std::cout << color << '\n';
  }

  Color color;
};

struct Uno : Card
{

};


using Deck = std::vector<Card*>;
