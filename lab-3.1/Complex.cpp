#include "Complex.h"
#include <sstream>
#pragma execution_character_set("utf-8")


// Виклик конструкторів базового класу
Complex::Complex() : Pair(0.0, 0.0) {}

Complex::Complex(double r, double i) : Pair(r, i) {}

Complex::Complex(const Pair& p) : Pair(p) {}

Complex::Complex(const Complex& other) : Pair(other) {}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        Pair::operator=(other); // Виклик базової операції присвоєння
    }
    return *this;
}

Complex::operator string() const {
    stringstream sout;
    sout << "Z = " << Pair::operator string(); // Виклик базового перетворення
    return sout.str();
}

Complex& Complex::operator++() {
    Pair::operator++();
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    Pair::operator++(0);
    return temp;
}

Complex& Complex::operator--() {
    Pair::operator--();
    return *this;
}

Complex Complex::operator--(int) {
    Complex temp(*this);
    Pair::operator--(0);
    return temp;
}

// (a, b) × (c, d) = (ac - bd, ad + bc)
Complex operator*(const Complex& c1, const Complex& c2) {
    double a = c1.getFirst();
    double b = c1.getSecond();
    double c = c2.getFirst();
    double d = c2.getSecond();
    return Complex(a * c - b * d, a * d + b * c);
}

// (a, b) - (c, d) = (a - c, b - d)
Complex operator-(const Complex& c1, const Complex& c2) {
    double a = c1.getFirst();
    double b = c1.getSecond();
    double c = c2.getFirst();
    double d = c2.getSecond();
    return Complex(a - c, b - d);
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << string(c);
    return out;
}

istream& operator>>(istream& in, Complex& c) {
    double r, i;
    cout << "Введіть складові комплексного числа:" << endl;
    cout << "Дійсна частина = ? "; in >> r;
    cout << "Уявна частина = ? "; in >> i;
    c.setFirst(r);
    c.setSecond(i);
    return in;
}