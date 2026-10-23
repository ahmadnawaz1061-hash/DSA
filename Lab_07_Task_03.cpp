//Muhammad Ahmad Nawaz
//CMS ID: 544090
//BS CS 15D

#include <iostream>
using namespace std;

class CircularQueue{
private:
    int items[5];
    int front;
    int rear;
    const int SIZE = 5;

public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }
    bool IsEmpty(){
        return front == -1;
    }
    bool IsFull() {
        return (rear + 1) % SIZE == front;
    }
    void Enqueue(int value){
        if(IsFull()){
            cout << "Insertion rejected: Queue is full.\n";
            return;
        }
        if(IsEmpty()){
            front = 0;
            rear = 0;
        } 
        else{
            rear = (rear + 1) % SIZE;
        }
        items[rear] = value;
        cout << "Enqueued: " << value << "\n";
    }
    void Dequeue(){
        if(IsEmpty()){
            cout << "Deletion rejected: Queue is empty.\n";
            return;
        }
        cout << "Dequeued: " << items[front] << "\n";
        
        if(front == rear){ // Last element removed
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
    void Display(){
        if(IsEmpty()){
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while(true){
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << "\n(Front index = " << front << ", Rear index = " << rear << ")\n";
    }
};

int main(){
    CircularQueue cq;
    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);
    cq.Enqueue(40);
    cq.Enqueue(50);
    
    cq.Dequeue();
    cq.Dequeue();
    
    // Freed positions can be reused without shifting
    cq.Enqueue(60);
    cq.Enqueue(70);
    
    // Should display 30 40 50 60 70 with front=2, rear=1
    cq.Display();
    
    // Reject another insertion
    cq.Enqueue(80); 
    
    cout << "\n--- Emptying the queue ---\n";
    cq.Dequeue(); // 30
    cq.Dequeue(); // 40
    cq.Dequeue(); // 50
    cq.Dequeue(); // 60
    cq.Dequeue(); // 70
    
    // Test one further dequeue
    cq.Dequeue();
    
    // Test insertion into an empty queue again
    cout << "\n--- Insert into empty queue again ---\n";
    cq.Enqueue(99);
    cq.Display();
    return 0;
}