//
// Created by Mikołaj on 05.05.2021.
//

#ifndef PRACA_DOMOWA_08_REVERSE_STRING_COLLECTOR_HPP
#define PRACA_DOMOWA_08_REVERSE_STRING_COLLECTOR_HPP

#include <string>

#include "collector.hpp"

struct reverse_string_collector : collector {

private:
    std::string str;

    void collect(const char to_collect) {
        str.insert(str.begin(), to_collect);
    }

public :
    auto representation() {
        return str;
    }
};

#endif //PRACA_DOMOWA_08_REVERSE_STRING_COLLECTOR_HPP
