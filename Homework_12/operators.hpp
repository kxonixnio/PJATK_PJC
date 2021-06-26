//
// Created by Mikołaj on 30.05.2021.
//

#ifndef PRACA_DOMOWA_12_OPERATORS_HPP
#define PRACA_DOMOWA_12_OPERATORS_HPP

#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>

namespace pjc {

    namespace string_operators {

        auto operator*(const std::string &word, const int &number) {
            auto new_string = std::string();
            for (int i = 0; i < number; i++) {
                new_string += word;
            }

            return new_string;
        }

        auto operator*(const int &number, const std::string &word) {
            auto new_string = std::string();
            for (int i = 0; i < number; i++) {
                new_string += word;
            }

            return new_string;
        }

        auto operator-(const std::string& string_to_reduce, const std::string &reducing_string) {

            auto reduce_me = string_to_reduce;

            auto beginning_of_removal = std::search(
                    reduce_me.begin(), reduce_me.end(),
                    reducing_string.begin(), reducing_string.end()
            );

            if(beginning_of_removal != reduce_me.end()) {
                reduce_me.erase(
                        beginning_of_removal,
                        beginning_of_removal + reducing_string.size()
                );
            }
            return reduce_me;
        }

        auto operator*=(std::string &word, const int &number) {
            return word = (word * number);
        }

        auto operator-=(std::string& string_to_reduce, const std::string &reducing_string) {
            return string_to_reduce = (string_to_reduce - reducing_string);
        }

        auto operator/(const std::string &word_to_split, const int &number) {
            auto vec = std::vector<std::string>();
            auto word_length = word_to_split.size();
            auto rest_of_division = word_length % number;
            auto substring_length = word_length / number;
            while (rest_of_division != 0){
                word_length += 1;
                substring_length = word_length / number;
                rest_of_division = word_length % number;
            }

            for (int i = 0; i < word_length; i += substring_length) {
                vec.push_back(word_to_split.substr(i, substring_length));
            }

            return vec;
        }

    }

    namespace vector_operators{
        template<typename T>
        auto& operator+=(std::vector<T>& vector, const T &number) {
            vector.push_back(number);
            return vector;
        }

        template<typename T>
        auto& operator,(std::vector<T>& vector, const T &number){
            return vector += number;
        }

        //https://stackoverflow.com/questions/4581961/c-how-to-overload-operator
    }

}

#endif //PRACA_DOMOWA_12_OPERATORS_HPP
