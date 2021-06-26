#include <iostream>
#include <vector>
#include <algorithm>
#include "student.hpp"
#include "loud_int.hpp"

int main() {

    auto s1 = student("Adam", "Mickiewicz", 31);
    auto s2 = student("Adam", "Mickiewicz", 18);
    auto s3 = student("Adam", "Mickiewicz", 9);
    auto s4 = student("Michal", "Tomaszew", 850);
    auto s5 = student("Procek", "Szescdziewiec", 69);
    auto s6 = student("Dziki", "Golomp", 420);
    auto s7 = student("Michal", "Tomaszew", 800);

    std::vector<student> student_vector{s2, s3, s4, s7, s1, s5, s6};

    std::for_each(student_vector.begin(), student_vector.end(),
                  [](student student) {
                      std::cout << student.name << " " << student.surname << " " << student.age << "\n";
                  });

    std::sort(student_vector.begin(), student_vector.end(), student::comparator());

    std::cout << "\n";
    std::for_each(student_vector.begin(), student_vector.end(),
                  [](student student) {
                      std::cout << student.name << " " << student.surname << " " << student.age << "\n";
                  });

    std::cout << "\n\n\n";

    std::vector<int> int_vec {1, 2, 3, 4, 5};
    std::vector<loud_int> loud_vec = make_louder(int_vec);

    std::for_each(loud_vec.begin(), loud_vec.end(),
                  [](loud_int li){std::cout << "->" << li.number << "<-\n";});

    std::cout<< "\ntest_sorting():\n";
    test_sorting();

    return 0;
}
