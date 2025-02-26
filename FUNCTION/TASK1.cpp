#include <iostream>

using namespace std;

// Этап 1: Объявление функции для преобразования времени в секунды
long hms_to_secs(int hours, int minutes, int seconds) {
    return hours * 3600 + minutes * 60 + seconds;
}

int main() {
    // Этап 2: Организация бесконечного цикла для запроса данных у пользователя
    while (true) {
        int hours, minutes, seconds;

        // Этап 3: Запрос ввода времени
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;

        // Этап 4: Вычисление общего количества секунд
        long total_seconds = hms_to_secs(hours, minutes, seconds);

        // Этап 5: Вывод результата
        cout << "Total seconds: " << total_seconds << endl;

        // Этап 6: Запрос на продолжение работы
        char choice;
        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            break; // Выход из цикла при отрицательном ответе
        }
    }

    return 0; // Этап 7: Завершение программы
}
