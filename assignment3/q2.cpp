#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(char c) {
    if (!isFull()) {
        stack[++top] = c;
    }
}

char pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return '\0';
}

int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    cout << "Reversed string: ";
    while (!isEmpty()) {
        cout << pop();
    }
    cout << endl;

    return 0;
}
