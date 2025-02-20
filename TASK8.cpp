#include <iostream>
#include <iomanip>  // Для управления форматом вывода

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
    // Этап 2: Объявление переменных типа Time для хранения времени
    Time t1, t2, result;

    // Этап 3: Ввод двух значений времени
    cout << "Enter first time (hours minutes seconds): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "Enter second time (hours minutes seconds): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    // Этап 4: Перевод времени в секунды
    long totalSecs1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    long totalSecs2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Этап 5: Сложение двух временных значений в секундах
    long totalSecs = totalSecs1 + totalSecs2;

    // Этап 6: Перевод общей суммы секунд обратно в часы, минуты и секунды
    result.hours = totalSecs / 3600;  // Получаем количество часов
    totalSecs %= 3600;  // Оставшиеся секунды после вычисления часов
    result.minutes = totalSecs / 60;  // Получаем количество минут
    result.seconds = totalSecs % 60;  // Оставшиеся секунды

    // Если минут больше 59, добавляем к часам
    if (result.minutes >= 60) {
        result.hours += result.minutes / 60;
        result.minutes %= 60;
    }

    // Этап 7: Вывод общего количества секунд
    cout << "Total seconds: " << totalSecs1 + totalSecs2 << endl;

    // Этап 8: Вывод результата в формате часов, минут и секунд с ведущими нулями
    cout << "Total time: "
        << setw(2) << setfill('0') << result.hours << ":"
        << setw(2) << setfill('0') << result.minutes << ":"
        << setw(2) << setfill('0') << result.seconds << endl;

    return 0; // Завершаем программу
}
