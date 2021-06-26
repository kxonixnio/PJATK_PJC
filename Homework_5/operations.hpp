//
// Created by Mikołaj on 27.04.2021.
//

#ifndef PRACA_DOMOWA_05_OPERATIONS_HPP
#define PRACA_DOMOWA_05_OPERATIONS_HPP

#include "card.hpp"

enum class comparing_by{
    cost, name, description, attack, toughness
};

auto get_name_comparator(){

    auto compare_by_name = [](card card1, card card2){
        return card1.name < card2.name;
    };

    return compare_by_name;
}

auto get_description_comparator(){

    auto compare_by_description = [](card card1, card card2){
        return card1.description < card2.description;
    };

    return compare_by_description;
}

auto get_cost_comparator(){

    auto compare_by_cost = [](card card1, card card2){
        return card1.cost < card2.cost;
    };

    return compare_by_cost;
}

auto get_attack_comparator(){

    auto compare_by_attack = [](card card1, card card2){
        return card1.attack < card2.attack;
    };

    return compare_by_attack;
}

auto get_toughness_comparator(){

    auto compare_by_toughness = [](card card1, card card2){
        return card1.toughness < card2.toughness;
    };

    return compare_by_toughness;
}

#endif //PRACA_DOMOWA_05_OPERATIONS_HPP
