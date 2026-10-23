//Muhammad Ahmad Nawaz
//CMS ID: 544090
//BS CS 15D

/*
 How a deque differs from a queue:
 A standard Queue strictly follows FIFO (First-In, First-Out), meaning we can ONLY 
 insert items at the back (rear) and ONLY remove items from the front. 
 A Deque (Double-Ended Queue) provides far more flexibility. It allows insertion AND 
 deletion at BOTH ends (front and rear). This makes a deque capable of acting as a 
 Queue, a Stack, or a hybrid of both simultaneously.
*/

#include <iostream>
using namespace std;

class LinkedDeque {
private:
    struct node {
        int data;
        node* next;
        node* prev;
    };
    node* front;
    node* rear;

public:
    LinkedDeque() {
        front = nullptr;
        rear = nullptr;
    }

    bool IsEmpty() {
        return front == nullptr;
    }

    void InsertFront(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = front;

        if (IsEmpty()) {
            rear = newNode;
        } else {
            front->prev = newNode;
        }
        front = newNode;
        cout << "Inserted " << value << " at front.\n";
    }

    void InsertRear(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = rear;

        if (IsEmpty()) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        cout << "Inserted " << value << " at rear.\n";
    }

    void DeleteFront() {
        if (IsEmpty()) {
            cout << "Deletion rejected: Deque is empty.\n";
            return;
        }
        node* temp = front;
        cout << "Deleted " << temp->data << " from front.\n";
        
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; // Deque became empty
        } else {
            front->prev = nullptr;
        }
        delete temp;
    }

    void DeleteRear() {
        if (IsEmpty()) {
            cout << "Deletion rejected: Deque is empty.\n";
            return;
        }
        node* temp = rear;
        cout << "Deleted " << temp->data << " from rear.\n";
        
        rear = rear->prev;
        if (rear == nullptr) {
            front = nullptr; // Deque became empty
        } else {
            rear->next = nullptr;
        }
        delete temp;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque elements (front to rear): ";
        node* curr = front;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    void ClearDeque() {
        while (!IsEmpty()) {
            node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        cout << "Deque cleared.\n";
    }

    ~LinkedDeque() {
        ClearDeque();
    }
};

int main() {
    LinkedDeque ld;
    int choice, value;

    ld.InsertRear(20);
    ld.InsertFront(10);
    ld.InsertRear(30);
    ld.Display(); // Expect 10, 20, 30

    ld.DeleteFront();
    ld.DeleteRear();
    ld.Display(); // Expect 20

    ld.DeleteFront(); // Delete remaining node
    cout << "Inserting again after emptying...\n";
    ld.InsertFront(50);
    ld.DeleteRear(); // Removing only node from opposite end
    ld.Display();

    cout << "\n--- Menu ---\n";
    do {
        cout << "\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value: "; cin >> value;
                ld.InsertFront(value);
                break;
            case 2:
                cout << "Value: "; cin >> value;
                ld.InsertRear(value);
                break;
            case 3:
                ld.DeleteFront();
                break;
            case 4:
                ld.DeleteRear();
                break;
            case 5:
                ld.Display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    // ClearDeque is automatically called by destructor before exiting.
    return 0;
}