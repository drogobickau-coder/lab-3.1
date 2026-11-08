#include <iostream>
#include <windows.h>
#include "Pair.h"
#include "Complex.h"
#pragma execution_character_set("utf-8")


using namespace std;

#pragma pack(push, 1)
class ComplexPacked : public Pair {
};
#pragma pack(pop)

// Функція для демонстрації принципу підстановки (отримує і повертає базовий клас)
Pair substitutionFunction(Pair p) {
    cout << "Функція отримала об'єкт (принцип підстановки): " << p << endl;
    return p;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    {
        setlocale(LC_ALL, "uk_UA.UTF-8");
    }


    cout << "Розмір класу Complex без #pragma pack(1): " << sizeof(Complex) << " байт" << endl;
    cout << "Розмір класу Complex з #pragma pack(1): " << sizeof(ComplexPacked) << " байт\n" << endl;

    cout << "--- 1. Демонстрація базового класу Pair ---" << endl;
    Pair p1, p2;

    cout << "Ініціалізація першої пари:" << endl;
    cin >> p1;
    cout << "Ініціалізація другої пари:" << endl;
    cin >> p2;

    cout << "\nПара 1: " << p1 << endl;
    cout << "Пара 2: " << p2 << endl;

    cout << "Добуток полів першої пари: " << p1.multiplyFields() << endl;

    Pair p3 = p1 + p2;
    cout << "Сума пар (a+c, b+d): " << p3 << endl;

    cout << "\nДемонстрація інкременту/декременту Pair:" << endl;
    cout << "++p1 (префіксна): " << ++p1 << endl;
    cout << "p1++ (постфіксна): " << p1++ << " -> тепер: " << p1 << endl;

    cout << "\n--- 2. Демонстрація похідного класу Complex ---" << endl;

    Complex c1(1.5, -2.5);
    Complex c2;

    cout << "Ініціалізація другого комплексного числа:" << endl;
    cin >> c2;

    cout << "\nC1: " << c1 << endl;
    cout << "C2: " << c2 << endl;

    Complex c3 = c1 - c2;
    cout << "Різниця (C1 - C2): " << c3 << endl;

    Complex c4 = c1 * c2;
    cout << "Добуток (C1 * C2): " << c4 << endl;

    cout << "\n--- 3. Демонстрація масиву об'єктів Complex ---" << endl;

    Complex arr[2] = { Complex(1.0, 2.0), Complex(3.0, 4.0) };

    for (int i = 0; i < 2; i++) {
        cout << "Елемент масиву [" << i << "]: " << arr[i] << endl;
    }

    cout << "\n--- 4. Демонстрація принципу підстановки ---" << endl;
    // Передаємо об'єкт похідного класу (Complex) туди, де очікується базовий (Pair)
    Pair result = substitutionFunction(c1);

    return 0;
}