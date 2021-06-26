#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

template<typename T, typename V>
auto contains_all(T firstContainer, V secondContainer) {
    std::sort(firstContainer.begin(), firstContainer.end());
    std::sort(secondContainer.begin(), secondContainer.end());

    if (
            std::includes(
                    firstContainer.begin(), firstContainer.end(),
                    secondContainer.begin(), secondContainer.end()
            )
            ) {
        return true;
    } else {
        return false;
    }
}

template<typename T, typename V>
auto contains_all(T firstContainer, std::set<V> secondContainer) {
    std::sort(firstContainer.begin(), firstContainer.end());
//    std::sort(secondContainer.begin(), secondContainer.end());

    if (
            std::includes(
                    firstContainer.begin(), firstContainer.end(),
                    secondContainer.begin(), secondContainer.end()
            )
            ) {
        return true;
    } else {
        return false;
    }
}

template<typename T, typename V>
auto contains_all(std::set<T> firstContainer, V secondContainer) {
//    std::sort(firstContainer.begin(), firstContainer.end());
    std::sort(secondContainer.begin(), secondContainer.end());

    if (
            std::includes(
                    firstContainer.begin(), firstContainer.end(),
                    secondContainer.begin(), secondContainer.end()
            )
            ) {
        return true;
    } else {
        return false;
    }
}

namespace pjc{

    template<typename T, typename V>
    auto swap(T& firstValueToSwap, V& secondValueToSwap){
        std::swap(firstValueToSwap, secondValueToSwap);
    }

}

template <typename T>
struct container_wrapper : std::vector<T> {
//    std::vector<T> container;

    template<typename C>
    auto add_all(const C& cont){

        for (const auto& item : cont) {
            this->push_back(item);              //push_back(item); -> IDE podpowiedziało użycie this->
        }

    }

    template<typename C>
    auto remove_all(const C& cont){

        for (const auto &element_to_remove : cont) {
            this->erase(
                    std::remove(
                            this->begin(), this->end(), element_to_remove
                    ), this->end()
            );
        }

    }

    /*
     *     template<typename C>
    auto remove_all(const C& cont){

        for (const auto &element_to_remove : cont) {
            container.erase(
                    std::remove(
                            container.begin(), container.end(), element_to_remove
                    ), container.end()
            );
        }

    }
     */

    template <template<typename> class H>
    auto to(){
        auto new_container = H<T>(this->begin(), this->end());

//        for(int i = 0; i < this->size(); i++){
//            new_container.insert(this->at(i));
//        }

//        std::copy(
//                this->begin(), this->end(),
//                std::back_inserter(new_container)
//                );

        return new_container;
    }

};


int main() {

    auto vec = std::vector{5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    auto set = std::set{40, 30, 20, 10};
    std::cout << contains_all(vec, set) <<"\n";

    auto x = 37;
    auto y = 13;
    std::cout << x << y << "\n";
    pjc::swap(x, y);
    std::cout << x << y << "\n";

    auto ex3 = container_wrapper<int>();
    auto vec_to_add = std::vector<int>{1, 2, 3, 4, 5};
    ex3.push_back(50);
    ex3.add_all(vec_to_add);
    ex3.add_all(std::set{9, 8, 7, 6});
    ex3.remove_all(std::vector{3, 2, 1});
    ex3.remove_all(std::set{7, 6});

    for(const auto& element : ex3){
        std::cout << element << " ";
    }

    std::cout<<'\n';

    auto ints = container_wrapper<int>();
    ints.push_back(50);
    ints.insert(ints.begin(), 5);
    ints.add_all(std::vector<int>{20, 55, 45, 35, 30});
    ints.push_back(25);
    ints.insert(ints.begin(), 10);
    ints.insert(ints.begin() + 2, 40);
    ints.push_back(15);
    ints.pop_back();
    ints.push_back(15);
    for (const auto& item : ints) {
        std::cout << item << ' ';
    }
    std::cout << '\n';

    for (const auto& item : ints.to<std::set>()) {      //tu skończyłeś - trzeba dojść do tego jak to skompilować
        std::cout << item << ' ';
    }

}
