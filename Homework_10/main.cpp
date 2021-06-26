#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <ostream>
#include <algorithm>

auto lines_with_words_containing_most(const std::string &file_path, const char &sign_to_find) {

    auto file = std::ifstream(file_path);
    auto lines_vector = std::vector<std::string>();
    auto amount_of_words_which_meet_the_condition = std::vector<int>();

    for (auto line = std::string(); std::getline(file, line);) {
        lines_vector.push_back(line);

        std::istringstream ss(line);
        std::string word;
        auto one_line_words_vector = std::vector<std::string>();

        while (ss >> word) {
            one_line_words_vector.push_back(word);
        }

        amount_of_words_which_meet_the_condition.push_back(
                std::count_if(
                        one_line_words_vector.begin(), one_line_words_vector.end(),
                        [sign_to_find](const std::string &word) {
                            return word.find(sign_to_find) != std::string::npos;
                        }
                )
        );
    }

    auto max_condition = std::max_element(
            amount_of_words_which_meet_the_condition.begin(),
            amount_of_words_which_meet_the_condition.end()
    );

    std::vector<std::string> lines_to_return;

    for (int i = 0; i < lines_vector.size(); i++) {
        if (amount_of_words_which_meet_the_condition[i] == *max_condition) {
            lines_to_return.push_back(lines_vector[i]);
        }
    }

    return lines_to_return;
}

struct eof_exception : std::logic_error {

    eof_exception(const char *text) : logic_error(text) {}

};

struct filtered_stream {
private:
    std::string word_to_ignore;
    std::vector<char> vector_of_chars_to_ignore;


public:
    filtered_stream(const std::string &word) : word_to_ignore(word) {
        std::copy(word.begin(), word.end(), std::back_inserter(vector_of_chars_to_ignore));
    }

    filtered_stream(const std::vector<char> &vectorOfChars) : vector_of_chars_to_ignore(vectorOfChars) {}


    auto extract_from(std::istream &file) {
        /*auto lines_vector = std::vector<std::string>();
        auto one_line_words_vector = std::vector<std::string>();

        for (auto line = std::string(); std::getline(file, line);) {
            lines_vector.push_back(line);

            std::istringstream ss(line);
            std::string string;

            while (ss >> string) {
                one_line_words_vector.push_back(string);
            }
        }

        for(const auto& element : one_line_words_vector){
            std::cout << '[' << element <<"] \n";
        }
        //z każdego słowa trzeba usunąć chary_to_ignore, a potem to co zostanie podzielić na chary i zwrócić
*/
        /*std::for_each(
                std::istream_iterator<char>(file),
                std::istream_iterator<char>(),
                [this](const char &sign) {
                    std::vector<char>::iterator it;
                    it = std::find(
                            vector_of_chars_to_ignore.begin(),
                            vector_of_chars_to_ignore.end(),
                            sign
                    );
                    return it == vector_of_chars_to_ignore.end();   //not found
//                    if(it == vector_of_chars_to_ignore.end()){
//                        return sign;
//                        //std::cout << sign << "\n";
//                    }
                }
        );*/

        char c;
        while (file.get(c)) {

            if (isspace(c))
                continue;

            auto it = std::find(
                    vector_of_chars_to_ignore.begin(),
                    vector_of_chars_to_ignore.end(),
                    c
            );

            if (it == vector_of_chars_to_ignore.end()) {  //not found
                return c;
            }
        }
        return c;
    }
    //https://stackoverflow.com/questions/38595834/compilation-error-this-cannot-be-implicitly-captured-in-this-context
    //https://www.cplusplus.com/reference/istream/istream/get/

    auto extract_word_from(std::istream &file) {
/*        std::string line;
        while (getline(file, line)) {

            std::istringstream ss(line);
            std::string word;

            while (ss >> word) {

                for (const char &char_to_remove : vector_of_chars_to_ignore) {
                    word.erase(
                            std::remove(
                                    word.begin(), word.end(), char_to_remove
                            ), word.end()
                    );
                }
                return word;
            }
        }
        return std::string();
*/
        auto word = std::string();
        file >> word;

        for (const char &char_to_remove : vector_of_chars_to_ignore) {
            word.erase(
                    std::remove(
                            word.begin(), word.end(), char_to_remove
                    ), word.end()
            );
        }
        return word;
    }

    auto extract_line_from(std::istream &file) {

        std::string line;

        while (getline(file, line)) {

            if (line.empty()) {
                continue;
            }

            for (const char &char_to_remove : vector_of_chars_to_ignore) {
                line.erase(
                        std::remove(
                                line.begin(), line.end(), char_to_remove
                        ), line.end()
                );
            }
            return line;
        }
        return std::string();
    }

};

int main() {

    auto ex1 = lines_with_words_containing_most("myfile.txt", 'a');
    for(const auto& element: ex1){
        std::cout << element << "\n";
    }

    auto eof = eof_exception("End of file\n");
    try {
        throw eof;
    } catch (const eof_exception &ex) {
        std::cout << ex.what();
    }

    auto fs = filtered_stream("Beztr ");
    try {
        auto file = std::ifstream("myfile.txt");

        std::cout << fs.extract_from(file) << "\n";
        std::cout << fs.extract_from(file) << "\n";
        std::cout << fs.extract_word_from(file) << "\n";
        std::cout << fs.extract_word_from(file) << "\n";
        std::cout << fs.extract_word_from(file) << "\n";
        std::cout << fs.extract_line_from(file) << "\n";
        std::cout << fs.extract_line_from(file) << "\n";

    } catch (const eof_exception &ex) {
        std::cout << ex.what();
    }
}

/*
 *         std::cout << std::count_if(                                 //wykorzystaj to w projekcie
                std::istream_iterator<char>(file),
                std::istream_iterator<char>(),
                        [](const char& sign){
                    return sign == 'a';
                }
                );
 */