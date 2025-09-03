#include <iostream>
using namespace std;


#define MAX 5

int stack[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed" << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
    } else {
        cout << stack[top] << " popped" << endl;
        top--;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element: " << stack[top] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            if (isEmpty())
                cout << "Stack is empty" << endl;
            else
                cout << "Stack is not empty" << endl;
        } else if (choice == 4) {
            if (isFull())
                cout << "Stack is full" << endl;
            else
                cout << "Stack is not full" << endl;
        } else if (choice == 5) {
            display();
        } else if (choice == 6) {
            peek();
        } else if (choice == 7) {
            exit(0);
        } else {
            cout << "Invalid choice" << endl;
        }

        cout << endl;
    }

    return 0;
}
