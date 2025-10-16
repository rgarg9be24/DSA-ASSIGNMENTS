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
};

class StackOneQueue {
    Queue q;
public:
    void push(int x) {
        int size = q.size();
        q.enqueue(x);

        for (int i = 0; i < size; i++) {
            q.enqueue(q.dequeue());
        }
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.dequeue();
    }

    int top() {
        if (q.isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.peek();
    }

    bool empty() {
        return q.isEmpty();
    }
};

int main() {
    StackOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.top() << endl; 
    s.pop();
    cout << "Top after pop: " << s.top() << endl; 
    return 0;

}