//
// Created by Mikołaj on 09.05.2021.
//

#ifndef PRACA_DOMOWA_09_STUDENT_HPP
#define PRACA_DOMOWA_09_STUDENT_HPP

#include <string>

namespace models {

    struct student {
    private:
        std::string name;
        std::string surname;
        int age;

    public:
        student(const std::string &name, const std::string &surname, const int age);

        student();

        const std::string &getName() const;

        void setName(const std::string &name);

        const std::string &getSurname() const;

        void setSurname(const std::string &surname);

        int getAge() const;

        void setAge(int age);

        friend void set_all (
                student& s,
                const std::string &new_name,
                const std::string &new_surname,
                const int new_age
        );
        /*
         * set_all to NIE JEST funkcja ani metoda - po prostu mówimy, że set_all jest naszym "przyjacielem"
         * i ma dostęp do prywatnych pól
         *
         * "A propos komentarza wyzej - set_all to jest funkcja, ale nie jest to typowa deklaracja ani definicja"
         */
    };
}

#endif //PRACA_DOMOWA_09_STUDENT_HPP
