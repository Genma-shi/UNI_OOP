#include <iostream>
#include <cstdlib> // Для использования abs()

using namespace std;

// Структура для хранения дробей
struct Fraction {
    int numerator;   // Числитель
    int denominator; // Знаменатель
};

int main() {
    Fraction frac1, frac2, result;
    char operation;            // Операция (+, -, *, /)
    char continueCalculation;  // Переменная для продолжения или завершения цикла

    do {
        // Этап 1: Ввод первой дроби
        cout << "Enter first fraction (numerator/denominator): ";
        char slash; // Переменная для считывания символа '/'
        cin >> frac1.numerator >> slash >> frac1.denominator;

        // Этап 2: Ввод операции
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;

        // Этап 3: Ввод второй дроби
        cout << "Enter second fraction (numerator/denominator): ";
        cin >> frac2.numerator >> slash >> frac2.denominator;

        // Этап 4: Выполнение операции
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
            // Сообщение об ошибке, если введен некорректный оператор
            cout << "Invalid operation!" << endl;
            continue;
        }

        // Этап 5: Упрощение дроби
        // НОД для упрощения дроби
        int a = abs(result.numerator);
        int b = abs(result.denominator);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        int gcd = a; // НОД числителя и знаменателя

        // Упрощение
        result.numerator /= gcd;
        result.denominator /= gcd;

        // Этап 6: Вывод результата
        cout << "Result: " << result.numerator << "/" << result.denominator << endl;

        // Этап 7: Запрос на продолжение вычислений
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueCalculation;

    } while (continueCalculation == 'y' || continueCalculation == 'Y');

    return 0;
}
