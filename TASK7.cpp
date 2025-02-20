#include <iostream>

using namespace std;

int main()
{
    char continueCalc; // Переменная для проверки, хочет ли пользователь продолжить

    do
    {
        // Вводим первую сумму
        int pounds1, shillings1, pence1;
        cout << "Enter the first amount (pounds shillings pence): ";
        cin >> pounds1 >> shillings1 >> pence1;

        // Вводим вторую сумму
        int pounds2, shillings2, pence2;
        cout << "Enter the second amount (pounds shillings pence): ";
        cin >> pounds2 >> shillings2 >> pence2;

        // Складываем суммы
        int totalPounds = pounds1 + pounds2;
        int totalShillings = shillings1 + shillings2;
        int totalPence = pence1 + pence2;

        // Нормализуем, если пенсов больше 11
        if (totalPence >= 12)
        {
            totalShillings += totalPence / 12;
            totalPence = totalPence % 12;
        }

        // Нормализуем, если шиллингов больше 19
        if (totalShillings >= 20)
        {
            totalPounds += totalShillings / 20;
            totalShillings = totalShillings % 20;
        }

        // Выводим результат
        cout << "Total sum: " << totalPounds << " " << totalShillings << " " << totalPence << endl;

        // Запрашиваем, хочет ли пользователь продолжить
        cout << "Would you like to continue (y/n)? ";
        cin >> continueCalc;
    } while (continueCalc == 'y' || continueCalc == 'Y');  // Повторить, если ответ "y" или "Y"

    return 0;
}
