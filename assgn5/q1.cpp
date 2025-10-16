#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;


void insertAtBeginning(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}


void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}


void insertBeforeAfter(int value, int key, bool before) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;

  
    if (before && head->data == key) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " before " << key << ".\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        if ((before && temp->next && temp->next->data == key) ||
            (!before && temp->data == key)) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << (before ? " before " : " after ") << key << ".\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Node with value " << key << " not found.\n";
}


void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted " << temp->data << " from beginning.\n";
    delete temp;
}


void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted " << head->data << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    cout << "Deleted " << temp->next->data << " from end.\n";
    delete temp->next;
    temp->next = nullptr;
}


void deleteSpecificNode(int key) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node with value " << key << ".\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != key)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Node with value " << key << " not found.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    cout << "Deleted node with value " << key << ".\n";
}


void searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Node " << key << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node " << key << " not found in the list.\n";
}


void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    int choice, value, key;
    bool before;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter new value: ";
                cin >> value;
                cout << "Enter existing node value (before which to insert): ";
                cin >> key;
                insertBeforeAfter(value, key, true);
                break;
            case 4:
                cout << "Enter new value: ";
                cin >> value;
                cout << "Enter existing node value (after which to insert): ";
                cin >> key;
                insertBeforeAfter(value, key, false);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter node value to delete: ";
                cin >> key;
                deleteSpecificNode(key);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> key;
                searchNode(key);
                break;
            case 9:
                displayList();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}