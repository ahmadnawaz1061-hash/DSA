//Muhammad Ahmad Nawaz
//CMS ID: 544090
//BS CS 15D

#include <iostream>
using namespace std;

class DoublyList {
private:
    struct node {
        int data;
        node* next;
        node* prev;
    };
    node* head;
    node* tail;

public:
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    void AddNode(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void InsertBefore(int position, int value) {
        if (position < 1 || head == nullptr) {
            cout << "Invalid position or empty list. Insertion rejected.\n";
            return;
        }

        node* curr = head;
        int currentPos = 1;

        // Traverse to find the existing node at 'position'
        while (curr != nullptr && currentPos < position) {
            curr = curr->next;
            currentPos++;
        }

        if (curr == nullptr) {
            cout << "Position " << position << " out of bounds. Insertion rejected.\n";
            return;
        }

        node* newNode = new node;
        newNode->data = value;
        newNode->next = curr;
        newNode->prev = curr->prev;

        if (curr->prev != nullptr) {
            curr->prev->next = newNode;
        } else {
            head = newNode; 
        }
        curr->prev = newNode;
    }

    void DeleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        node* curr = head;
        while (curr != nullptr && curr->data != value) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Value " << value << " not found.\n";
            return;
        }

        // Adjust previous node's link
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        } else {
            head = curr->next;
        }

        // Adjust next node's link
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        } else {
            tail = curr->prev;
        }

        delete curr;
        cout << "Deleted " << value << " from the list.\n";
    }

    void PrintForward() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        node* curr = head;
        cout << "Forward: ";
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void PrintReverse() {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        node* curr = tail;
        cout << "Reverse: ";
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

    void ClearList() {
        node* curr = head;
        while (curr != nullptr) {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyList() {
        ClearList();
    }
};

int main() {
    DoublyList list;
    
    // Testing based on prompt requirements
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    cout << "Initial list:\n";
    list.PrintForward();
    list.PrintReverse();

    cout << "\nInserting 15 before position 2:\n";
    list.InsertBefore(2, 15);
    list.PrintForward();
    list.PrintReverse();

    cout << "\nDeleting 20:\n";
    list.DeleteNode(20);
    list.PrintForward();
    list.PrintReverse();

    cout << "\nInserting before head (pos 1):\n";
    list.InsertBefore(1, 5);
    list.PrintForward();

    cout << "\nDeleting head (5) and tail (30):\n";
    list.DeleteNode(5);
    list.DeleteNode(30);
    list.PrintForward();

    cout << "\nDeleting only node left (10) and (15):\n";
    list.DeleteNode(10);
    list.DeleteNode(15);
    list.PrintForward(); // Should be empty

    cout << "\nDeleting from empty list:\n";
    list.DeleteNode(99);

    return 0;
}