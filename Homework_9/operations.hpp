//
// Created by Mikołaj on 09.05.2021.
//

#ifndef PRACA_DOMOWA_09_OPERATIONS_HPP
#define PRACA_DOMOWA_09_OPERATIONS_HPP

#include <iostream>

namespace models{

    namespace predicates{

        auto is_adult(const student& s){
            if (s.getAge() >= 18){
                return true;
            }else{
                return false;
            }
        }

    }

    namespace mappers{

        auto virgin_to_string(const student& s){
            std::cout << s.getName() << " " << s.getSurname() << " " << s.getAge() << '\n';
        }

    }

}

#endif //PRACA_DOMOWA_09_OPERATIONS_HPP
