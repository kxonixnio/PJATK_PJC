#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <array>
#include <set>

auto show_ordered_character_occurrences(const std::string &word) {
    auto occurrences = std::map<char, int>();

    for (auto c : word) {
        occurrences[c] += 1;
    }

    auto vec_of_pair = std::vector<std::pair<char, int>>(occurrences.begin(), occurrences.end());

    std::sort(vec_of_pair.begin(), vec_of_pair.end(),
              [](const std::pair<char, int> &left, const std::pair<char, int> &right) {
                  return left.second > right.second;
              });

    for (const auto &pair : vec_of_pair) {
        std::cout << pair.first << ' ' << pair.second << '\n';
    }
}

auto has_balanced_brackets(
        const std::string &string_to_check,
        const std::map<char, char> &open_to_close_bracket_map,
        const std::map<char, char> &close_to_open_bracket_map
) {
    auto stack_for_brackets = std::stack<char>();

    for (const auto &sign : string_to_check) {
        //Check opening brackets
        if (open_to_close_bracket_map.find(sign)->first == sign) {
            stack_for_brackets.push(sign);
        }

        //Check closing brackets
        if (close_to_open_bracket_map.find(sign)->first == sign) {

            if (stack_for_brackets.empty()) {
                return false;
            }

            if (stack_for_brackets.top() != close_to_open_bracket_map.find(sign)->second) {
                return false;
            } else {
                stack_for_brackets.pop();
            }

        }
    }

    if (!stack_for_brackets.empty()) {
        return false;
    }

    return true;
}

enum class action {
    move_left, move_right, idle
};

auto chunk(std::vector<action> vec) {

    auto the_rest_of_the_division = vec.size() % 3;
    if (the_rest_of_the_division == 1) {
        vec.push_back(action::idle);
        vec.push_back(action::idle);
    }
    if (the_rest_of_the_division == 2) {
        vec.push_back(action::idle);
    }

    auto arrays = std::vector<std::array<action, 3>>();
    for (int i = 0; i < vec.size(); i += 3) {
        arrays.push_back({vec[i], vec[i + 1], vec[i + 2]});
    }

    return arrays;
}

auto effectively_idle(const std::vector<std::array<action, 3>> &gimme_some_chunk_function) {

    for (auto array : gimme_some_chunk_function) {
        auto set = std::set<action>(array.begin(), array.end());
        if (set.size() != array.size()) {
            if (set.size() == 2) {
                return false;
            } else if (set.size() == 1) {
                if (set.find(action::idle) == set.end()) {
                    return false;
                }
            }
        }
    }

    return true;

    /*
     * Ka??d?? partycj?? (tablic?? 3-elementow??) zmieniamy na seta. Je??eli size seta r????ni si?? od pierwotnej tablicy tzn,
     * ??e jaki?? element si?? powt??rzy??. Jedynym scenariuszem "z powt??rzeniami" w partycji, kt??ry mo??e spe??nia?? warunki
     * zadania jest ten, gdzie "idle" powtarza si?? dok??adnie 3 razy. Dlatego w przypadku set.size() == 2 rzucamy false,
     * a w przypadku set.size() == 1 sprawdzamy, czy to akurat "idle" powt??rzy??o si?? trzykrotnie
     */
}

int main() {

    show_ordered_character_occurrences("ala ma kooota eeeee");

    auto open_to_close_bracket_map = std::map<char, char>{
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
            {'<', '>'}
    };

    auto close_to_open_bracket_map = std::map<char, char>{
            {')', '('},
            {']', '['},
            {'}', '{'},
            {'>', '<'}
    };

    std::cout << has_balanced_brackets(
            "aaaa{{[[asx((a<>s))]as]}saa}",
            open_to_close_bracket_map,
            close_to_open_bracket_map) << '\n';

    std::cout << has_balanced_brackets(
            "{[(])}",
            open_to_close_bracket_map,
            close_to_open_bracket_map) << '\n';

    std::cout << effectively_idle(chunk(
            std::vector<action>{
                    action::move_left, action::move_right, action::idle,
                    action::move_right, action::idle, action::move_left,
                    action::idle, action::move_left, action::move_right,
                    action::idle, action::idle, action::idle,
                    action::move_right, action::move_left}
    ));

    std::cout << "\ntest: " << effectively_idle(chunk(
            std::vector<action>{
                    action::move_left, action::move_right, action::idle,
                    action::idle, action::move_right}
    ));
}
