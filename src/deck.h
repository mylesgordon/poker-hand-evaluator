#include "card.h"
#include <vector>

class Deck {
public:
    Deck()
    {
        for (int rank = 0; rank < 14; rank++) {
            for (int suit = 0; suit < 4; suit++) {
                auto rank_enum = static_cast<Card::Rank>(rank);
                auto suit_enum = static_cast<Card::Suit>(suit);
                Card new_card(rank_enum, suit_enum);
                m_deck.push_back(new_card);
            }
        }
    }

    // TODO: add shuffle

    Card draw()
    {
        const Card drawn_card = m_deck.at(0);
        m_deck.erase(m_deck.begin());

        return drawn_card;
    };

    const std::vector<Card>& get_deck() { return m_deck; };

private:
    std::vector<Card> m_deck;
};
