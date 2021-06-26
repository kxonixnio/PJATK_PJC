//
// Created by Mikołaj on 05.05.2021.
//

#ifndef PRACA_DOMOWA_08_REVERSE_VECTOR_COLLECTOR_HPP
#define PRACA_DOMOWA_08_REVERSE_VECTOR_COLLECTOR_HPP

#include "collector.hpp"

struct reverse_vector_collector : collector {

private:
    std::vector<char> vec;

    void collect(const char to_collect) {
        vec.insert(vec.begin(), to_collect);
    }

public :
    auto representation() {
        return vec;
    }
};

#endif //PRACA_DOMOWA_08_REVERSE_VECTOR_COLLECTOR_HPP
