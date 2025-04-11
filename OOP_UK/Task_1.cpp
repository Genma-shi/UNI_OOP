#include <iostream>
using namespace std;

// ЭТАП 1: Прототип функции, выполняющей покомпонентное сложение двух массивов через указатели
void addArrays(const float* src1, const float* src2, float* dst, int len);

int main() {
    // ЭТАП 2: Определение и инициализация исходных массивов
    const int N = 5;
    float* inputA = new float[N] { 10.0f, 20.0f, 30.0f, 40.0f, 50.0f };
    float* inputB = new float[N] { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f };
    float* output = new float[N];  // Массив для хранения результата

    // ЭТАП 3: Вызов функции, передаём указатели на массивы
    addArrays(inputA, inputB, output, N);

    // ЭТАП 4: Вывод результата
    cout << "Summed values: ";
    for (int i = 0; i < N; ++i) {
        cout << *(output + i) << " ";
    }
    cout << endl;

    // ЭТАП 5: Очистка динамически выделенной памяти
    delete[] inputA;
    delete[] inputB;
    delete[] output;

    return 0;
}

// ЭТАП 6: Реализация функции сложения массивов через указатели
// Каждый элемент dst[i] = src1[i] + src2[i]
void addArrays(const float* src1, const float* src2, float* dst, int len) {
    const float* end = src1 + len;
    while (src1 < end) {
        *dst = *src1 + *src2;
        ++src1;
        ++src2;
        ++dst;
    }
}
