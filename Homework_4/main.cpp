#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

auto get_male_names_from(std::vector<std::string> names) {

    auto amount_of_male_names = std::count_if(
            names.begin(), names.end(),
            [](std::string name) { return name.back() != 'a'; }
    );

    auto male_names = std::vector<std::string>(amount_of_male_names);

    std::copy_if(
            names.begin(), names.end(),
            male_names.begin(),
            [](std::string name) { return name.back() != 'a'; }
    );

    std::sort(male_names.begin(), male_names.end());

    std::stable_sort(
            male_names.begin(), male_names.end(),
            [](std::string left, std::string right) { return left.length() < right.length(); }
    );

    return male_names;

    /*
     * 1. Zliczenie ilości męskich imion
     * 2. Stworzenie nowego wektora o "wielkości" zliczonej w punkcie 1
     * 3. Skopiowanie jedynie imion męskich z pierwotnego wektora do wektora z punktu 2
     * 4. Posortowanie nowego wektora "alfabetycznie"
     * 5. Stable_sort, aby posortować imiona po ich długościach przy jednoczesnym zachowaniu "kolejności alfabetycznej"
     */
}

auto reduce_adjacent_whitespaces(std::string reduce_me) {

    std::replace_if(reduce_me.begin(), reduce_me.end(),
                    [](char sign) { return isspace(sign); }, ' ');

    auto beginning_of_removal = std::unique(
            reduce_me.begin(), reduce_me.end(),
            [](char left_sign, char right_sign) { return (isspace(left_sign) && isspace(right_sign)); }
    );
    reduce_me.erase(beginning_of_removal, reduce_me.end());

    return reduce_me;

    /*
     * 1. Zastąp wszystkie białe znaki spacją
     * 2. Sprawdź czy dwa sąsiednie elementy są spacją. Jeżeli tak, unique usuwa jeden z nich
     *
     * std::unique
     * Removes all but the first element from every consecutive group of equivalent elements in the range [first,last)
     */
}

auto max_nested_parentheses_depth(std::string brackets) {

    auto beginning_of_removal = std::remove_if(
            brackets.begin(), brackets.end(),
            [](char sign) { return (sign != '(' && sign != ')'); });
    brackets.erase(beginning_of_removal, brackets.end());

    auto brackets_as_1_minus1 = std::vector<int>(brackets.size());

    std::transform(
            brackets.begin(), brackets.end(),
            brackets_as_1_minus1.begin(),
            [](char sign) {
                if (sign == '(') {
                    return 1;
                } else {
                    return -1;
                }
            }
    );

    //(()(())) -> 11-111-1-1-1

    std::transform(
            brackets_as_1_minus1.begin(), brackets_as_1_minus1.end() - 1,
            brackets_as_1_minus1.begin() + 1, brackets_as_1_minus1.begin() + 1,
            [](int left_one, int right_one) {
                return left_one + right_one;
            }
    );

    /*
     * brackets_as_1_minus1 - 1, bo <;)
     * pierwsze brackets_as_1_minus1.begin() + 1, bo pomijamy pierwszy element (zawsze będzie to (, czyli 1)
     */

    auto max_depth = *std::max_element(brackets_as_1_minus1.begin(), brackets_as_1_minus1.end());

    return max_depth;

    /*
     * 1. Usunięcie jakichkolwiek znaków, które nie są nawiasami
     * 2. Zamiana ( -> 1 i ) -> -1
     * 3. Najtrudniejsza część:
     *
     *      -pominięcie pierwszego elementu ("przepisujemy go" jako "wynik1", bo ciąg nawiasów ZAWSZE będzie zaczynał się nawiasem otwierającym)
     *      -zsumowanie "wyniku1" i drugiego elementu (->wynik2)
     *      -zsumowanie "wyniku2" i trzeciego elementu (->wynik3)
     *      -...
     *      przykład:
     *      ()(())() -> 1 -1 1 1 -1 -1 1 -1
     *                  1  0 1 2  1  0 1  0
     * 4. Max element to wynik (*, bo chcemy zwrócić wartość, a nie iterator)
     */
}

int main() {

    //Zadanie 1
    {
        auto vec = std::vector<std::string>{"Mikolaj", "Alicja", "Jerzy", "Wiktoria", "Aleksandra", "Marcin", "Jakub",
                                            "Aleksander", "Marian", "Krystyna", "Zbyszko", "Grzegorz", "Arystoteles",
                                            "Krystian", "Maksymilian", "Anatoliusz"};

        auto male_names = get_male_names_from(vec);

        for (auto v : male_names) {
            std::cout << v << ' ';
        }
        std::cout << "\n";
    }

    //Zadanie 2
    {
        std::cout
                << '['
                << reduce_adjacent_whitespaces("Abc")
                << "]\n"
                << "["
                << reduce_adjacent_whitespaces("A b c")
                << "]\n"
                << "["
                << reduce_adjacent_whitespaces("     A b c     ")
                << "]\n"
                << "["
                << reduce_adjacent_whitespaces("A\t\tb\n \n  \t c")
                << "]\n";
    }

    //Zadanie 3
    {
        std::cout
                << max_nested_parentheses_depth("()") << ' '
                << max_nested_parentheses_depth("(()(()))") << ' '
                << max_nested_parentheses_depth("(sd()ds((ss))   a)") << ' '
                << max_nested_parentheses_depth("(((S)))") << ' '
                << max_nested_parentheses_depth("()()()()") << ' '
                << max_nested_parentheses_depth("()(())()") << ' ';
    }

    return 0;
}
