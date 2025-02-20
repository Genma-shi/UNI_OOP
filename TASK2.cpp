#include <iostream>

using namespace std;

// Этап 1: Определение структуры Date
struct Date {
    int day;    // День
    int month;  // Месяц
    int year;   // Год
};

int main() {
    // Этап 2: Создание переменной структуры Date
    Date date;
    char confirm_exit;

    // Этап 3: Ввод данных от пользователя с проверкой
    while (true) {
        cout << "Enter date in format DD MM YYYY \n or 0 to exit: ";
        cin >> date.day;

        // Проверка на выход
        if (date.day == 0) {
            cout << "Are you sure you want to exit? (Y/N): ";
            cin >> confirm_exit;
            if (confirm_exit == 'Y' || confirm_exit == 'y') {
                break;
            }
            else {
                continue;
            }
        }

        cin >> date.month >> date.year;

        if (date.day < 1 || date.day > 31) {
            cout << "Error: Day must be between 1 and 31.\n";
        }
        else if (date.month < 1 || date.month > 12) {
            cout << "Error: Month must be between 1 and 12.\n";
        }
        else if (date.year < 0) {
            cout << "Error: Year cannot be negative.\n";
        }
        else {
            // Этап 4: Вывод данных на экран
            cout << "You entered the date: "
                << date.day << "/"
                << date.month << "/"
                << date.year << endl;
            continue;
        }
    }

    return 0; // Завершение программы
}
