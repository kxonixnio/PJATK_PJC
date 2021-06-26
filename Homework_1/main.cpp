#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    //using namespace std;

    //zadanie 1

    std::cout << 123 + 321 <<std::endl;
    std::cout << (123 & 321) <<std::endl;
    std::cout << (123 | 321) <<std::endl;

    //Koniecznym było dodanie nawiasów, ponieważ "left shift" ma "pierwszeństwo" przed "&" i "|"
    //https://en.cppreference.com/w/cpp/language/operator_precedence

    //zadanie 2

    std::string word1, word2, word3;
    std::cin >> word1 >> word2 >> word3;

    if(word1 > word3){
        std::string temp = word1;
        word1 = word3;
        word3 = temp;
    }
    if(word1 > word2){
        std::string temp = word1;
        word1 = word2;
        word2 = temp;
    }
    if(word2 > word3){
        std::string temp = word2;
        word2 = word3;
        word3 = temp;
    }

    std::cout << word1 << " " << word2 << " " << word3 << "\n";

    //zadanie 3

    std::vector<int>numbers;
    std::vector<std::string>words;

    for(int input_number;
    std::cin >> input_number && input_number >= 0;
    numbers.push_back(input_number));

    for(std::string input;
    std::cin >> input && input != "exit";
    words.push_back(input));

    reverse(numbers.begin(), numbers.end());

    for(int number : numbers){
        std::cout << number << ' ';
    }
    std::cout << '\n';

    for(std::string word : words){
        std::cout << word << ' ';
    }

    return 0;
}
