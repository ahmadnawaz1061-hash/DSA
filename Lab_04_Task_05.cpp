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

    void AddNode(int addData) {
        node* newNode = new node;
        newNode->data = addData;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } 
        else {
            node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void DeleteNode(int delData) {
        //handling empty list
        if (head == nullptr) {
            cout << "List is empty. Value " << delData << " not found." << endl;
            return;
        }

        //handling deletion if its first node
        if (head->data == delData) {
            node* temp = head;
            head = head->next; //updating head to second node
            delete temp;
            return;
        }

        //handling middle or last node
        node* curr = head;
        //traversing until we find the node before one we want to delete
        while (curr->next != nullptr && curr->next->data != delData) {
            curr = curr->next;
        }

        //if we reached the end and didn't find the value
        if (curr->next == nullptr) {
            cout << "Value " << delData << " not found in the list." << endl;
        } 
        else {
            //we found it curr->next is the node to delete.
            node* temp = curr->next;
            //bypassing the node
            curr->next = curr->next->next;
    
            delete temp;
        }
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

    cout << "Deleting from an empty list test:" << endl;
    myList.DeleteNode(50);

    myList.AddNode(10);
    myList.AddNode(20);
    myList.AddNode(20);
    myList.AddNode(30);

    cout << "\nInitial list created:" << endl;
    myList.PrintList();

    cout << "\nDeleting 20 once (testing middle deletion & duplicates):" << endl;
    myList.DeleteNode(20);
    myList.PrintList();

    cout << "\nDeleting 10 (testing first node deletion):" << endl;
    myList.DeleteNode(10);
    myList.PrintList();

    cout << "\nDeleting 30 (testing last node deletion):" << endl;
    myList.DeleteNode(30);
    myList.PrintList();

    cout << "\nDeleting 99 (testing missing value):" << endl;
    myList.DeleteNode(99);
    myList.PrintList();

    cout << "\nDeleting 20 (testing deleting the only node left):" << endl;
    myList.DeleteNode(20);
    myList.PrintList();

    return 0;
}