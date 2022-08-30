#include "deck.h"
#include "hand.h"
#include <iostream>

int main()
{
    bool should_run { true };
    while (should_run) {
        Hand hand;
        auto evaluation = hand.evalulate();
        std::cout << evaluation << '\n';

        if (evaluation != "None") {
            should_run = false;
        }
    }

    return 0;
}
