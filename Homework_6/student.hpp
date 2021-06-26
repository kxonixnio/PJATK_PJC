//
// Created by Mikołaj on 29.04.2021.
//

#ifndef PRACA_DOMOWA_06_STUDENT_HPP
#define PRACA_DOMOWA_06_STUDENT_HPP

struct student {
    std::string name;
    std::string surname;
    int age;

    student(std::string n, std::string s, int a) {
        name = n;
        surname = s;
        age = a;
        student_count += 1;
    }

    student() {
        age = 0;
        student_count += 1;
//        std::cout << "student created\n";
    }

    student(const student &other) {
        name = other.name;
        surname = other.surname;
        age = other.age;
        student_count += 1;

//        std::cout << "student copied\n";
    }

    student &operator=(const student &other) {
        name = other.name;
        surname = other.surname;
        age = other.age;

        return *this;
    }

    ~student() {
        student_count -= 1;
//        std::cout << "student destroyed\n";
    }

    static inline auto student_count = 0;       //w przypadku zmiennych piszemy jeszcze inline

    static void print_number_of_students() {    //statyczna metoda
        std::cout << student_count << '\n';
    }

    static auto name_comparator() {

        auto compare_by_name = [](student student1, student student2) {
            return student1.name < student2.name;
        };

        return compare_by_name;
    }

    static auto surname_comparator() {

        auto compare_by_surname = [](student student1, student student2) {
            return student1.surname < student2.surname;
        };

        return compare_by_surname;
    }

    static auto age_comparator() {

        auto compare_by_age = [](student student1, student student2) {
            return student1.age < student2.age;
        };

        return compare_by_age;
    }

    static auto comparator() {

        /*auto complete_comparator = [](student student1, student student2){        //ŹLE

            if(student1.name == student2.name){
                if(student1.surname == student2.surname){
                    return age_comparator();
                }else{
                    return surname_comparator();
                }
            }else{
                return name_comparator();
            }
        };

        return complete_comparator;*/

        /*auto complete_comparator = [](student student1, student student2) -> bool {       //ŹLE
            if(student1.name == student2.name){
                if(student1.surname == student2.surname){
                    return age_comparator();
                }else{
                    return surname_comparator();
                }
            }else{
                return name_comparator();
            }
        };

        return complete_comparator;

         //"lambda nie przekazuje argumentów w kolejną lambdę"
         */

        auto suitable_comparision = [](student student1, student student2) {

            if (student1.name != student2.name) {
                return student1.name < student2.name;
            } else if (student1.surname != student2.surname) {
                return student1.surname < student2.surname;
            } else {
                return student1.age < student2.age;
            }

        };
        return suitable_comparision;
    }
};


#endif //PRACA_DOMOWA_06_STUDENT_HPP
