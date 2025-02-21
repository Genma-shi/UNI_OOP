#include <iostream>

using namespace std;

// Этап 1: Определение структуры time для хранения времени
struct Time
{
    int hours;   // Часы
    int minutes; // Минуты
    int seconds; // Секунды
};

int main()
{
    // Этап 2: Объявление переменной типа Time для хранения введенного времени
    Time t1;
    char first_letter;  // Для выхода из цикла
    char confirm_exit;  // Подтверждение выхода

    while (true) {  // Цикл для повторного ввода

        // Этап 3: Ввод данных о времени

        cout << "Enter time in the format (hours minutes seconds): ";
        cin >> t1.hours >> t1.minutes >> t1.seconds;

        // Этап 4: Вычисление общего количества секунд
        long totalSecs = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;

        // Этап 5: Вывод результата
        cout << "Total seconds: " << totalSecs << endl;

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
