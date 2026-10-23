//Muhammad Ahmad Nawaz
//CMS ID: 544090
//BS CS 15D

#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int items[5];
    int front;
    int rear;
    const int SIZE = 5;

public: 
    ArrayQueue() {
        front = -1;
        rear = -1;
    }
    bool IsEmpty() {
        return front == -1;
    }
    bool IsFull() {
        return rear == SIZE - 1;
    }
    void Enqueue(int value) {
        if(IsFull()){
            cout << "Insertion rejected: Queue is full.\n";
            return;
        }
        if(IsEmpty()){
            front = 0;
        }
        rear++;
        items[rear] = value;
        cout << "Enqueued: " << value << "\n";
    }
    void Dequeue() {
        if(IsEmpty()){
            cout << "Deletion rejected: Queue is empty.\n";
            return;
        }
        cout << "Dequeued: " << items[front] << "\n";
        //reseting indices if the last item is removed
        if(front == rear){
            front = -1;
            rear = -1;
        } 
        else{
            front++;
        }
    }
    void Peek() {
        if(IsEmpty()){
            cout << "Peek rejected: Queue is empty.\n";
        } 
        else{
            cout << "Front element: " << items[front] << "\n";
        }
    }
    void Display() {
        if(IsEmpty()){
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for(int i = front; i <= rear; i++){
            cout << items[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    ArrayQueue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    
    q.Dequeue();
    q.Dequeue();
    
    //attempting to enqueue 60 (should reject as earlier positions are unused but rear is 4)
    q.Enqueue(60); 
    //it should show 30, 40, 50
    q.Display();
    cout << "\n--- Emptying the queue ---\n";
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();    
    //testing another dequeue from empty
    q.Dequeue(); 
    cout << "\n--- Verifying reuse after reset ---\n";
    q.Enqueue(70);
    q.Display();
    return 0;
}
