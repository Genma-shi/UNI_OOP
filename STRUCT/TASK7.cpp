#include <iostream>

using namespace std;

// Структура для хранения суммы в старой английской системе
struct Sterling {
    int pounds;   // Фунты
    int shillings; // Шиллинги
    int pence;    // Пенсы
};

int main() {
    char continueCalc; // Переменная для проверки, хочет ли пользователь продолжить

    do {
        double decimalPounds; // Переменная для хранения суммы в десятичных фунтах

        // Ввод суммы в десятичных фунтах
        cout << "Enter the amount in decimal pounds: ";
        cin >> decimalPounds;

        // Перевод суммы из десятичных фунтов в старую систему
        int totalPence = static_cast<int>(decimalPounds * 240);  // 1 фунт = 240 пенсов

        // Создаем объект структуры Sterling для хранения переведенной суммы
        Sterling sterling;

        sterling.pounds = totalPence / 240;        // Получаем количество фунтов
        totalPence %= 240;                         // Оставшиеся пенсы после перевода в фунты

        sterling.shillings = totalPence / 12;      // Получаем количество шиллингов
        sterling.pence = totalPence % 12;          // Оставшиеся пенсы после перевода в шиллинги

        // Вывод результата
        cout << "Converted amount: " << sterling.pounds << " pounds, "
             << sterling.shillings << " shillings, "
             << sterling.pence << " pence." << endl;

        // Запрашиваем, хочет ли пользователь продолжить
        cout << "Would you like to continue (y/n)? ";
        cin >> continueCalc;
    } while (continueCalc == 'y' || continueCalc == 'Y');  // Повторить, если ответ "y" или "Y"

    return 0;
}
