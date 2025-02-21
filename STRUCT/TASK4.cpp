#include <iostream>

using namespace std;

// Этап 1: Определение структур
struct Date {
    int day;    // День
    int month;  // Месяц
    int year;   // Год
};

enum etype { laborer, secretary, manager, accountant, executive, researcher };

struct Employee {
    int id;          // ID сотрудника
    float salary;    // Зарплата сотрудника
    etype position;  // Должность сотрудника
    Date hire_date;  // Дата приёма на работу
};

int main() {
    // Этап 2: Создание массива сотрудников
    Employee employees[3];

    // Этап 3: Ввод данных для каждого сотрудника
    for (int i = 0; i < 3; i++) {
        while (true) {
            cout << "Enter data for employee " << i + 1 << ":\n";

            cout << "Enter ID: ";
            cin >> employees[i].id;

            if (employees[i].id <= 0) {
                cout << "Invalid ID. Please re-enter employee data.\n";
                continue;
            }

            cout << "Enter salary: ";
            cin >> employees[i].salary;

            if (employees[i].salary <= 0) {
                cout << "Invalid salary. Please re-enter employee data.\n";
                continue;
            }

            cout << "Enter position (l - laborer, s - secretary, m - manager, a - accountant, e - executive, r - researcher): ";
            char pos;
            cin >> pos;
            switch (pos) {
            case 'l': employees[i].position = laborer; break;
            case 's': employees[i].position = secretary; break;
            case 'm': employees[i].position = manager; break;
            case 'a': employees[i].position = accountant; break;
            case 'e': employees[i].position = executive; break;
            case 'r': employees[i].position = researcher; break;
            default:
                cout << "Invalid position. Please re-enter employee data.\n";
                continue;
            }

            cout << "Enter hire date (DD MM YYYY): ";
            cin >> employees[i].hire_date.day >> employees[i].hire_date.month >> employees[i].hire_date.year;

            if (employees[i].hire_date.day < 1 || employees[i].hire_date.day > 31 ||
                employees[i].hire_date.month < 1 || employees[i].hire_date.month > 12 ||
                employees[i].hire_date.year < 0) {
                cout << "Invalid date entered. Please re-enter employee data.\n";
                continue;
            }

            break; // Все данные корректны, выход из цикла
        }
    }

    // Этап 4: Вывод данных о сотрудниках
    cout << "\n__________Employee Data__________\n";
    for (int i = 0; i < 3; i++) {
        cout << "Employee " << i + 1 << ":\n";
        cout << "     ID: " << employees[i].id << "\n";
        cout << "     Salary: " << employees[i].salary << "\n";
        cout << "     Position: ";
        switch (employees[i].position) {
        case laborer: cout << "laborer\n"; break;
        case secretary: cout << "secretary\n"; break;
        case manager: cout << "manager\n"; break;
        case accountant: cout << "accountant\n"; break;
        case executive: cout << "executive\n"; break;
        case researcher: cout << "researcher\n"; break;
        }
        cout << "     Hire Date: " << employees[i].hire_date.day << "/"
            << employees[i].hire_date.month << "/" << employees[i].hire_date.year << "\n";
    }

    return 0; // Завершение программы
}
