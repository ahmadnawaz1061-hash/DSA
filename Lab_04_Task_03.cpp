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

    void SearchNode(int searchData) {
        node* curr = head;
        int position = 1;
        bool found = false;

        while (curr != nullptr) {
            if (curr->data == searchData) {
                cout << "Value " << searchData << " found at position " << position << endl;
                found = true;
                break;
            }
            curr = curr->next;
            position++;
        }

        if (!found) {
            cout << "Value not found" << endl;
        }
    }

    void PrintSecondNode() {
        if (head == nullptr || head->next == nullptr) {
            cout << "Fewer than two nodes exist." << endl;
        } else {
            cout << "The second node contains: " << head->next->data << endl;
        }
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

    //Testing on empty list
    cout << "---Testing Empty List---" << endl;
    myList.PrintSecondNode();
    myList.SearchNode(20);

    myList.AddNode(10);
    myList.AddNode(20);
    myList.AddNode(30);
    myList.AddNode(20);

    cout << "\n---Testing Populated List---" << endl;
    myList.PrintList();
    myList.PrintSecondNode();

    cout << "\nSearching for 20:" << endl;
    myList.SearchNode(20);

    cout << "\nSearching for 99:" << endl;
    myList.SearchNode(99);

    return 0;
}