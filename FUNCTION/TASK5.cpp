#include <iostream>
using namespace std;

// Этап 1: Определение структуры Time для хранения времени
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

// Этап 4: Функция swap для обмена значениями двух структур Time
void swap(Time& t1, Time& t2) {
    Time temp = t1; // Сохраняем t1 во временную переменную
    t1 = t2;        // Присваиваем t1 значение t2
    t2 = temp;      // Присваиваем t2 значение временной переменной (старое значение t1)
}

void print_time(int h, int m, int s) {
    // Вывод времени с ведущими нулями
    if (h < 10) cout << "0";
    cout << h << ":";
    if (m < 10) cout << "0";
    cout << m << ":";
    if (s < 10) cout << "0";
    cout << s << endl;
}

int main() {
    // Этап 5: Объявление переменных типа Time для хранения времени
    Time t1, t2, result;

    // Этап 6: Ввод двух значений времени
    cout << "Enter first time (hours minutes seconds): ";
    cin >> t1.hours >> t1.minutes >> t1.seconds;

    cout << "Enter second time (hours minutes seconds): ";
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    // Этап 7: Вывод значений времени до обмена
    cout << "Before swap: " << endl;
    print_time(t1.hours, t1.minutes, t1.seconds);
    print_time(t2.hours, t2.minutes, t2.seconds);

    // Этап 8: Вызов функции swap для обмена значениями
    swap(t1, t2);

    // Этап 9: Вывод значений времени после обмена
    cout << "\nAfter swap: " << endl;
    print_time(t1.hours, t1.minutes, t1.seconds);
    print_time(t2.hours, t2.minutes, t2.seconds);

    // Этап 10: Перевод времени в секунды
    long totalSecs1 = time_to_secs(t1);
    long totalSecs2 = time_to_secs(t2);

    // Этап 11: Сложение двух временных значений в секундах
    long totalSecs = totalSecs1 + totalSecs2;

    // Этап 12: Перевод общей суммы секунд обратно в структуру Time
    result = secs_to_time(totalSecs);

    // Этап 13: Вывод общего количества секунд
    cout << "\nTotal seconds: " << totalSecs << endl;

    // Этап 14: Вывод результата в формате часов, минут и секунд с ведущими нулями
    cout << "Total time: ";
    print_time(result.hours, result.minutes, result.seconds);

    return 0; // Завершаем программу
}
