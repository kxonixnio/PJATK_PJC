//
// Created by Mikołaj on 05.05.2021.
//

#ifndef PRACA_DOMOWA_08_OBJECT_STORING_CHARS_HPP
#define PRACA_DOMOWA_08_OBJECT_STORING_CHARS_HPP

#include "collector.hpp"

#include <vector>
#include <algorithm>

struct store{
    std::vector<char> vec;

    store(std::vector<char>vector_chars) : vec(vector_chars){}

    auto collect_using(collector& col){
        for(auto element : vec){
            col.collect(element);
        }
    }
};

auto filter_hyphens_from(std::vector<char> vec_char){
    auto s = store(vec_char);

    auto beginning_of_removal = std::remove(s.vec.begin(), s.vec.end(), '-');
    s.vec.erase(beginning_of_removal, s.vec.end());

    return s;
}

#endif //PRACA_DOMOWA_08_OBJECT_STORING_CHARS_HPP
