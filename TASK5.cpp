#include <iostream>

using namespace std;

// Этап 1: Определение структуры для хранения дроби
struct Fraction
{
    int numerator;   // Числитель
    int denominator; // Знаменатель
};

int main()
{
    // Этап 2: Объявление переменных для хранения дробей и суммы
    Fraction f1, f2, sum;

    // Этап 3: Ввод первой дроби
    cout << "Enter the first fraction (in the format a/b): ";
    char slash; // Символ '/' для разделения числителя и знаменателя
    cin >> f1.numerator >> slash >> f1.denominator;

    // Этап 4: Ввод второй дроби
    cout << "Enter the second fraction (in the format c/d): ";
    cin >> f2.numerator >> slash >> f2.denominator;

    // Этап 5: Сложение дробей
    // Формула: (a/b) + (c/d) = (a * d + b * c) / (b * d)
    sum.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    sum.denominator = f1.denominator * f2.denominator;

    // Этап 6: Вывод результата с разделением через '/'
    cout << "The sum is: " << sum.numerator << "/" << sum.denominator << endl;

    return 0; // Завершаем программу
}
