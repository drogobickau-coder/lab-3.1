#include "Pair.h"
#include <sstream>
#pragma execution_character_set("utf-8")


Pair::Pair() {
    setFirst(0.0);
    setSecond(0.0);
}

Pair::Pair(double f, double s) {
    setFirst(f);
    setSecond(s);
}

Pair::Pair(const Pair& other) {
    setFirst(other.getFirst());
    setSecond(other.getSecond());
}

double Pair::multiplyFields() const {
    return first * second;
}

Pair& Pair::operator=(const Pair& other) {
    if (this != &other) {
        setFirst(other.getFirst());
        setSecond(other.getSecond());
    }
    return *this;
}

Pair::operator string() const {
    stringstream sout;
    sout << "(" << first << ", " << second << ")";
    return sout.str();
}

Pair& Pair::operator++() {
    ++first;
    return *this;
}

Pair Pair::operator++(int) {
    Pair temp(*this);
    second++;
    return temp;
}

Pair& Pair::operator--() {
    --first;
    return *this;
}

Pair Pair::operator--(int) {
    Pair temp(*this);
    second--;
    return temp;
}

Pair operator+(const Pair& p1, const Pair& p2) {
    return Pair(p1.getFirst() + p2.getFirst(), p1.getSecond() + p2.getSecond());
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << string(p);
    return out;
}

istream& operator>>(istream& in, Pair& p) {
    double f, s;
    cout << "first = ? "; in >> f;
    cout << "second = ? "; in >> s;
    p.setFirst(f);
    p.setSecond(s);
    return in;
}