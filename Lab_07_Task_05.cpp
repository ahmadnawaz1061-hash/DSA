//Muhammad Ahmad Nawaz
//CMS ID: 544090
//BS CS 15D

#include <iostream>
using namespace std;

class ArrayDeque {
private:
    int items[5];
    int front;
    int rear;
    const int SIZE = 5;

public:
    ArrayDeque() {
        front = -1;
        rear = -1;
    }

    bool IsEmpty() { return front == -1; }
    bool IsFull() { return (rear + 1) % SIZE == front; }

    void InsertFront(int value) {
        if (IsFull()) {
            cout << "Insertion rejected: Deque is full.\n";
            return;
        }
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            front = (front + SIZE - 1) % SIZE; // Move backward circularly
        }
        items[front] = value;
        cout << "Inserted " << value << " at front.\n";
    }

    void InsertRear(int value) {
        if (IsFull()) {
            cout << "Insertion rejected: Deque is full.\n";
            return;
        }
        if (IsEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        items[rear] = value;
        cout << "Inserted " << value << " at rear.\n";
    }

    void DeleteFront() {
        if (IsEmpty()) {
            cout << "Deletion rejected: Deque is empty.\n";
            return;
        }
        cout << "Deleted " << items[front] << " from front.\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void DeleteRear() {
        if (IsEmpty()) {
            cout << "Deletion rejected: Deque is empty.\n";
            return;
        }
        cout << "Deleted " << items[rear] << " from rear.\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            rear = (rear + SIZE - 1) % SIZE; // Move backward circularly
        }
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque elements (front to rear): ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

int main() {
    ArrayDeque dq;

    // Test sequence 1
    dq.InsertRear(20);
    dq.InsertFront(10);
    dq.InsertRear(30);
    dq.Display(); // Expect: 10 20 30

    dq.DeleteRear();
    dq.DeleteFront();
    dq.Display(); // Expect: 20

    // Test sequence 2
    dq.InsertFront(5);
    dq.InsertRear(30);
    dq.InsertRear(40);
    dq.InsertFront(1);
    dq.Display(); // Expect: 1 5 20 30 40

    // Reject further insertions
    cout << "\n--- Testing Full Rejections ---\n";
    dq.InsertFront(99);
    dq.InsertRear(100);

    // Test deletion of only value from each end in separate runs, followed by empty
    cout << "\n--- Testing Emptying Deque ---\n";
    dq.DeleteFront(); // 1
    dq.DeleteFront(); // 5
    dq.DeleteRear();  // 40
    dq.DeleteRear();  // 30
    dq.DeleteFront(); // 20 (Last item)
    
    cout << "\n--- Deleting from empty ---\n";
    dq.DeleteFront();
    dq.DeleteRear();

    return 0;
}