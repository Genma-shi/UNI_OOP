#include <iostream>
using namespace std;

// ЭТАП 1: Константы
const int BLOCKS = 10;
const int SIZE_PER_BLOCK = 10;

int main() {
    setlocale(LC_ALL, "Rus");
    // ЭТАП 2: Объявление массивов
    int block0[SIZE_PER_BLOCK], block1[SIZE_PER_BLOCK], block2[SIZE_PER_BLOCK];
    int block3[SIZE_PER_BLOCK], block4[SIZE_PER_BLOCK], block5[SIZE_PER_BLOCK];
    int block6[SIZE_PER_BLOCK], block7[SIZE_PER_BLOCK], block8[SIZE_PER_BLOCK];
    int block9[SIZE_PER_BLOCK];

    // ЭТАП 3: Массив указателей на массивы
    int* segments[BLOCKS] = {
        block0, block1, block2, block3, block4,
        block5, block6, block7, block8, block9
    };

    // ЭТАП 4: Заполнение данными
    for (int i = 0; i < BLOCKS; i++) {
        for (int j = 0; j < SIZE_PER_BLOCK; j++) {
            segments[i][j] = i * 100 + j * 10;
        }
    }

    // ЭТАП 5: Вывод значений
    cout << "Вывод значений из массивов:\n";
    for (int i = 0; i < BLOCKS; i++) {
        cout << "Массив #" << i << ": ";
        for (int j = 0; j < SIZE_PER_BLOCK; j++) {
            cout << segments[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
