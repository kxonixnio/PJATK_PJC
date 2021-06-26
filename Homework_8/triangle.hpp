//
// Created by Mikołaj on 04.05.2021.
//

#ifndef PRACA_DOMOWA_08_TRIANGLE_HPP
#define PRACA_DOMOWA_08_TRIANGLE_HPP

struct triangle : shape {       //trojkat rownoboczny
private:
    double height;
    double base;

public:
    triangle(double rect_height, double rect_base) : height(rect_height), base(rect_base) {}

    double get_area() const override {
        return (base * height) / 2;
    }

    double get_perimeter() const override {
        return 3 * base;
    }
};

#endif //PRACA_DOMOWA_08_TRIANGLE_HPP
