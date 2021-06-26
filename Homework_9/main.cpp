#include <iostream>
#include <algorithm>

#include "student.hpp"
#include "operations.hpp"


auto fill_range(const std::vector<int>& vec, int beginning_value, int increment_value){
    auto new_vec = std::vector<int>();
    new_vec.push_back(beginning_value);

    int i = 0;
    std::generate_n(std::back_inserter(new_vec), vec.size() - 1,
                    [beginning_value, increment_value, &i](){
        i++;
        return beginning_value + increment_value * i;
    });

//    for(int i = 1; i < new_vec.size(); i++){
//        new_vec[i] = new_vec[i - 1] + increment_value;
//    }

/*    std::transform(
            new_vec.begin(), new_vec.end(),
            new_vec.begin(), new_vec.begin() + 1,
            [increment_value, new_vec](int left, int right){
                return left + increment_value;
            }
            );


    /*    index:0 1 2 3 4
     *          3 0 0 0 0   left i right wskazują na ten sam indeks tego samego vectora
     *          3 0 0 0 0   w "pierwszym korku" na 3 na indexie 0
     *          ^   |
     *              v       dodawany jest left/right (wszystko jedno - to i tak "to samo") i increment_value
     *          3 9 0 0 0   i wynik zapisywany jest na indexie 1 (!)
     *          3 9 0 0 0
     *            ^ |       teraz dodawana jest 9 + increment_value a wynik zapisywany jest na następnym indexie (2)
     *              v
     *          3 9 15 0 0
     *          3 9 15 0 0   itd...
     *              ...
     *
     *              Undefined Behaviour jednak
     */


    return new_vec;
}

int main() {

    auto s1 = models::student("Filip", "Kwiatek", 23);
    auto s2 = models::student();

    std::cout << s1.getName() << " " << s1.getSurname() << " " << s1.getAge() <<'\n';
    std::cout << s2.getName() << " " << s2.getSurname() << " " << s2.getAge() <<'\n';

    set_all(s1, "Dziki", "Golomp", 420);
    std::cout << s1.getName() << " " << s1.getSurname() << " " << s1.getAge() << '\n';

    std::cout << models::predicates::is_adult(s1) << '\n';

    set_all(s2, "Michael", "Tomaszewsky", 850);
    models::mappers::virgin_to_string(s2);

    auto vec = std::vector<int> {1, 2, 3, 4, 5};
    auto new_vec = fill_range(vec, 3, 6);

    for(auto element : new_vec){
        std::cout << element << " ";
    }

    return 0;
}
