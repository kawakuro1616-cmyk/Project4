#include <iostream>
#include <vector>
#include <string>
#include <random>    
#include <algorithm> 

class Card {
public:
    enum Suit { SPADE, HEART, DIAMOND, CLUB };
    enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

    Suit suit;
    Rank rank;

    std::string toString() const {
        std::string s_suit, s_rank;
        switch (suit) {
        case SPADE:   s_suit = "スペード"; break;
        case HEART:   s_suit = "ハート";   break;
        case DIAMOND: s_suit = "ダイヤ";   break;
        case CLUB:    s_suit = "クラブ";   break;
        }
        if (rank >= TWO && rank <= TEN) {
            s_rank = std::to_string(rank);
        }
        else {
            switch (rank) {
            case ACE:   s_rank = "A"; break;
            case JACK:  s_rank = "J"; break;
            case QUEEN: s_rank = "Q"; break;
            case KING:  s_rank = "K"; break;
            }
        }
        return s_suit + " の " + s_rank;
    }
};


class Deck {
private:
    std::vector<Card> cards;

public:

    Deck() {
        for (int s = Card::SPADE; s <= Card::CLUB; ++s) {
            for (int r = Card::ACE; r <= Card::KING; ++r) {
                cards.push_back({ static_cast<Card::Suit>(s), static_cast<Card::Rank>(r) });
            }
        }
    }


    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }


    Card draw() {
        Card drawn_card = cards.back();
        cards.pop_back();
        return drawn_card;
    }


    auto begin() { return cards.begin(); }
    auto end() { return cards.end(); }
};

int main() {

    Deck myDeck;

    std::cout << "シャッフルします..." << std::endl;
    myDeck.shuffle();

    std::cout << "\n--- シャッフル後のデッキ一覧 ---" << std::endl;

    for (const auto& card : myDeck) {
        std::cout << card.toString() << std::endl;
    }

    return 0;
}