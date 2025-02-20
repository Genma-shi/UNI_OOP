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

    char first_letter;  // Для выхода из цикла
    char confirm_exit;  // Подтверждение выхода

    while (true) {  // Цикл для повторного ввода

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

        // Этап 6: Вывод результата
        cout << "The sum is: " << sum.numerator << "/" << sum.denominator << endl;

        // Проверка на выход
        cout << "Enter '0' to exit or any other key to continue: ";
        cin >> first_letter;

        if (first_letter == '0') {
            cout << "Are you sure you want to exit? (Y/N): ";
            cin >> confirm_exit;
            if (confirm_exit == 'Y' || confirm_exit == 'y') {
                break;  // Выход из цикла
            }
            else {
                continue;  // Продолжение цикла
            }
        }
    }

    return 0; // Завершаем программу
}
