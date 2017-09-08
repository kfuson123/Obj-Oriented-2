#include <iostream>
#include <iomanip>
#include <vector>

#include "card.hpp"

int main()
{
    Rank r1 = Two;
    Rank r2 = Ace;
    std::cout << (r1 == r2) << "\n";
    std::cout << (r1 < r2) << "\n";

    // Widening conversion. This is oka.
    int n = Jack;
    std::cout << n << "\n";

    // Narrowing conversion. Loses information. This instance it doesn't work as it cannot convert.
    //Rank r3 = 4;// error cannot convert.
    //Initialized some cards
    Card c1{Ace, Spades};
    Card c2{Four, Hearts};
    // We should be able to do this.
    Card c;
    // Create a deck of cards.
    std::vector<Card> deck;
    for (Rank r = Ace; r<= King, ++r){
        for (Suit s = Hearts; s<= Spades; ++s){
            
        }
    }

}
