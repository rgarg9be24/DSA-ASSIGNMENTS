#include <iostream>
using namespace std;

class Queue{
  private:
  int *arr;
  int front;
  int rear;
  int capacity;
  
  public:
  Queue(int size)
  {
      capacity=size;
      arr=new int[capacity];
      front=-1;
      rear=-1;
      
  }
  ~Queue()
  {
      delete[] arr;
  }
  
  bool isEmpty()
  {
      return (front==-1);
  }
  bool isFull(){
      return rear==capacity-1;
  }
  void enqueue(int item)
  {
      if(isFull())
      cout<<"Queue is full"<<endl;
      return;
      
      if(isEmpty())
      {
          front=0;
      }
      arr[++rear]=item;
      cout<<item<<" enqueued in Queue";
  }
  void dequeue(){
      if(isEmpty())
      {
          cout<<"queue is Empty"<<endl;
          return;
      }
      cout<<"dequeued item: "<<arr[front]<<endl;
      if(rear==front)
      front=rear=-1;
      else
      front++;
  }
  
  void peek(){
      if(isEmpty())
      {
          cout<<"queue is Empty";
      }
      else
      cout<<"peek item is: "<<arr[front]<<endl;
  }
  void display()
  {
      if(isEmpty())
      cout<<"Queue is Empty"<<endl;
      else
      cout<<"Queue elements are: "<<endl;
      for(int i=front ; i<=rear;i++)
      cout<<arr[i]<<endl;
  }
    
};

int main()
{
   int size;
    cout << "Enter the maximum size of the queue: ";
    cin >> size;

    Queue q(size);
    int choice, value;

    while (true) {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;

            case 4:
                cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;

            case 5:
                q.display();
                break;

            case 6:
                q.peek();
                break;

            case 7:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 7." << endl;
        }
    }


    return 0;
}