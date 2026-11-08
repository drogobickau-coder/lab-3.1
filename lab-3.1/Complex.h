#pragma once
#include "Pair.h"

// Відкрите успадкування від Pair
class Complex : public Pair {
public:
    Complex();
    Complex(double r, double i);
    Complex(const Pair& p);
    Complex(const Complex& other);

    Complex& operator=(const Complex& other);
    operator string() const;

    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);

    // Дружні функції: віднімання, множення, ввід, вивід
    friend Complex operator*(const Complex& c1, const Complex& c2);
    friend Complex operator-(const Complex& c1, const Complex& c2);
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};