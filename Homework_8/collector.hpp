//
// Created by Mikołaj on 05.05.2021.
//

#ifndef PRACA_DOMOWA_08_COLLECTOR_HPP
#define PRACA_DOMOWA_08_COLLECTOR_HPP

#include <vector>

struct collector {
    virtual void collect(const char to_collect) = 0;
};

#endif //PRACA_DOMOWA_08_COLLECTOR_HPP
