#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>

enum class CardKind {
    Coeur,
    Carreau,
    Trefle,
    Pique,
};

enum class CardValue {
    Deux,
    Trois,
    Quatre,
    Cinq,
    Six,
    Sept,
    Huit,
    Neuf,
    Dix,
    Valet,
    Dame,
    Roi,
    As,
};

struct Card {
    CardKind kind;
    CardValue value;

    size_t hash() const {
        return static_cast<size_t>(kind) * 13 + static_cast<size_t>(value);
    }
};

bool operator==(const Card& gauche, const Card& droite) {
    return gauche.kind == droite.kind && gauche.value == droite.value;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " de ";

    if (card.kind == CardKind::Coeur) {
        name += "Coeur";
    }else if (card.kind == CardKind::Carreau) {
        name += "Carreau";
    }else if (card.kind == CardKind::Trefle) {
        name += "Trèfle";
    }else if (card.kind == CardKind::Pique) {
        name += "Pique";
    }
    return name;
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

int main() {
    std::vector<Card> cards = get_cards(100);
    std::unordered_map<Card, int> card_counts;

    for (const auto& card : cards) {
        card_counts[card]++;
    }

    for (const auto& pair : card_counts) {
        std::cout << card_name(pair.first) << " : " << pair.second << std::endl;
    }

    return 0;
}
