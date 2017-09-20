// Kyle Fuson
// All rights reserved

#include <utility>
#include <iosfwd>

// Ranks of a card:
// ace, 2-10, jack, king, and queen.

// Suits of a card are:
// hearts, diamonds, clubs, spades

// using Card = int[2];
// using Card = std::pair<int, int>;

enum Rank  // Enumeration type
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
    Hearts,
    Diamonds,
    Clubs,
    Spades,
};

    // A playing card (in a standard deck) is a pair of rank and suit (see enums above).
class Card
{
public:
    // Creates a "not a card" abstraction/
    //Card()
    //: rank(), suit()
    //{ }

    // Possibly better. Creats a uninitialized abstradction
    //Card()
    //{ }

    // Good
    Card() = default;
    // Construct a card with a rank and suit.
    Card(Rank r, Suit s)
        : rank(r), suit(s) // member initializer list
    { }
    /*
    // Copy consturctor.
    Card(const Card& c)
        : rank(c.rank), (c.suit)
    { }

    // Copy assignment operator
    Card& operator=(const Card& c)
    {
        rank = c.rank;
        suit = c.suit;
        return *this;
    }
    */

    // Accessor functions.
    // Returns rank of the card
    Rank get_rank() const { return rank;}
    // Returns suit of the card
    Suit get_suit() const { return suit;}

    // Mutator or modifier functions
    // Don't provide mutators if they're just assignment.
    // Prefer to make things public
    /*
    void set_rank(Rank r) {
        rank=r;
    }
    void set_suit(Suit r) {
        suit=s;
    }
    */


private:
     Rank rank;
     Suit suit;
};


// Equality comparison
bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

// Comparsion operators
bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);

std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Suit s);

