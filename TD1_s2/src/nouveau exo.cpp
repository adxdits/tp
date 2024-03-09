#pragma once
#include "utils.hpp"
#include "fraction.hpp"
#include <iostream>

//exo1

Fraction operator+(Fraction const& a, Fraction const& b) {
    return simplify({a.numerator * b.denominator + b.numerator * a.denominator,
        a.denominator * b.denominator});
}

Fraction operator*(Fraction const& a, Fraction const& b) {
    return simplify({a.numerator * b.numerator,
            a.denominator * b.denominator});
        }
     
Fraction operator-(Fraction const& f1, Fraction const& f2){
    return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction operator/(Fraction const& f1, Fraction const& f2){
    return simplify({f1.numerator * f2.denominator,
                     f1.denominator * f2.numerator});
}

//exo2
 
std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

//exo3
bool operator==(Fraction const& f1, Fraction const& f2){
    Fraction simp1 = simplify(f1);
    Fraction simp2 = simplify(f2);

    return simp1.numerator == simp2.numerator && simp1.denominator == simp2.denominator;
}  

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}


//exo4
bool operator<(Fraction const& f1, Fraction const& f2) {
    Fraction simp1 = simplify({f1.numerator * f2.denominator, f1.denominator * f2.denominator});
    Fraction simp2 = simplify({f2.numerator * f1.denominator, f2.denominator * f1.denominator});
    return simp1.numerator < simp2.numerator;
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return !(f2 < f1);
}

bool operator>(Fraction const& f1, Fraction const& f2) {
    return f2 < f1;
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return !(f1 < f2);
}

//exo5 
// dans struct de fraction
// Méthode add 
// Fraction& Fraction::operator+=(Fraction const &f)
// {
//     numerator = numerator * f.denominator + f.numerator * denominator;
//     denominator *= f.denominator;
//     return *this; // Renvoie une référence à l'objet modifié
// }

// // Méthode sub 
// Fraction& Fraction::operator-=(Fraction const &f)
// {
//     numerator = numerator * f.denominator - f.numerator * denominator;
//     denominator *= f.denominator;
//     return *this; // Renvoie une référence à l'objet modifié
// }

// // Méthode mul 
// Fraction& Fraction::operator*=(Fraction const &f)
// {
//     numerator *= f.numerator;
//     denominator *= f.denominator;
//     return *this; // Renvoie une référence à l'objet modifié
// }

// // Méthode div 
// Fraction& Fraction::operator/=(Fraction const &f)
// {
//     numerator *= f.denominator;
//     denominator *= f.numerator;
//     return *this; // Renvoie une référence à l'objet modifié
// }


//exo6
struct Fractionsix {
    int numerator;
    int denominator;

    Fractionsix(int num, int denom) : numerator(num), denominator(denom) {}

    float to_float() const {
        return static_cast<float>(numerator) / static_cast<float>(denominator);
    }

    operator float() const {
        return to_float();
    }
};

//exo6
//1)methode dans struct de fraction
// Fraction::operator float() const
// {
//     return static_cast<float>(numerator) / static_cast<float>(denominator);
// }

int main() {
    Fractionsix f1{1, 2};
    float d1 = static_cast<float>(f1); // conversion avec static_cast
    std::cout << "f1 en tan que float: " << d1 << std::endl;

    return 0;
}