#include <iostream>
using namespace std;

// ЭТАП 1: Класс работника с именем и зарплатой
class Employee {
private:
    char fullName[50];
    float salary;

public:
    void fillInfo() {
        cout << "Введите имя сотрудника: ";
        cin >> fullName;
        cout << "Введите зарплату: ";
        cin >> salary;
    }

    void showInfo() {
        cout << "Имя: " << fullName << ", Зарплата: " << salary << " руб.";
    }

    float getPay() {
        return salary;
    }
};

// ЭТАП 2: Функция сортировки по зарплате (через указатели)
void sortBySalary(Employee* arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if ((*(arr + i))->getPay() > (*(arr + j))->getPay()) {
                Employee* temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

// ЭТАП 3: Главная функция
int main() {
    setlocale(LC_ALL, "Rus");
    const int MAX = 100;
    Employee* list[MAX];
    int size = 0;
    char answer;

    // Ввод данных
    do {
        list[size] = new Employee;
        list[size]->fillInfo();
        size++;

        cout << "Добавить ещё одного сотрудника? (y/n): ";
        cin >> answer;
    } while ((answer == 'y' || answer == 'Y') && size < MAX);

    // Сортировка по зарплате
    sortBySalary(list, size);

    // Вывод отсортированных данных
    cout << "\nСписок сотрудников по возрастанию зарплаты:\n";
    for (int i = 0; i < size; i++) {
        cout << "Сотрудник #" << i + 1 << ": ";
        list[i]->showInfo();
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < size; i++)
        delete list[i];

    return 0;
}
