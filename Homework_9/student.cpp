//
// Created by Mikołaj on 09.05.2021.
//
#include "student.hpp"

namespace models {

    student::student(const std::string &name, const std::string &surname, const int age)
            : name(name), surname(surname), age(age) {}

    student::student() { age = 0; }  //uporanie się z UB

    const std::string &student::getName() const {
        return name;
    }

    void student::setName(const std::string &name) {
        student::name = name;
    }

    const std::string &student::getSurname() const {
        return surname;
    }

    void student::setSurname(const std::string &surname) {
        student::surname = surname;
    }

    int student::getAge() const {
        return age;
    }

    void student::setAge(int age) {
        student::age = age;
    }

    void set_all(student& s, const std::string &new_name, const std::string &new_surname, const int new_age){
        s.setName(new_name);
        s.setSurname(new_surname);
        s.setAge(new_age);
    }

}