#include <iostream>
using namespace std;

// ЭТАП 1: Определение симулированной памяти
const int MEMORY_SIZE = 100;

struct Memory {
    float floats[MEMORY_SIZE]; // Хранилище значений float
    int pointers[MEMORY_SIZE]; // Хранилище "указателей"
    int float_index = 0;
    int pointer_index = 0;

    // Сохраняет значение и возвращает "адрес"
    int storeFloat(float value) {
        floats[float_index] = value;
        return float_index++;
    }

    // Сохраняет указатель и возвращает индекс в pointers
    int storePointer(int float_addr) {
        pointers[pointer_index] = float_addr;
        return pointer_index++;
    }

    float& getFloat(int address) {
        return floats[address];
    }

    int getPointer(int address) {
        return pointers[address];
    }
};

Memory mem; // глобальная модель памяти

// ЭТАП 2: Класс переменной типа float
class Float {
private:
    int location;

public:
    explicit Float(float val) {
        location = mem.storeFloat(val);
    }

    int getAddress() const {
        return location;
    }
};

// ЭТАП 3: Класс указателя на float
class ptrFloat {
private:
    int pointer_location;

public:
    explicit ptrFloat(const Float& f) {
        pointer_location = mem.storePointer(f.getAddress());
    }

    float& operator*() {
        return mem.getFloat(mem.getPointer(pointer_location));
    }
};

// ЭТАП 4: Демонстрация работы
int main() {
    Float f1(3.14f);
    Float f2(6.28f);

    ptrFloat p1(f1);
    ptrFloat p2(f2);

    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    *p1 = 1.11f;
    *p2 = 2.22f;

    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;

    return 0;
}
