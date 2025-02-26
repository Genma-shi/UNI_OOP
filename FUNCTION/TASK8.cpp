#include <iostream>
#include <cstdlib> // Для использования abs()

using namespace std;

// Структура для хранения дробей
struct Fraction {
    int numerator;   // Числитель
    int denominator; // Знаменатель
};

// Этап 1: Функция для сложения дробей
Fraction fadd(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator + frac1.denominator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;
    return result;
}

// Этап 2: Функция для вычитания дробей
Fraction fsub(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator - frac1.denominator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;
    return result;
}

// Этап 3: Функция для умножения дробей
Fraction fmul(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;
    return result;
}

// Этап 4: Функция для деления дробей
Fraction fdiv(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator;
    result.denominator = frac1.denominator * frac2.numerator;
    return result;
}

// Главная функция
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
            result = fadd(frac1, frac2); // Выполнение сложения
            break;
        case '-':
            result = fsub(frac1, frac2); // Выполнение вычитания
            break;
        case '*':
            result = fmul(frac1, frac2); // Выполнение умножения
            break;
        case '/':
            result = fdiv(frac1, frac2); // Выполнение деления
            break;
        default:
            // Если введен некорректный оператор
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
