#include <iostream>
#include <vector>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "object_storing_chars.hpp"
#include "string_collector.hpp"
#include "reverse_string_collector.hpp"
#include "vector_collector.hpp"
#include "reverse_vector_collector.hpp"

int main() {

    auto r1 = rectangle(10.0, 10.0);
    std::cout << r1.get_area() <<"\n";

    auto c1 = circle(5.0);
    std::cout << c1.get_perimeter() << "\n";

    auto t1 = triangle(5, 10);
    std::cout << t1.get_perimeter() << "\n";

    const auto r2 = rectangle(10.0, 10.0);
    std::cout << r2.get_area() << "\n";

    print_shape_info(r1);
    print_shape_info(c1);
    print_shape_info(t1);
    print_shape_info(r2);

    {
        auto vector = std::vector<char>{
            'a', '-', 'l', '-', '-', 'a', '-',
            ' ', '-',
            'm', 'a',
            '-', ' ', '-',
            '-', 'k', '-', '-', 'o', 't', '-', 'a', '-', '-'
        };

        auto str_collector = string_collector();
        filter_hyphens_from(vector).collect_using(str_collector);
        std::cout << '\n' << str_collector.representation() << '\n';
    }

    {
        auto vector = std::vector<char>{
                'a', '-', 'l', '-', '-', 'a', '-',
                ' ', '-',
                'm', 'a',
                '-', ' ', '-',
                '-', 'k', '-', '-', 'o', 't', '-', 'a', '-', '-'
        };
        auto str_collector = reverse_string_collector(); // inny kolektor
        filter_hyphens_from(vector).collect_using(str_collector);
        std::cout << '\n' << str_collector.representation() << '\n';

    }

    {
        auto vector = std::vector<char>{
                'a', '-', 'l', '-', '-', 'a', '-',
                ' ', '-',
                'm', 'a',
                '-', ' ', '-',
                '-', 'k', '-', '-', 'o', 't', '-', 'a', '-', '-'
        };
        auto vec_collector = vector_collector(); // inny kolektor
        filter_hyphens_from(vector).collect_using(vec_collector);
        for (const auto& item : vec_collector.representation()) {
            std::cout << item;
        }
    }
    std::cout <<'\n';
    {
        auto vector = std::vector<char>{
                'a', '-', 'l', '-', '-', 'a', '-',
                ' ', '-',
                'm', 'a',
                '-', ' ', '-',
                '-', 'k', '-', '-', 'o', 't', '-', 'a', '-', '-'
        };
        auto vec_collector = reverse_vector_collector(); // inny kolektor
        filter_hyphens_from(vector).collect_using(vec_collector);
        for (const auto& item : vec_collector.representation()) {
            std::cout << item;
        }
    }


    return 0;
}
