#include <iostream>
#include <string>

#include "operators.hpp"

int main() {

    {
        using namespace pjc::string_operators;

        auto str = std::string("abc");
        std::cout << (str * 5) <<'\n';
        std::cout << (5 * str) << '\n';

        auto str1 = std::string("ala ma kota i psa");
        auto str2 = std::string("kota i psa");
        std::cout << (str1 - str2) <<'\n';
        std::cout << str1 <<'\n';

        auto str3 = std::string("abc");
        (str3 *= 5);
        std::cout << str3 <<'\n';

        auto str4 = std::string("ala ma kota i psa");
        auto str5 = std::string("kota i psa");
        std::cout << str4 <<'\n';
        std::cout << str5 <<'\n';
        (str4 -= str5);
        std::cout << str4 <<'\n';

        auto str6 = std::string("01234567890");
        for(const auto& splitted_string : (str6 / 3)){
            std::cout << splitted_string <<'\n';
        }
    }

    {
        using namespace pjc::vector_operators;

        auto vec = std::vector<int>{1, 2};
        vec += 3, 4, 5;
//        operator,(vec, 4);
//        vec,5,6;
        vec.push_back(6);
        vec += 7, 8, 9, 10;

        auto double_vec = std::vector<double>{1.5, 2.5};
        double_vec += 3.5, 4.5, 5.5;

        auto string_vec = std::vector<std::string>{std::string("ala")};
        string_vec += std::string("ma"), std::string("kota");

        for(const auto& element : vec){
            std::cout << element << ' ';
        }
        std::cout<<'\n';
        for(const auto& element : double_vec){
            std::cout << element << ' ';
        }
        std::cout<<'\n';
        for(const auto& element : string_vec){
            std::cout << element << ' ';
        }

    }
}