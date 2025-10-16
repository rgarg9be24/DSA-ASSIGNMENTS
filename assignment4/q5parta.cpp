#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }

    bool isEmpty() { return front > rear; }
    void enqueue(int x) { arr[++rear] = x; }
    int dequeue() { return arr[front++]; }
    int peek() { return arr[front]; }
    int size() { return rear - front + 1; }
    void reset() { front = 0; rear = -1; }
};

class StackTwoQueues {
    Queue q1, q2;
public:
    void push(int x) {
        q2.enqueue(x);

        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
        q2.reset();  
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.dequeue();
    }

    int top() {
        if (q1.isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.peek();
    }

    bool empty() {
        return q1.isEmpty();
    }
};

int main() {
    StackTwoQueues s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.top() << endl; 
    s.pop();
    cout << "Top after pop: " << s.top() << endl; 
    return 0;
}