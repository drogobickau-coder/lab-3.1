#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pair {
private:
    double first;
    double second;
public:
    Pair();
    Pair(double f, double s);
    Pair(const Pair& other);

    double getFirst() const { return first; }
    double getSecond() const { return second; }
    void setFirst(double f) { first = f; }
    void setSecond(double s) { second = s; }

    // Метод множення полів
    double multiplyFields() const;

    Pair& operator=(const Pair& other);
    operator string() const;

    Pair& operator++();
    Pair operator++(int);
    Pair& operator--();
    Pair operator--(int);

    friend Pair operator+(const Pair& p1, const Pair& p2);
    friend ostream& operator<<(ostream& out, const Pair& p);
    friend istream& operator>>(istream& in, Pair& p);
};