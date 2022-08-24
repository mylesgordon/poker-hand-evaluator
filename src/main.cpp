#include "card.h"
#include <iostream>

int main()
{
    Card card(Card::Rank::Ace, Card::Suit::Clubs);
    std::cout << card.to_string() << '\n';

    return 0;
}
