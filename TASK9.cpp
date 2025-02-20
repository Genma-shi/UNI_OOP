#include <iostream>
#include <cstdlib>  // Для использования abs()

using namespace std;

// Структура для хранения дробей
struct Fraction {
    int numerator;   // Числитель
    int denominator; // Знаменатель
};

// Функция для вычисления НОД (наибольший общий делитель)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция для упрощения дроби
void simplify(Fraction& frac) {
    int commonDivisor = gcd(abs(frac.numerator), abs(frac.denominator));
    frac.numerator /= commonDivisor;
    frac.denominator /= commonDivisor;
}

int main() {
    Fraction frac1, frac2, result;
    char operation;
    char continueCalculation;

    do {
        // Ввод первой дроби
        cout << "Enter first fraction (numerator/denominator): ";
        char slash;
        cin >> frac1.numerator >> slash >> frac1.denominator;

        // Ввод операции
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;

        // Ввод второй дроби
        cout << "Enter second fraction (numerator/denominator): ";
        cin >> frac2.numerator >> slash >> frac2.denominator;

        // Выполнение операции в зависимости от введенного знака
        switch (operation) {
        case '+':
            // Сложение: (a/b) + (c/d) = (a * d + b * c) / (b * d)
            result.numerator = frac1.numerator * frac2.denominator + frac1.denominator * frac2.numerator;
            result.denominator = frac1.denominator * frac2.denominator;
            break;
        case '-':
            // Вычитание: (a/b) - (c/d) = (a * d - b * c) / (b * d)
            result.numerator = frac1.numerator * frac2.denominator - frac1.denominator * frac2.numerator;
            result.denominator = frac1.denominator * frac2.denominator;
            break;
        case '*':
            // Умножение: (a/b) * (c/d) = (a * c) / (b * d)
            result.numerator = frac1.numerator * frac2.numerator;
            result.denominator = frac1.denominator * frac2.denominator;
            break;
        case '/':
            // Деление: (a/b) / (c/d) = (a * d) / (b * c)
            result.numerator = frac1.numerator * frac2.denominator;
            result.denominator = frac1.denominator * frac2.numerator;
            break;
        default:
            cout << "Invalid operation!" << endl;
            continue;
        }

        // Упрощение результата
        simplify(result);

        // Вывод результата
        cout << "Result: " << result.numerator << "/" << result.denominator << endl;

        // Запрос на продолжение вычислений
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueCalculation;

    } while (continueCalculation == 'y' || continueCalculation == 'Y');

    return 0;
}
