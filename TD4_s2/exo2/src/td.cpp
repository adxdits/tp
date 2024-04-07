#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

auto const is_space = [](char letter){ return letter == ' '; };

int count_letters_first_word(const std::string& phrase) {
    auto first_letter = std::find_if_not(phrase.begin(), phrase.end(), is_space);
    auto space_after_first_word = std::find(first_letter, phrase.end(), ' ');
    return std::distance(first_letter, space_after_first_word);
}

std::vector<std::string> split_string(const std::string& str) {
    std::vector<std::string> words;
    auto start = str.begin();
    while (start != str.end()) {
        auto end = std::find_if(start, str.end(), is_space);
        words.push_back(std::string(start, end));
        start = std::find_if_not(end, str.end(), is_space);
    }
    return words;
}

int main() {
    std::string phrase = "solo leveling ";
    
    std::cout << "Nb dr premier mot : " << count_letters_first_word(phrase) << std::endl;

    std::vector<std::string> mots = split_string(phrase);
    std::cout << "Les mots de la phrase : ";
    for (const auto& mot : mots) {
        std::cout << mot << " ";
    }
    std::cout << std::endl;

    return 0;
}