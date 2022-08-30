#pragma once

#include "fmt/core.h"
#include <array>
#include <fmt/format.h>
#include <fmt/printf.h>
#include <string>

class Card {
public:
    enum class Rank { Ace, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

    enum class Suit { Hearts, Spades, Clubs, Diamonds };

    Card() { }

    Card(Rank rank, Suit suit)
        : m_rank(rank)
        , m_suit(suit) {};

    Rank get_rank() const { return m_rank; }
    Suit get_suit() const { return m_suit; }

    void set_rank(Rank rank) { m_rank = rank; }
    void set_suit(Suit suit) { m_suit = suit; }

    std::string to_string()
    {
        const std::string& rank_string = m_rank_strings[rank_as_int()];
        const std::string& suit_string = m_suit_strings[suit_as_int()];

        return fmt::format("{} of {}", rank_string, suit_string);
    }

    bool operator<(const Card& other) const { return m_rank < other.get_rank(); }

private:
    Rank m_rank;
    Suit m_suit;

    int rank_as_int() { return static_cast<int>(m_rank); };
    int suit_as_int() { return static_cast<int>(m_suit); };

    std::array<std::string, 14> m_rank_strings { "Ace", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" };
    std::array<std::string, 4> m_suit_strings { "Hearts", "Spades", "Clubs", "Diamonds" };
};
