//
// Created by Mikołaj on 26.04.2021.
//

#ifndef PRACA_DOMOWA_05_CARD_HPP
#define PRACA_DOMOWA_05_CARD_HPP

#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

struct card{
    int cost;
    std::string name;
    std::string description;
    int attack;
    int toughness;
};

auto get_all_cards(){
    auto card_vec = std::vector<card>{
        card{
            8, "Ragnaros the Firelord",
             "Can't attack. At the end of your turn, deal 8 damage to a random enemy.", 8, 8
        },
        card{
            6, "Sylvanas Windrunner",
            "Take control of a random enemy minion", 5, 5
        },
        card{
            4, "Sen'jin Shieldmasta","Taunt.", 3, 5
        },
        card{
             3, "Injured Blademaster",
            "Deal 4 damage to HIMSELF", 3, 7
        },
        card{
            5, "Harrison Jones",
            "Destroy your opponent's weapon and draw cards equal to its Durability", 5, 4
        },
        card{
            3, "Earthen Ring Farseer",
            "Restore 3 Health", 3, 3
        },
        card{
            5, "Azure Drake",
            "Spell Damage +1. Draw a card.", 4, 4
        },
        card{
            4, "Auchenai Soulpriest",
            "Your cards and powers that restore Health now deal damage instead", 3, 5
        },
        card{
            1, "Northsire Cleric",
            "Whenever a minion is healed, draw a card", 1, 3
        },
        card{
         2, "Wild Pyromancer",
         "After yo cast a spell, deal 1 damage to ALL minions", 3, 2
        }
    };

    return card_vec;
}

auto get_hand(){
    auto cards = get_all_cards();
    auto counter_of_duplicates = std::vector<int>(cards.size());
    auto amount_of_cards_in_hand = 7;
    auto selected_cards = std::vector<card>();

    do{
        int rand_number = rand() % cards.size();   //(0 - 9) - to nie jest losowe. Do poprawy

        if(counter_of_duplicates[rand_number] != 2){
            selected_cards.push_back(cards[rand_number]);
            counter_of_duplicates[rand_number] ++;
        }

    }while(
            std::accumulate(counter_of_duplicates.begin(), counter_of_duplicates.end(), 0) < amount_of_cards_in_hand
            );

    return selected_cards;
}

auto get_sample_hands(int amount_of_random_hands){
    auto cards = get_all_cards();
    auto sample_hands = std::vector< std::vector<card> >();

    for(int i = 0; i < amount_of_random_hands; i++){
        sample_hands.push_back(get_hand());
    }

    std::for_each(sample_hands.begin(), sample_hands.end(),
                  [](std::vector<card> vector_of_cards){

        std::cout << "-> ";

        std::for_each(vector_of_cards.begin(), vector_of_cards.end(),
                      [](card card){
            std::cout << card.cost << ", ";
        });

        std::cout << "\n";
    }
    );

    return sample_hands;
}


#endif //PRACA_DOMOWA_05_CARD_HPP
