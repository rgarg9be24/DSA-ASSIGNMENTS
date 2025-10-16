#include <iostream>
using namespace std;

class Cqueue{
    private:
    int *arr;
    int front;
    int rear;
    int size;
    
    public:
    Cqueue(int n)
    {
        size=n;
        front =-1;
        rear=-1;
        arr=new int[size];
        
    }
    ~Cqueue()
    {
        delete[] arr;
    }
    
    bool isEmpty()
    {
        return front ==-1;
    }
    
    bool isFull()
    {
        return rear==(rear+1)%size;
        
    }
    
    void enqueue(int item)
    {
        if(isFull())
        {
            cout<<"queue is full"<<endl;
            return;
        }
        if(isEmpty())
        {
            front=rear=0;
        }
        else
        {
        rear=(rear+1)%size;
        }
        arr[rear]=item;
        cout<<item<<" is enqueued"<<endl;
    }
    
    void dequeue( ){
        if(isEmpty())
        {
            cout<<"queue is Empty"<<endl;
            return;
    }
        int removedval=arr[front];
        if(front==rear)
        {
            front=rear=-1;
        }
        else{
        front=(front+1)%size;
        }
        cout<<removedval<<" id dequeued";
    }
    void peek() {
        if(isEmpty())
        {
            cout<<"queue is Empty"<<endl;
            return ;
        }
    cout<<arr[front]<<endl;
        
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"queue is Empty"<<endl;
            return;
        }
        cout<<"queue elements: "<<endl;
        int i=front;
        while(true)
        {
            cout<<arr[i]<<" ";
            if(rear==i)
            break;
            i=(i+1)%size;
        }
    }
    
};

int main()
{
   int n;
    cout << "Enter size of circular queue: ";
    cin >> n;
    Cqueue q(n);

    int choice, item;
     while (choice != 7){
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Display Queue\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> item;
                q.enqueue(item);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                if (q.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                break;
            case 4:
                if (q.isFull())
                    cout << "Queue is full." << endl;
                else
                    cout << "Queue is not full." << endl;
                break;
            case 5:
                q.display();
                break;
            case 6:
               q.peek();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }


    return 0;
}