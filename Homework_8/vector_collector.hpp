//
// Created by Mikołaj on 05.05.2021.
//

#ifndef PRACA_DOMOWA_08_VECTOR_COLLECTOR_HPP
#define PRACA_DOMOWA_08_VECTOR_COLLECTOR_HPP

#include "collector.hpp"

struct vector_collector : collector {

private:
    std::vector<char> vec;

    void collect(const char to_collect) {
        vec.push_back(to_collect);
    }

public :
    auto representation() {
        return vec;
    }
};

#endif //PRACA_DOMOWA_08_VECTOR_COLLECTOR_HPP
