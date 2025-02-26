#include <iostream>
using namespace std;

// Этап 1: Структура для хранения суммы в старой английской системе
struct Sterling {
    int pounds;   // Фунты
    int shillings; // Шиллинги
    int pence;    // Пенсы
};

// Этап 2: Функция для получения суммы от пользователя
Sterling getAmountFromUser() {
    Sterling amount;
    cout << "Enter the amount (pounds shillings pence): ";
    cin >> amount.pounds >> amount.shillings >> amount.pence;
    return amount;  // Возвращаем введенную сумму типа sterling
}

// Этап 3: Функция для сложения двух сумм типа sterling
Sterling addSterling(Sterling s1, Sterling s2) {
    Sterling result;

    // Сложение пенсов
    result.pence = s1.pence + s2.pence;
    if (result.pence >= 12) {  // Если пенсов больше 11, нормализуем
        result.shillings += result.pence / 12;
        result.pence = result.pence % 12;
    }

    // Сложение шиллингов
    result.shillings += s1.shillings + s2.shillings;
    if (result.shillings >= 20) {  // Если шиллингов больше 19, нормализуем
        result.pounds += result.shillings / 20;
        result.shillings = result.shillings % 20;
    }

    // Сложение фунтов
    result.pounds += s1.pounds + s2.pounds;

    return result;  // Возвращаем сложенную сумму
}

// Этап 4: Функция для вывода суммы типа sterling
void displaySterling(Sterling s) {
    cout << "Total sum: " << s.pounds << " pounds, "
        << s.shillings << " shillings, "
        << s.pence << " pence." << endl;  // Выводим сумму
}

int main() {
    char continueCalc; // Переменная для проверки, хочет ли пользователь продолжить

    do {
        // Этап 5: Получаем первую сумму от пользователя
        Sterling sum1 = getAmountFromUser();

        // Этап 6: Получаем вторую сумму от пользователя
        Sterling sum2 = getAmountFromUser();

        // Этап 7: Складываем две суммы
        Sterling total = addSterling(sum1, sum2);

        // Этап 8: Выводим результат
        displaySterling(total);

        // Этап 9: Запрашиваем, хочет ли пользователь продолжить
        cout << "Would you like to continue (y/n)? ";
        cin >> continueCalc;

    } while (continueCalc == 'y' || continueCalc == 'Y');  // Повторить, если ответ "y" или "Y"

    return 0;  // Завершаем программу
}
