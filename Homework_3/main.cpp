#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

auto contains_needle(std::string word1, std::string word2) {
    if (word1.find(word2) != std::string::npos) {
        return true;
    } else {
        return false;
    }

    /*
     * Return Value
     * The position of the first character of the first match.
     * If no matches were found, the function returns string::npos.
     */
}

auto contains_all(std::vector<int> vector1, std::vector<int> vector2) {

//    std::sort(vector1.begin(), vector1.end());
//    auto beginning_of_removal_vec1 = std::unique_copy(vector1.begin(), vector1.end(), vector1.begin());
//    vector1.erase(beginning_of_removal_vec1, vector1.end());

//    std::sort(vector2.begin(), vector2.end());
//    auto beginning_of_removal_vec2 = std::unique_copy(vector2.begin(), vector2.end(), vector2.begin());
//    vector2.erase(beginning_of_removal_vec2, vector2.end());

    std::sort(vector1.begin(), vector1.end());
    vector1.erase(
            std::unique(vector1.begin(), vector1.end()),
            vector1.end()
    );

    std::sort(vector2.begin(), vector2.end());
    vector2.erase(
            std::unique(vector2.begin(), vector2.end()),
            vector2.end()
    );

    if (std::includes(
            vector1.begin(), vector1.end(),
            vector2.begin(), vector2.end()
    )) {
        return true;
    } else {
        return false;
    }

    /*
     * std::includes
     * Returns true if the sorted range [first1, last1) contains all the elements in the sorted range [first2, last2),
     * false otherwise
     *
     * std::unique_copy
     * Returns an iterator pointing to the end of the copied range, which contains no consecutive duplicates
     *
     * auto beginning_of_removal_vec1 = std::unique_copy(vector1.begin(), vector1.end(), vector1.begin());
     * totalnie nie rozumiem dlaczego potrzebny jest trzeci argument i nie rozumiem do końca dlaczego to działa tak,
     * jak jest.
     * -> Copies each element in the range [__first,__last) to the range beginning at __result,
     * czyli wychodzi na to, że "nadpisuję" oryginalny wektor wektorem "poprawionym", już bez powtórzonych elementów?
     * Spróbuj to potem ugryźć std::unique
     *
     * std::unique
     * Returns an iterator to the element that follows the last element not removed.
     * The range between first and this iterator includes all the elements in the sequence that were not considered
     * duplicates.
     */
}

auto exchange_boundaries(std::vector<int> vector) {      //nie wolno wprowadzać żadnych dodatkowych zmiennych
    std::swap(
            *std::minmax_element(vector.begin(), vector.end()).first,
            *std::minmax_element(vector.begin(), vector.end()).second
//            *std::min_element(vector.begin(), vector.end()),
//            *std::max_element(vector.begin(), vector.end())
    );
    return vector;

    /*
     *std::minmax_element return smallest and largest elements in range
     * Returns a pair with an iterator pointing to the element with the smallest value in the range [first, last)
     * as a "first" element, and the largest as "second"
     *
     * std::min_element return smallest element in range
     * std::max_element return largest element in range
     *
     * Oba rozwiązania dają ten sam rezultat
     */
}

auto copy_by_pushing(std::vector<int> vector, int amount_of_elements_to_copy, int shift) {

    std::copy_n(
            vector.begin(),
            amount_of_elements_to_copy,
            vector.begin() + shift
    );
    return vector;

    /*
     * std::copy_n
     * Copies the first n elements from the range beginning at first into the range beginning at result.
     * The function returns an iterator to the end of the destination range (which points to one past the last element
     * copied).
     */
}

auto translate_to_Kwiatkovsky(std::string str) {

    std::replace(str.begin(), str.end(), 'R', 'L');
    std::replace(str.begin(), str.end(), 'r', 'l');

    return str;

    /*
     * std::replace
     * Assigns new_value to all the elements in the range [first,last) that compare equal to old_value.
     */
}

int main() {

    //Zadanie 1

    auto word1 = std::string("Ala ma kota, ale nie ma psa");
    auto word2 = std::string("Ala");
    auto word3 = std::string("ala");
    auto word4 = std::string("Al");
    auto word5 = std::string("ma");
    auto word6 = std::string("m");
    auto word7 = std::string("psa");
    auto word8 = std::string("ps");

    std::cout << contains_needle(word1, word2) << "\n";
    std::cout << contains_needle(word1, word3) << "\n";
    std::cout << contains_needle(word1, word4) << "\n";
    std::cout << contains_needle(word1, word5) << "\n";
    std::cout << contains_needle(word1, word6) << "\n";
    std::cout << contains_needle(word1, word7) << "\n";
    std::cout << contains_needle(word1, word8) << "\n";

    /*
     * word4, word6 i word8 znajdują się w word1, jednak są to jedynie "części wyrazu", a nie "osobne wyrazy"
     * czy w związku z tym takie rozwiązanie jest ok?
     *
     * Funkcja zwróci true, gdy word2 będzie substringiem(!) s1 (i oba będą typu std::string)
     */

    //Zadanie 2
    std::cout << "\n";

    auto vector1 = std::vector<int>{8, 1, 2, 6, 3, 9, 3, 4, 5, 6, 6, 6, 7, 8, 9, 10, 6, 4, 11, 12, 75, 100};
    auto vector2 = std::vector<int>{1, 2, 2, 3, 9, 4, 5, 6, 7, 7, 8, 12, 7, 99};
    std::cout << contains_all(vector1, vector2);

    //Zadanie 3
    std::cout << "\n\n";

    auto changed_vector = exchange_boundaries(vector1);
    for (auto vec : vector1) {
        std::cout << vec << " ";
    }
    std::cout << "\n";
    for (auto vec : changed_vector) {
        std::cout << vec << " ";
    }

    //Zadanie 4
    std::cout << "\n\n";

    auto result = copy_by_pushing({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 3, 5);
    auto result2 = copy_by_pushing({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5, 2);

    for (auto vec : result) {
        std::cout << vec << " ";
    }
    std::cout << "\n";
    for (auto vec : result2) {
        std::cout << vec << " ";
    }

    //Zadanie 5
    std::cout << "\n\n";

    auto str = std::string("Rabarbar");
    std::cout << translate_to_Kwiatkovsky(str) << "\n";

    auto str2 = std::string("Strings are objects that represent sequences of characters.");
    std::cout << translate_to_Kwiatkovsky(str2) << "\n";

    return 0;
}
