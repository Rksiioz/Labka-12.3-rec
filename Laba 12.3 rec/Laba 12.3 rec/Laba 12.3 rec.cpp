#include <iostream>

using namespace std;

typedef int Info;
struct Elem {
    int data;
    Elem* prev;
    Elem* next;
    Elem* link;
    Info info;
};

Elem* createNode(int data) {
    Elem* newNode = new Elem;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    newNode->link = nullptr;
    return newNode;
}

void addToEndRecursive(Elem*& head, Elem* newNode) {
    if (head == nullptr) {
        head = newNode;
    }
    else if (head->next == nullptr) {
        head->next = newNode;
        newNode->prev = head;
    }
    else {
        addToEndRecursive(head->next, newNode);
    }
}

void addToEnd(Elem*& head, int data) {
    Elem* newNode = createNode(data);
    addToEndRecursive(head, newNode);
}

void printListRecursive(Elem* current) {
    if (current != nullptr) {
        std::cout << current->data << " ";
        printListRecursive(current->next);
    }
    else {
        std::cout << std::endl;
    }
}

void printList(Elem* head) {
    printListRecursive(head);
}

void freeMemoryRecursive(Elem*& head) {
    if (head != nullptr) {
        Elem* temp = head;
        head = head->next;
        delete temp;
        freeMemoryRecursive(head);
    }
}

void freeMemory(Elem*& head) {
    freeMemoryRecursive(head);
}

void duplicateElementsRecursive(Elem* current, Info value) {
    if (current != nullptr) {
        if (current->data == value) {
            Elem* newNode = createNode(current->data);
            newNode->info = value;
            newNode->next = current->next;
            if (newNode->next != nullptr) {
                newNode->next->prev = newNode;
            }
            newNode->prev = current;
            current->next = newNode;
            duplicateElementsRecursive(newNode->next, value);
        }
        else {
            duplicateElementsRecursive(current->next, value);
        }
    }
}

void duplicateElements(Elem*& head, Info value) {
    duplicateElementsRecursive(head, value);
}

int main() {
    Elem* myList = nullptr;
    int n;
    cout << "Vvedit kilkist elem: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Vvedit znachenya elem " << i + 1 << ": ";
        cin >> value;
        addToEnd(myList, value);
    }

    std::cout << "List: ";
    printList(myList);

    int duplicateValue;
    cout << "Znachenya dlya dublyuvanya: ";
    cin >> duplicateValue;

    duplicateElements(myList, duplicateValue);

    std::cout << "List after dublyuvanya: ";
    printList(myList);

    freeMemory(myList);

    return 0;
}
