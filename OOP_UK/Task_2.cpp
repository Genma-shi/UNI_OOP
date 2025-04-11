#include <iostream>
using namespace std;



// ЭТАП 1: Функция сравнения строк через указатели
int compareText(const char* a, const char* b);

int main() {
    setlocale(LC_ALL, "Rus");
    // ЭТАП 2: Создание буферов и ввод строк
    const int LIMIT = 256;
    char* buffer1 = new char[LIMIT];
    char* buffer2 = new char[LIMIT];

    cout << "Введите первую строку: ";
    cin.getline(buffer1, LIMIT);

    cout << "Введите вторую строку: ";
    cin.getline(buffer2, LIMIT);

    // ЭТАП 3: Сравнение строк
    int status = compareText(buffer1, buffer2);

    // ЭТАП 4: Вывод результата
    switch (status) {
    case -1:
        cout << "Первая строка идет раньше по алфавиту." << endl;
        break;
    case 1:
        cout << "Вторая строка идет раньше по алфавиту." << endl;
        break;
    default:
        cout << "Строки совпадают." << endl;
        break;
    }

    // ЭТАП 5: Освобождение памяти
    delete[] buffer1;
    delete[] buffer2;

    return 0;
}

// ЭТАП 6: Реализация функции посимвольного сравнения
int compareText(const char* a, const char* b) {
    while (*a != '\0' && *b != '\0') {
        if (*a != *b)
            return (*a < *b) ? -1 : 1;
        ++a;
        ++b;
    }

    // Обработка случая, когда одна строка короче
    if (*a == '\0' && *b == '\0')
        return 0;
    return (*a == '\0') ? -1 : 1;
}
