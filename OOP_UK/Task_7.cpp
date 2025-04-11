#include <iostream>
using namespace std;

// ЭТАП 1: Класс, объединяющий 10 массивов в один логический массив
class SafeLinearArray {
private:
    static const int NUM_ARRAYS = 10;
    static const int ARRAY_SIZE = 10;
    int* blocks[NUM_ARRAYS];

public:
    // ЭТАП 2: Конструктор — выделение памяти
    SafeLinearArray() {
        for (int i = 0; i < NUM_ARRAYS; i++) {
            *(blocks + i) = new int[ARRAY_SIZE];
        }
    }

    // ЭТАП 3: Деструктор — освобождение памяти
    ~SafeLinearArray() {
        for (int i = 0; i < NUM_ARRAYS; i++) {
            delete[] * (blocks + i);
        }
    }

    // ЭТАП 4: Перегрузка оператора [] — доступ к элементу как к одномерному массиву
    int& operator[](int index) {
        int outer = index / ARRAY_SIZE;   // номер подмассива
        int inner = index % ARRAY_SIZE;   // позиция в подмассиве
        return *(*(blocks + outer) + inner);
    }

    // ЭТАП 5: Заполнение массива тестовыми данными
    void fill() {
        for (int i = 0; i < NUM_ARRAYS * ARRAY_SIZE; i++) {
            (*this)[i] = i * 10;
        }
    }

    // ЭТАП 6: Отображение содержимого
    void print() {
        cout << "Содержимое массива:\n";
        for (int i = 0; i < NUM_ARRAYS * ARRAY_SIZE; i++) {
            cout << (*this)[i] << " ";
            if ((i + 1) % ARRAY_SIZE == 0) cout << endl;
        }
    }
};

// ЭТАП 7: Работа с классом в функции main
int main() {
    setlocale(LC_ALL, "Rus");
    SafeLinearArray data;
    data.fill();
    data.print();
    return 0;
}
