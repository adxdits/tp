#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>   
#include <cstdlib>   
#include <ctime>     

int main() {
    std::srand(55); 
    std::vector<int> v;

    for (int i = 0; i < 100; ++i) {
        v.push_back(std::rand() % 100 + 1);
    }
    std::cout << "Valeur du vect : ";
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    int numberToFind;
    std::cout << "Entre un nombre a rechercher dans le vect : ";
    std::cin >> numberToFind;

    auto found = std::find(v.begin(), v.end(), numberToFind);
    if (found != v.end()) {
        std::cout << "Le nombre " << numberToFind << " est present." << std::endl;
    } else {
        std::cout << "Le nombre " << numberToFind << " n'est pas " << std::endl;
    }

    int count = std::count(v.begin(), v.end(), numberToFind);
    std::cout << "Nombre d'occurrences de " << numberToFind << " dans le vecteur : " << count << std::endl;

    std::sort(v.begin(), v.end());

   
    std::cout << "Valeurs du vecteur après le tri : ";
    for (int &num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "Somme des éléments du vecteur : " << sum << std::endl;

    return 0;
}