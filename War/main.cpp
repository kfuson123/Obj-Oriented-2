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
    //Rank r3 = 4;

    Card c1{Ace, Spades};
    Card c2{Four, Hearts};

    Card c;
    
    std::vector<Card> deck(52);
    


}
