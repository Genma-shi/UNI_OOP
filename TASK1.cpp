#include <iostream>

using namespace std;

// Этап 1: Определение структуры Employee
struct Employee {
    int id;        // ID сотрудника
    float salary;  // Зарплата сотрудника
};

int main() {
    // Этап 2: Ввод количества сотрудников
    int employee_count;
    cout << "Enter employee counts : ";
    cin >> employee_count;

    // Этап 3: Динамическое выделение памяти для массива сотрудников
    Employee* employee = new Employee[employee_count];

    // Этап 4: Ввод данных для каждого сотрудника
    for (int i = 0; i < employee_count; i++) {
        cout << "Enter employee ID : ";
        cin >> employee[i].id;
        cout << "Enter employee Salary : ";
        cin >> employee[i].salary;
    }

    // Этап 5: Вывод данных о сотрудниках
    cout << "__________Employee Data__________" << endl;
    for (int i = 0; i < employee_count; i++) {
        cout << "Employee " << i << endl;
        cout << "     ID: " << employee[i].id << " Salary: " << employee[i].salary << endl;
    }

    // Этап 6: Освобождение памяти
    delete[] employee;

    return 0;  // Завершение программы
}
