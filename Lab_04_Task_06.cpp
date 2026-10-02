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

    void InsertAtBeginning(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << addData << " at the beginning.\n";
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
        cout << "Inserted " << addData << " at the end.\n";
    }

    void SearchNode(int searchData) {
        node* curr = head;
        int position = 1;
        bool found = false;

        while (curr != nullptr) {
            if (curr->data == searchData) {
                cout << "Value " << searchData << " found at position " << position << ".\n";
                found = true;
                break;
            }
            curr = curr->next;
            position++;
        }

        if (!found) {
            cout << "Value not found.\n";
        }
    }

    void DeleteNode(int delData) {
        if (head == nullptr) {
            cout << "List is empty, cannot delete.\n";
            return;
        }

        if (head->data == delData) {
            node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << delData << " from the list.\n";
            return;
        }

        node* curr = head;
        while (curr->next != nullptr && curr->next->data != delData) {
            curr = curr->next;
        }

        if (curr->next == nullptr) {
            cout << "Value " << delData << " not found in the list.\n";
        } else {
            node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            cout << "Deleted " << delData << " from the list.\n";
        }
    }

    void PrintList() {
        if (head == nullptr) {
            cout << "The list is empty!\n";
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

    void CountNodes() {
        int count = 0;
        node* curr = head;
        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        cout << "Total number of nodes: " << count << endl;
    }

    void PrintSecondNode() {
        if (head == nullptr || head->next == nullptr) {
            cout << "Fewer than two nodes exist.\n";
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
    int choice;
    int value;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Search by value\n";
        cout << "4. Delete by value\n";
        cout << "5. Display all nodes\n";
        cout << "6. Count nodes\n";
        cout << "7. Display second node\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                myList.InsertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                myList.AddNode(value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                myList.SearchNode(value);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                myList.DeleteNode(value);
                break;
            case 5:
                myList.PrintList();
                break;
            case 6:
                myList.CountNodes();
                break;
            case 7:
                myList.PrintSecondNode();
                break;
            case 8:
                cout << "Cleaning up memory and exiting...\n";
                myList.ClearList();
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}