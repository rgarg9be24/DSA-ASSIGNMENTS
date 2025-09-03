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

char peek() {
    if (!isEmpty()) {
        return stack[top];
    }
    return '\0';
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty()) {
                return false;
            }
            char topChar = pop();
            if (!isMatchingPair(topChar, ch)) {
                return false;
            }
        }
    }
    return isEmpty();
}

int main() {
    char exp[MAX];
    cout << "Enter an expression: ";
    cin >> exp;

    if (isBalanced(exp)) {
        cout << "Expression is Balanced" << endl;
    } else {
        cout << "Expression is Not Balanced" << endl;
    }

    return 0;
}
