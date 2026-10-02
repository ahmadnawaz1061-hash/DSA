//Muhammad Ahmad Nawaz
//544090
//BS CS 15 D
#include <iostream>
using namespace std;

class List {
private:
    struct node {
        int data;
        node* next;
    };
    node* head;

public:
    List() {
        head = nullptr;
    }

    void PrintList() {
        if (head == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }
        node* curr = head;
        cout << "List elements: ";
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void AddNode(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    int CountNodes() {
        int count = 0;
        node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    void ClearList() {
        node* curr = head;
        while (curr != nullptr) {
            node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
    }

    ~List() {
        ClearList();
    }
};

int main() {
    List myList;
    int n;

    cout << "Enter a non-negative number of elements (n): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cout << "Enter element " << i + 1 << ": ";
        cin >> val;
        myList.AddNode(val);
    }

    cout << "\nFinal List:\n";
    myList.PrintList();
    cout << "Total nodes: " << myList.CountNodes() << endl;

    return 0;
}