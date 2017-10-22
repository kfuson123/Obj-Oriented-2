#include "card2.hpp"

#include <iostream>
#include <algorithm>
#include <random>

std::random_device rng;
std::minstd_rand prng;




int main()
{
  prng.seed(rng());
  // fix later brain isn't functioning properly
  Spade c1 {0, Ace};
  Spade c2 {1, Two};
  Spade c3 {2, Three};
  Spade c4 {3, Four};
  Spade c5 {4, Five};
  Spade c6 {5, Six};
  Spade c7 {6, Seven};
  Spade c8 {7, Eight};
  Spade c9 {8, Nine};
  Spade c10 {9, Ten};
  Spade c11 {10, Jack};
  Spade c12 {11, Queen};
  Spade c13 {12, King};

  Club c14 {13, Ace};
  Club c15 {14, Two};
  Club c16 {15, Three};
  Club c17 {16, Four};
  Club c18 {17, Five};
  Club c19 {18, Six};
  Club c20 {19, Seven};
  Club c21 {20, Eight};
  Club c22 {21, Nine};
  Club c23 {22, Ten};
  Club c24 {23, Jack};
  Club c25 {24, Queen};
  Club c26 {25, King};

  Heart c27 {26, Ace};
  Heart c28 {27, Two};
  Heart c29 {28, Three};
  Heart c30 {29, Four};
  Heart c31 {30, Five};
  Heart c32 {31, Six};
  Heart c33 {32, Seven};
  Heart c34 {33, Eight};
  Heart c35 {34, Nine};
  Heart c36 {35, Ten};
  Heart c37 {36, Jack};
  Heart c38 {37, Queen};
  Heart c39 {38, King};

  Diamond c40 {39, Ace};
  Diamond c41 {40, Two};
  Diamond c42 {41, Three};
  Diamond c43 {42, Four};
  Diamond c44 {43, Five};
  Diamond c45 {44, Six};
  Diamond c46 {45, Seven};
  Diamond c47 {46, Eight};
  Diamond c48 {47, Nine};
  Diamond c49 {48, Ten};
  Diamond c50 {49, Jack};
  Diamond c51 {50, Queen};
  Diamond c52 {51, King};

  Joker j1{52, Black};
  Joker j2{53, Red};

  Deck d;
  d.cards.push_back(&c1);
  d.cards.push_back(&c2);
  d.cards.push_back(&c3);
  d.cards.push_back(&c4);
  d.cards.push_back(&c5);
  d.cards.push_back(&c6);
  d.cards.push_back(&c7);
  d.cards.push_back(&c8);
  d.cards.push_back(&c9);
  d.cards.push_back(&c10);
  d.cards.push_back(&c11);
  d.cards.push_back(&c12);
  d.cards.push_back(&c13);
  d.cards.push_back(&c14);
  d.cards.push_back(&c15);
  d.cards.push_back(&c16);
  d.cards.push_back(&c17);
  d.cards.push_back(&c18);
  d.cards.push_back(&c19);
  d.cards.push_back(&c20);
  d.cards.push_back(&c21);
  d.cards.push_back(&c22);
  d.cards.push_back(&c23);
  d.cards.push_back(&c24);
  d.cards.push_back(&c25);
  d.cards.push_back(&c26);
  d.cards.push_back(&c27);
  d.cards.push_back(&c28);
  d.cards.push_back(&c29);
  d.cards.push_back(&c30);
  d.cards.push_back(&c31);
  d.cards.push_back(&c32);
  d.cards.push_back(&c33);
  d.cards.push_back(&c34);
  d.cards.push_back(&c35);
  d.cards.push_back(&c36);
  d.cards.push_back(&c37);
  d.cards.push_back(&c38);
  d.cards.push_back(&c39);
  d.cards.push_back(&c40);
  d.cards.push_back(&c41);
  d.cards.push_back(&c42);
  d.cards.push_back(&c43);
  d.cards.push_back(&c44);
  d.cards.push_back(&c45);
  d.cards.push_back(&c46);
  d.cards.push_back(&c47);
  d.cards.push_back(&c48);
  d.cards.push_back(&c49);
  d.cards.push_back(&c50);
  d.cards.push_back(&c51);
  d.cards.push_back(&c52);
  d.cards.push_back(&j1);
  d.cards.push_back(&j2);

  std::shuffle(d.cards.begin(), d.cards.end(), prng);

  std::cout << d.cards[0]->id << '\n';


  std::cout << d.cards[1]->id << '\n';
  std::cout << d.cards[2]->id << '\n';
  std::cout << d.cards[3]->id << '\n';
}
