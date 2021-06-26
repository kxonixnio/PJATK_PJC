//
// Created by Mikołaj on 29.04.2021.
//

#ifndef PRACA_DOMOWA_06_LOUD_INT_HPP
#define PRACA_DOMOWA_06_LOUD_INT_HPP

#include <algorithm>
#include <vector>

struct loud_int {
    int number;

    loud_int(int a) {
        number = a;
        std::cout << "loud_int(int " << a << ") created\n";
        amount_of_loud_ints_created += 1;
    }

    loud_int() {
        number = 0;
        std::cout << "loud_int() created\n";
    }

    loud_int(const loud_int& other_loud_int) {
        number = other_loud_int.number;
        std::cout << "loud_int copied\n";
        amount_of_loud_ints_copied += 1;
    }

    loud_int& operator=(const loud_int& other) {
        number = other.number;
        std::cout << "loud_int overwrote\n";
        amount_of_loud_ints_overwrote += 1;
        return *this;
    }

    ~loud_int() {
        std::cout << "loud_int destroyed\n";
        amount_of_loud_ints_destroyed += 1;
    }

    static inline auto amount_of_loud_ints_created = 0;
    static inline auto amount_of_loud_ints_copied = 0;
    static inline auto amount_of_loud_ints_destroyed = 0;
    static inline auto amount_of_loud_ints_overwrote = 0;
};

auto make_louder(std::vector<int>vector_int){
    auto vector_loud_int = std::vector<loud_int>();

    std::for_each(vector_int.begin(), vector_int.end(),
                  [&](int a){
        vector_loud_int.push_back(loud_int(a));
    });

    return vector_loud_int;

//    & -> https://docs.microsoft.com/pl-pl/cpp/error-messages/compiler-errors-2/compiler-error-c3493?view=msvc-160
//    Default capture modes are [=] (by value) and [&] (by reference). [ ] means no capture
}

auto test_sorting(){
    auto loud_int_vec = std::vector<loud_int>();

    for(int i = 0; i < 20; i++){
        loud_int_vec.push_back(
                loud_int(rand() % 101)
                );
    }

    loud_int::amount_of_loud_ints_created = 0;
    loud_int::amount_of_loud_ints_copied = 0;
    loud_int::amount_of_loud_ints_destroyed = 0;
    loud_int::amount_of_loud_ints_overwrote = 0;

    std::cout << "sort:\n";

    std::sort(loud_int_vec.begin(), loud_int_vec.end(),
              [](loud_int li1, loud_int li2){
        return li1.number < li2.number;
    });

    /*
     * Powyższe sortowanie wykonało:
     * amount_of_loud_ints_created: 0
     * amount_of_loud_ints_copied: 225
     * amount_of_loud_ints_destroyed: 225
     * amount_of_loud_ints_overwrote: 73
     */

    std::cout << "amount_of_loud_ints_created: " << loud_int::amount_of_loud_ints_created
              << "\namount_of_loud_ints_copied: " << loud_int::amount_of_loud_ints_copied
              << "\namount_of_loud_ints_destroyed: " << loud_int::amount_of_loud_ints_destroyed
              << "\namount_of_loud_ints_overwrote: " << loud_int::amount_of_loud_ints_overwrote << "\n";

//    std::for_each(loud_int_vec.begin(), loud_int_vec.end(),
//                  [](loud_int li){std::cout << "->" << li.number << "<-";});
//
}

#endif //PRACA_DOMOWA_06_LOUD_INT_HPP
