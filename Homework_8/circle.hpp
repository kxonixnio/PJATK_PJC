//
// Created by Mikołaj on 04.05.2021.
//

#ifndef PRACA_DOMOWA_08_CIRCLE_HPP
#define PRACA_DOMOWA_08_CIRCLE_HPP

#include <math.h>

struct circle : shape {
private:
    double radius;

public :
    circle(double circ_radius) : radius(circ_radius) {}

    double get_area() const override {
    return M_PI * radius * radius;
    }

    double get_perimeter() const override {
        return 2 * M_PI * radius;
    }
};

#endif //PRACA_DOMOWA_08_CIRCLE_HPP
