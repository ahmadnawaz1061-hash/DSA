//Muhammad Ahmad Nawaz
//CMS ID: 544090
//BS CS 15D


#include <iostream>
using namespace std;

class CircularList {
private:
    struct node {
        int data;
        node* next;
    };
    node* head;
    node* tail;

public:
    CircularList() {
        head = nullptr;
        tail = nullptr;
    }

    void AddNode(int value) {
        node* newNode = new node;
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head; // Point to itself
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Preserve circular link
        }
    }

    void PrintList() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        node* curr = head;
        cout << "List: ";
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head); // Stop after one complete cycle
        cout << endl;
    }

    void CountNodes() {
        if (head == nullptr) {
            cout << "Count: 0\n";
            return;
        }
        int count = 0;
        node* curr = head;
        do {
            count++;
            curr = curr->next;
        } while (curr != head);
        cout << "Count: " << count << endl;
    }

    void ClearList() {
        if (head == nullptr) return;

        // Break the circular link first
        tail->next = nullptr;
        
        node* curr = head;
        while (curr != nullptr) {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    ~CircularList() {
        ClearList();
    }
};

int main() {
    CircularList list;
    
    cout << "Testing Empty List:\n";
    list.PrintList();
    list.CountNodes();

    cout << "\nAdding one node (10):\n";
    list.AddNode(10);
    list.PrintList();
    list.CountNodes();

    cout << "\nAdding 20 and 30:\n";
    list.AddNode(20);
    list.AddNode(30);
    list.PrintList();
    list.CountNodes();

    return 0;
}

/*
 Why would a normal nullptr-based traversal not terminate on a non-empty circular list?
 
 Answer: In a standard singly linked list, the last node points to 'nullptr', which stops the loop 
 (while curr != nullptr). In a circular linked list, the last 
 node (tail) points back to the head. There is no 'nullptr' anywhere in the ring. If we 
 checked for nullptr, the loop would just cycle around infinitely. Therefore, we must stop 
 when the traversal pointer wraps around and equals 'head' again (using a do-while loop).
*/