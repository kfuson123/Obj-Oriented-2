#include <iostream>
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
    //Rank r3 = 4;

    Card c1{Ace, Spades};
    Card c2{Four, Hearts};
    Card c3(Three, Clubs);
    Card c4(Two, Diamonds);
    Card c5(Five, Spades);
    Card c6(Jack, Hearts);
    Card c7(Queen, Diamonds);
    Card c8(King, Clubs);
    Card c9(Ten, Spades);
    Card c10(Eight, Hearts);





}
