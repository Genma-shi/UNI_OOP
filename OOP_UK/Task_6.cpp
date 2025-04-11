#include <iostream>
using namespace std;

// ЭТАП 1: Константы
const int NUM_ARRAYS = 10;
const int ARRAY_SIZE = 10;

int main() {
    setlocale(LC_ALL, "Rus");
    // ЭТАП 2: Создание массива указателей
    int* arrays[NUM_ARRAYS];

    // ЭТАП 3: Динамическое выделение памяти под массивы
    for (int i = 0; i < NUM_ARRAYS; i++) {
        *(arrays + i) = new int[ARRAY_SIZE];
    }

    // ЭТАП 4: Заполнение данными
    for (int i = 0; i < NUM_ARRAYS; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            *(*(arrays + i) + j) = i * 100 + j * 10;
        }
    }

    // ЭТАП 5: Вывод содержимого
    cout << "Содержимое всех массивов:\n";
    for (int i = 0; i < NUM_ARRAYS; i++) {
        cout << "Массив #" << i << ": ";
        for (int j = 0; j < ARRAY_SIZE; j++) {
            cout << *(*(arrays + i) + j) << " ";
        }
        cout << endl;
    }

    // ЭТАП 6: Освобождение памяти
    for (int i = 0; i < NUM_ARRAYS; i++) {
        delete[] * (arrays + i);
    }

    return 0;
}
