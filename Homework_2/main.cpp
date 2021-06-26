#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

auto modify(std::vector<int> vec,           //ma przyjmować "vector<int>", zatem chyba nie ma jak obsługiwać liczb zmiennoprzecinkowych
            std::string str = "reverse") {

    int number;

    if (str == "reverse") {
        std::reverse(vec.begin(), vec.end());
        return vec;
    } else if (str == "append") {
        std::cout << "Jaka liczbe chcesz dodac na koniec wektora?\n";
        std::cin >> number;
        vec.push_back(number);
        return vec;
    } else if (str == "truncate") {
        vec.pop_back();
        return vec;
    }

    return vec;
}

auto count_chars(std::vector<char> vec, char ch) {
    auto counter = 0;
    for (auto i : vec) {
        if (i == ch) {
            counter++;
        }
    }
    return counter;
}

auto count_chars(std::string str, char ch) {
    return count_chars(std::vector<char>(str.begin(), str.end()), ch);
}

auto asterisks_horizontally(int limit) {
    for (auto i = 0; i < limit; i++)
        std::cout << "*";
}

auto box_print(std::vector<std::string> vec_string) {
    if (!vec_string.empty()) {                               //if(vec.size() > 0
        auto max_length = 0;

        for (auto vec : vec_string) {
            if (vec.size() > max_length) {
                max_length = vec.size();
            }
        }

        //max_length += 2;
        /*
         * Co jest lepszą praktyką? Podniesienie wartości max_length o 2 jak wyżej, czy wpisywanie tej +2 " z palca
         * do metody asterisks_horizontally jak poniżej?
         */

        asterisks_horizontally(max_length + 2);            //+2, bo tak musi być, żeby obramowanie było estetyczne i symetryczne
        for (auto vec : vec_string) {
            std::cout << "\n" << "*" << vec;
            for (auto i = 0; i < max_length - vec.size(); i++) {
                std::cout << " ";
            }
            std::cout << "*";
        }
        std::cout << "\n";
        asterisks_horizontally(max_length + 2);
    }
}

int main() {

    //Zadanie 1
    auto vector = std::vector<int>{1, 2, 3, 4, 5};
    vector = modify(vector);

    for (auto vec : vector) {
        std::cout << vec << ' ';
    }

    //Zadanie 2
    auto char_vector = std::vector<char>{'a', 'l', 'a', 'm', 'a', 'k', 'o', 't', 'a'};
    std::cout << "\n" << count_chars(char_vector, 'm');
    std::cout << "\n" << count_chars("ala ma kota", 'a');

    //Zadanie 3
    auto strings = std::vector<std::string>{"Hello", "world", "in", "a", "frame"};
    std::cout << "\n";
    box_print(strings);
}
