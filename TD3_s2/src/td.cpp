#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
using namespace std;

//ne pas corriger maintenant sv^^ je nai pas terminer 
//EXERCICE 2
auto const is_space = [](char letter){ return letter == ' '; };

int main() {
    vector<int> numbers{ 10, 20, 30, 40 };

//EXERCICE 1

    // Remplir le vecteur avec des nombres aléatoires
    for (int i = 0; i < 10; i++) { 
        numbers.push_back(rand()%1000);
    }

    // Afficher les valeurs du vecteur à l'aide des itérateurs et de la méthode begin et end
    cout << "Valeurs du vecteur :" << std::endl;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    cout << std::endl;

    // Find
    int input;
    std::cout << "Entrez un nombre à rechercher dans le vecteur : ";
    std::cin >> input;
      auto it = find(numbers.begin(), numbers.end(), input);
      if (it != numbers.end())
      {
          cout << *it << endl;
      }
      else {
         cout << "Element not found" << std::endl;
      }
    // count
      int r;
      cin >> r;
      int counts = count(numbers.begin(), numbers.end(), r);
       cout << "number:" << input << endl;
         cout << "count:" <<  counts << endl;


      // sorting
        sort(numbers.begin(), numbers.end());

    //accumulate
    int som = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Somme des éléments du vecteur : " << som << std::endl;


         return 0;
        
}
