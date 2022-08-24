#include <array>
#include <fmt/format.h>
#include <string>

class Card {
public:
    enum class Rank {
        Ace,
        One,
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
        King
    };

    enum class Suit {
        Hearts,
        Spades,
        Clubs,
        Diamonds
    };

    Card(Rank rank, Suit suit)
        : m_rank(rank)
        , m_suit(suit) {};

    Rank get_rank()
    {
        return m_rank;
    }

    Suit get_suit()
    {
        return m_suit;
    }

    std::string to_string()
    {
        const std::string& rank_string = m_rank_strings[rank_as_int()];
        const std::string& suit_string = m_suit_strings[suit_as_int()];

        return fmt::format("{} of {}", rank_string, suit_string);
    }

private:
    Rank m_rank;
    Suit m_suit;

    int rank_as_int() { return static_cast<int>(m_rank); };
    int suit_as_int() { return static_cast<int>(m_suit); };

    std::array<std::string, 14> m_rank_strings { "Ace", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    std::array<std::string, 4> m_suit_strings { "Hearts", "Spades", "Clubs", "Diamonds" };
};
