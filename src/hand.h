#pragma once

#include "card.h"
#include "deck.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <string>

class Hand {
public:
    Hand()
        : m_deck(Deck())
        , m_hand(get_hand())
    {
        for (Card card : m_hand) {
            std::cout << card.to_string() << '\n';
        }
    }

    std::string evalulate()
    {
        if (is_flush()) {
            return "Flush";
        } else if (is_royal_flush()) {
            return "Royal Flush";
        } else {
            return "None";
        }
    }

private:
    using CardArray = std::array<Card, 5>;

    Deck m_deck;
    CardArray m_hand;

    CardArray get_hand()
    {
        CardArray hand;
        for (int i = 0; i < 5; i++) {
            hand[i] = m_deck.draw();
        }
        std::sort(std::begin(hand), std::end(hand));
        return hand;
    }

    bool is_flush()
    {
        for (int i = 1; i < 5; i++) {
            if (m_hand[0].get_suit() != m_hand[i].get_suit()) {
                return false;
            }
        }

        return true;
    }

    bool is_royal_flush()
    {
        if (is_flush()) {
            if (m_hand[0].get_rank() == Card::Rank::Ace && m_hand[1].get_rank() == Card::Rank::Ten
                && m_hand[2].get_rank() == Card::Rank::Jack && m_hand[3].get_rank() == Card::Rank::Queen
                && m_hand[4].get_rank() == Card::Rank::King) {
                return true;
            }
        }

        return false;
    }
};