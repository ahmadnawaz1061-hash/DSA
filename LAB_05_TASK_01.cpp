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

        if (head == nullptr) { // Empty list
            head = newNode;
            tail = newNode;
        } else { // Append using tail
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
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
    
    cout << "--- Testing Empty List ---\n";
    list.PrintForward();
    list.PrintReverse();

    int count;
    cout << "\nEnter a non-negative count to append: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        int val;
        cout << "Enter value " << i + 1 << ": ";
        cin >> val;
        list.AddNode(val);
    }

    cout << "\n--- Output after appending ---\n";
    list.PrintForward();
    list.PrintReverse();

    return 0;
}