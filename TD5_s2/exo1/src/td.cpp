#include <iostream>
#include <string>
using namespace std;

size_t folding_string_hash(const std::string& s, size_t max) {
    size_t hash = 0;
    for (char c : s) {
        hash += static_cast<size_t>(c);
    }
    return hash % max;
}

size_t folding_string_ordered_hash(const std::string& s, size_t max) {
    size_t hash = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        hash += static_cast<size_t>(s[i]) * (i + 1); // pour ne pas avoir *0
    }
    return hash % max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m) {
    size_t hash = 0;
    size_t power = 1; 
    for (char c : s) {
        hash = (hash + static_cast<size_t>(c) * power) % m;
        power = (power * p) % m; 
    }
    return hash;
}

int main() {
    string input = "Mushokutensei";
    size_t max = 1024;
    size_t p = 31;
    size_t m = 1024;

    size_t hash1 = folding_string_hash(input, max);
    size_t hash2 = folding_string_ordered_hash(input, max);
    size_t hash3 = polynomial_rolling_hash(input, p, m);
    std::cout << "Le Folding Hash: " << hash1 << std::endl;
    std::cout << "L'Ordered Folding Hash: " << hash2 << std::endl;
    std::cout << "Le Hash : " << hash3 << std::endl;

    return 0;
}
