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

    void CreateThreeNodes() {
        int v1, v2, v3;
        cout << "Enter 3 integers: ";
        cin >> v1 >> v2 >> v3;

        node* n1 = new node;
        n1->data = v1;
        n1->next = nullptr;

        node* n2 = new node;
        n2->data = v2;
        n2->next = nullptr;

        node* n3 = new node;
        n3->data = v3;
        n3->next = nullptr;

        head = n1;
        n1->next = n2;
           n2->next = n3;
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

    cout << "Empty list:\n";
    myList.PrintList();

    cout << "\nCreating 3 nodes...\n";
    myList.CreateThreeNodes();

    cout << "\nPrinting list after creation:\n";
    myList.PrintList();

    return 0;
}