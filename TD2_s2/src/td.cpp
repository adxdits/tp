
#include <iostream>
#include <vector>
#include <algorithm>
#include "ScopedTimer.hpp"
using namespace std;


//exo1

void bubbleSort(std::vector<int> vec) {
    size_t taille = vec.size();
    for (int j = 0; j < taille; j++)
    {
        for (int i = 0; i < taille - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                int temp = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = temp;
            }
        }
        }
        }

void selection_sort(std::vector<int> & tableau) {
    size_t n = tableau.size();
    for (int i = 0; i < n-1; i++) {
        int minindex = i;
        for (int j = i+1; j < n; j++) {
            if (tableau[j] < tableau[minindex]) {
                minindex = j;
            }
        }
        int temp = tableau[i];
        tableau[i] = tableau[minindex];
        tableau[minindex] = temp;
    }
}


//exo2
// debut du tri fusion
// void fusion(vector<int>a,vector<int>b){
//     for (int i = 0; i < a.size();i++){
//         a.push_back(b[i]);
//     }
//     }

// void trifusion(vector<float> & vec, size_t const left, size_t const middle, size_t const right){
    
// }

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right]; //dernier elementc
    int i = left - 1; // inderx du plus petit element

    for (int j = left; j <= right - 1; j++) {

        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return (i + 1);
}

void quicksort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);

        quicksort(arr, left, p - 1);
        quicksort(arr, p + 1, right);
    }
}


//exo 4 dichotomie 

int search(const std::vector<int>& table, int value) {
    int left = 0;
    int right = table.size() - 1;

    while (left <= right) {
        int milieu = (left + right) / 2;
        if (table[milieu] == value) {
            return milieu;
        }
        else if (table[milieu] < value) {
            left = milieu + 1;
        }
        else {
            right = milieu - 1;
        }
    }
    return -1;
}







int main() {
    std::vector<int> numbers = {64, 125, 12, 22, 11};
//essaie du quicksort
// std::vector<int> numbers = {64, 125, 12, 22, 11};
// quicksort(numbers, 0 , 4);
// for (int num : numbers)
// {
//     std::cout << num << " ";
//     }
//     std::cout << std::endl;

//essaie dichotomie
//  vector<int>tableau={1, 2, 3, 4, 5, 6, 7, 8, 9};
//     std::cout <<  search(tableau,10);


    {
        ScopedTimer timer("Selection Sort");
        selection_sort(numbers);
    }

    {
        ScopedTimer timer("Quick Sort");
        quicksort(numbers, 0, numbers.size() - 1);
    }
    {
        ScopedTimer timer("std::sort");
        std::sort(numbers.begin(), numbers.end());
    }

    return 0;
}

//exo3 resultat
// Selection Sort : 10.2us (0.0102ms)
// Quick Sort : 2.8us (0.0028ms)
// std::sort : 3.4us (0.0034ms)
//quicksort est le meilleur

