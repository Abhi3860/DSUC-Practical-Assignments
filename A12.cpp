//Program to implement Linked List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;


void create(int value) {
    Node* newNode = new Node{value, nullptr};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}


void traverse() {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insertAtBeginning(int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}


void insertAtEnd(int value) {
    create(value);
}


void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of range.\n";
        return;
    }

    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
}


void deleteNode(int value) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != value) {
        temp = temp->next;
    }

    if (!temp->next) {
        cout << "Value not found.\n";
        return;
    }

    Node* removeNode = temp->next;
    temp->next = temp->next->next;
    delete removeNode;

    cout << "Node deleted.\n";
}


void search(int value) {
    Node* temp = head;
    int pos = 1;

    while (temp) {
        if (temp->data == value) {
            cout << "Value found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Value not found.\n";
}

int main() {
    int choice, value, pos;

    while (true) {
        
        cout << "1. Create (Insert at end)\n";
        cout << "2. Traverse\n";
        cout << "3. Insert at Beginning\n";
        cout << "4. Insert at End\n";
        cout << "5. Insert at Position\n";
        cout << "6. Delete\n";
        cout << "7. Search\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                create(value);
                break;

            case 2:
                traverse();
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 4:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 5:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(value, pos);
                break;

            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;

            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;

            case 8:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}