#include <iostream>
#include <iomanip>  // Для управления форматом вывода

using namespace std;

// Этап 1: Определение структуры time для хранения времени
struct Time {
    int hours;   // Часы
    int minutes; // Минуты
    int seconds; // Секунды
};

// Этап 2: Функция для перевода времени в секунды
long time_to_secs(Time t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

// Этап 3: Функция для перевода секунд в структуру Time
Time secs_to_time(long totalSecs) {
    Time result;
    result.hours = totalSecs / 3600;  // Получаем количество часов
    totalSecs %= 3600;  // Оставшиеся секунды после вычисления часов
    result.minutes = totalSecs / 60;  // Получаем количество минут
    result.seconds = totalSecs % 60;  // Оставшиеся секунды
    return result;
}

int main() {
    // Этап 4: Объявление переменных типа Time для хранения времени
    Time t1, t2, result;

    // Этап 5: Ввод двух значений времени
    cout << "Enter first time (hours minutes seconds): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "Enter second time (hours minutes seconds): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    // Этап 6: Перевод времени в секунды
    long totalSecs1 = time_to_secs(t1);
    long totalSecs2 = time_to_secs(t2);

    // Этап 7: Сложение двух временных значений в секундах
    long totalSecs = totalSecs1 + totalSecs2;

    // Этап 8: Перевод общей суммы секунд обратно в структуру Time
    result = secs_to_time(totalSecs);

    // Этап 9: Вывод общего количества секунд
    cout << "Total seconds: " << totalSecs << endl;

    // Этап 10: Вывод результата в формате часов, минут и секунд с ведущими нулями
    cout << "Total time: "
        << setw(2) << setfill('0') << result.hours << ":"
        << setw(2) << setfill('0') << result.minutes << ":"
        << setw(2) << setfill('0') << result.seconds << endl;

    return 0; // Завершаем программу
}
