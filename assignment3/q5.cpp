#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == MAX - 1;
}

void push(int val) {
    if (!isFull()) {
        stack[++top] = val;
    }
}

int pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    return -1; 
}

int evaluatePostfix(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9') {
            push(ch - '0');  // convert char digit to int
        }
        else {
            int val2 = pop();
            int val1 = pop();
            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    cout << "Enter a postfix expression: ";
    cin >> exp;

    int result = evaluatePostfix(exp);
    cout << "Result = " << result << endl;

    return 0;
}
