#include <iostream>
using namespace std;

// ЭТАП 1: Определение структуры узла
struct Node {
    int value;
    Node* next;
};

// ЭТАП 2: Класс списка с добавлением в конец
class Chain {
private:
    Node* head;

public:
    // Конструктор
    Chain() {
        head = nullptr;
    }

    // Деструктор
    ~Chain() {
        Node* ptr = head;
        while (ptr != nullptr) {
            Node* temp = ptr;
            ptr = ptr->next;
            delete temp;
        }
    }

    // Метод добавления элемента в конец списка
    void append(int val) {
        Node* newNode = new Node;
        newNode->value = val;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Метод вывода элементов списка
    void printAll() {
        Node* current = head;
        cout << "\nСодержимое списка:\n";
        while (current != nullptr) {
            cout << current->value << endl;
            current = current->next;
        }
    }
};

// ЭТАП 3: Основная функция
int main() {
    setlocale(LC_ALL, "Rus");
    Chain myList;

    // Добавление значений
    myList.append(25);
    myList.append(36);
    myList.append(49);
    myList.append(64);

    // Вывод списка
    myList.printAll();

    return 0;
}
