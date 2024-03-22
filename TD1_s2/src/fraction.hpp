#pragma once

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    void display();
    //exo5 apres correction
    Fraction& operator-=(Fraction const& f);
    Fraction& operator+=(Fraction const& f);
    Fraction& operator*=(Fraction const& f);
    Fraction& operator/=(Fraction const& f);
    float to_float();
    operator float();
};

Fraction add(Fraction const& f1, Fraction const& f2);
Fraction sub(Fraction const& f1, Fraction const& f2);
Fraction mul(Fraction const& f1, Fraction const& f2);
Fraction div(Fraction const& f1, Fraction const& f2);