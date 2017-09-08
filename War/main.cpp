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
    
    //Declaration, invokes a constuctor to initialize an object (c3)
    Card c3 = c1;
    
    //Assignment(expression)
    c3 = c2;
    
    // We should be able to do this.
    Card c;
    // Create a deck of cards.
    std::vector<Card> deck;
    deck.reserve(52);
    for (int r = Ace; r<= King; ++r){
        for (int s = Hearts; s<= Spades; ++s){
            Card c{static_cast<Rank>(r), static_cast<Suit>(s)};
            deck.push_back(c);
            //Creates a card.
        }
    }
    for (Card c : deck) {
        std::cout << c.get_rank() << " " << c.get_suit() << "\n";
    }

}
