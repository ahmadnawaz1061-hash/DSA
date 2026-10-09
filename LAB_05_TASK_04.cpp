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
            tail->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void DeleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Value " << value << " not found.\n";
            return;
        }

        node* curr = head;
        node* prev = tail; // Keep track of the node right before 'curr'
        bool found = false;

        // One-cycle search
        do {
            if (curr->data == value) {
                found = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (!found) {
            cout << "Value " << value << " not found.\n";
            return;
        }

        // Case 1: Deleting the only node
        if (curr == head && curr == tail) {
            delete curr;
            head = nullptr;
            tail = nullptr;
        }
        // Case 2: Deleting the head node
        else if (curr == head) {
            head = head->next;
            tail->next = head; // preserve circular property
            delete curr;
        }
        // Case 3: Deleting the tail node
        else if (curr == tail) {
            prev->next = head;
            tail = prev; // update tail
            delete curr;
        }
        // Case 4: Deleting a middle node
        else {
            prev->next = curr->next;
            delete curr;
        }

        cout << "Deleted " << value << ".\n";
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
        } while (curr != head);
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

    // Build 10, 20, 30
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(30);
    
    cout << "Initial list:\n";
    list.PrintList();
    list.CountNodes();

    cout << "\nDeleting 10:\n";
    list.DeleteNode(10);
    list.PrintList();
    list.CountNodes();

    cout << "\nDeleting 30:\n";
    list.DeleteNode(30);
    list.PrintList();
    list.CountNodes();

    cout << "\nDeleting 20:\n";
    list.DeleteNode(20);
    list.PrintList();
    list.CountNodes();

    cout << "\n--- Testing Edge Cases ---\n";
    // Test empty list, missing value, duplicates
    list.DeleteNode(99); 
    
    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20); // duplicate
    list.AddNode(30);
    
    cout << "\nList with duplicates:\n";
    list.PrintList();
    
    cout << "\nDeleting 20 once:\n";
    list.DeleteNode(20);
    list.PrintList(); // Expect 10, 20, 30

    return 0;
}