//
// Created by Mikołaj on 04.05.2021.
//

#ifndef PRACA_DOMOWA_08_RECTANGLE_HPP
#define PRACA_DOMOWA_08_RECTANGLE_HPP

struct rectangle : shape {
private:
    double width;
    double height;

public :
    rectangle(double rect_width, double rect_height) : width(rect_width), height(rect_height) {}

    double get_area() const override {
        return width * height;
    }

    double get_perimeter() const override {
        return (2 * width + 2 * height);
    }


};

#endif //PRACA_DOMOWA_08_RECTANGLE_HPP
