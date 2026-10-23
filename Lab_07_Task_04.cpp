//Muhammad Ahmad Nawaz
//CMS ID: 544090
//BS CS 15D

#include <iostream>
using namespace std;

class CircularQueue {
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
    bool IsEmpty(){ return front == -1; }
    bool IsFull(){ return (rear + 1) % SIZE == front; }

    void Enqueue(int value){
        if (IsFull()) return;
        if (IsEmpty()) front = rear = 0;
        else rear = (rear + 1) % SIZE;
        items[rear] = value;
    }

    int Dequeue(){
        if (IsEmpty()) return -1;
        int val = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } 
        else{
            front = (front + 1) % SIZE;
        }
        return val;
    }

    void Display(){
        if (IsEmpty()){
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }

    void RotateTurn(){
        if (IsEmpty()){
            cout << "No students to serve!\n";
            return;
        }
        int servedID = Dequeue();
        cout << "Served ID: " << servedID << "\n";
        Enqueue(servedID);
        Display();
    }
};

int main() {
    CircularQueue cq;

    // Standard sequence
    cq.Enqueue(101);
    cq.Enqueue(102);
    cq.Enqueue(103);

    cout << "Initial Queue:\n";
    cq.Display();

    cout << "\n--- Simulating 5 turns ---\n";
    for (int i = 1; i <= 5; i++) {
        cout << "Turn " << i << ":\n";
        cq.RotateTurn();
        cout << "\n";
    }

    // Testing an empty queue
    CircularQueue emptyQ;
    cout << "--- Testing Empty Queue Rotation ---\n";
    emptyQ.RotateTurn();

    // Testing queue with one student
    CircularQueue singleQ;
    singleQ.Enqueue(999);
    cout << "\n--- Testing One Student Queue Rotation ---\n";
    singleQ.Display();
    singleQ.RotateTurn();

    return 0;
}