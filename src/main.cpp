#include "deck.h"
#include <iostream>

int main()
{
    Deck deck;
    std::cout << deck.draw().to_string() << '\n';

    return 0;
}
