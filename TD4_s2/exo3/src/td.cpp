#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string& str) {
    return std::equal(str.begin(), str.end(), str.rbegin(), str.rend());
}

int main() {
    std::string mot1 = "shrodinger";

    if (is_palindrome(mot1)) {
        std::cout << " est un palindrome." << std::endl;
    } else {
        std::cout << " n'est pas un palindrome." << std::endl;
    }

    return 0;
}
