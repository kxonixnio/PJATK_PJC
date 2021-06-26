//
// Created by Mikołaj on 04.05.2021.
//

#ifndef PRACA_DOMOWA_08_SHAPE_HPP
#define PRACA_DOMOWA_08_SHAPE_HPP


struct shape {
    virtual double get_area() const = 0;
    virtual double get_perimeter() const = 0;
};

void print_shape_info(const shape &s) {                                                         //ten const oznacza +/- "to może być const, ale nie musi"
    std::cout<<"area: " << s.get_area() << "\nperimeter: " << s.get_perimeter()<<"\n";
}

//https://stackoverflow.com/questions/7530616/override-on-non-virtual-functions

#endif //PRACA_DOMOWA_08_SHAPE_HPP
