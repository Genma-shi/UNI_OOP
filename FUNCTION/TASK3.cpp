#include <iostream>
using namespace std;

// Этап 1: Функция power для типа double
// Принимает число типа double и степень, возвращает результат возведения в степень
double power(double n, int p = 2) {
    double result = 1.0;  // Инициализация результата
    for (int j = 0; j < p; j++)  // Цикл для умножения n на себя p раз
        result *= n;
    return result;  // Возвращаем результат
}

// Этап 2: Перегруженная функция power для типа char
// Принимает char, преобразует в double и вызывает основную функцию
double power(char n, int p = 2) {
    return power(static_cast<double>(n), p);  // Преобразуем char в double и вызываем функцию power
}

// Этап 3: Перегруженная функция power для типа int
// Принимает int, преобразует в double и вызывает основную функцию
double power(int n, int p = 2) {
    return power(static_cast<double>(n), p);  // Преобразуем int в double и вызываем функцию power
}

// Этап 4: Перегруженная функция power для типа long
// Принимает long, преобразует в double и вызывает основную функцию
double power(long n, int p = 2) {
    return power(static_cast<double>(n), p);  // Преобразуем long в double и вызываем функцию power
}

// Этап 5: Перегруженная функция power для типа float
// Принимает float, преобразует в double и вызывает основную функцию
double power(float n, int p = 2) {
    return power(static_cast<double>(n), p);  // Преобразуем float в double и вызываем функцию power
}

int main() {
    // Этап 6: Переменные для разных типов
    double number, answer;  // Переменная для числа и ответа
    int pow;  // Переменная для степени
    char yeserno;  // Переменная для ответа, хотите ли вы ввести степень

    // Этап 7: Ввод числа
    cout << "\nEnter a number: ";
    cin >> number;

    // Этап 8: Запрос, хотите ли ввести степень
    cout << "Would you like to enter an exponent (y/n)? ";
    cin >> yeserno;

    // Этап 9: Ввод степени, если нужно
    if (yeserno == 'y') {
        cout << "Enter exponent: ";
        cin >> pow;  // Ввод степени
        answer = power(number, pow);  // Вызов перегруженной функции для типа double
    }
    else {
        answer = power(number);  // Использование стандартной функции для квадрата
    }

    // Этап 10: Вывод ответа
    cout << "Answer: " << answer << endl;

    // Этап 11: Пример вызовов функции для других типов
    cout << "\nOverload for char:" << endl;
    char char_num = '3';
    cout << "power(char) = " << power(char_num, 3) << endl;

    cout << "\nOverload for int:" << endl;
    int int_num = 3;
    cout << "power(int) = " << power(int_num, 3) << endl;

    cout << "\nOverload for long:" << endl;
    long long_num = 3;
    cout << "power(long) = " << power(long_num, 3) << endl;

    cout << "\nOverload for float:" << endl;
    float float_num = 3.5f;
    cout << "power(float) = " << power(float_num, 3) << endl;

    return 0;  // Завершаем программу
}
