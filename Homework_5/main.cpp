#include <iostream>
#include <algorithm>
#include "card.hpp"
#include "operations.hpp"

auto sorted(std::vector<card> cards, comparing_by comparing_by){

    if(comparing_by == comparing_by::cost){
        std::sort(cards.begin(), cards.end(), get_cost_comparator());
    }
    if(comparing_by == comparing_by::name){
        std::sort(cards.begin(), cards.end(), get_name_comparator());
    }
    if(comparing_by == comparing_by::description){
        std::sort(cards.begin(), cards.end(), get_description_comparator());
    }
    if(comparing_by == comparing_by::attack){
        std::sort(cards.begin(), cards.end(), get_attack_comparator());
    }
    if(comparing_by == comparing_by::toughness){
        std::sort(cards.begin(), cards.end(), get_toughness_comparator());
    }

    return cards;
}

auto get_max(std::vector<card> cards, comparing_by comparing_by){

    auto card = cards[0];

    if(comparing_by == comparing_by::cost){
        cards = sorted(cards, comparing_by::cost);
        std::reverse(cards.begin(), cards.end());
        card = cards[0];
    }
    if(comparing_by == comparing_by::name){
        cards = sorted(cards, comparing_by::name);
        std::reverse(cards.begin(), cards.end());
        card = cards[0];
    }
    if(comparing_by == comparing_by::description){
        cards = sorted(cards, comparing_by::description);
        std::reverse(cards.begin(), cards.end());
        card = cards[0];
    }
    if(comparing_by == comparing_by::attack){
        cards = sorted(cards, comparing_by::attack);
        std::reverse(cards.begin(), cards.end());
        card = cards[0];
    }
    if(comparing_by == comparing_by::toughness){
        cards = sorted(cards, comparing_by::toughness);
        std::reverse(cards.begin(), cards.end());
        card = cards[0];
    }

    return card;
}

auto get_min(std::vector<card> cards, comparing_by comparing_by){

    auto card = cards[0];

    if(comparing_by == comparing_by::cost){
        cards = sorted(cards, comparing_by::cost);
        card = cards[0];
    }
    if(comparing_by == comparing_by::name){
        cards = sorted(cards, comparing_by::name);
        card = cards[0];
    }
    if(comparing_by == comparing_by::description){
        cards = sorted(cards, comparing_by::description);
        card = cards[0];
    }
    if(comparing_by == comparing_by::attack){
        cards = sorted(cards, comparing_by::attack);
        card = cards[0];
    }
    if(comparing_by == comparing_by::toughness){
        cards = sorted(cards, comparing_by::toughness);
        card = cards[0];
    }

    return card;
}

int main() {

    for (auto hand : get_sample_hands(5)) {
        for (auto card : sorted(hand, comparing_by::cost)) {
            std::cout << card.cost << ' ' << card.name << '\n';
        }
        std::cout << "========== ### ==========\n";
    }

    auto most_expensive_card = get_max(
            get_sample_hands(1).front(),
            comparing_by::cost
    );
    std::cout << most_expensive_card.cost <<"\n";

    auto least_expensive_card = get_min(
            get_sample_hands(1).front(),
            comparing_by::cost
    );
    std::cout << least_expensive_card.cost;

    return 0;
}
