//Muhammad Ahmad Nawaz
//CMS ID: 544090
//BS CS 15D


#include <iostream>
using namespace std;

class LinkedStack {
private:
    struct node {
        int data;
        node* next;
    };
    node* top;

public:
    LinkedStack() {
        top = nullptr;
    }

    bool IsEmpty() {
        return top == nullptr;
    }

    void Push(int value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = top; // Connect new node to old top
        top = newNode;       // New node becomes top
        cout << "Pushed " << value << ".\n";
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Pop rejected: Stack Underflow (Empty).\n";
            return;
        }
        node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        cout << "Popped: " << poppedValue << endl;
    }

    void Peek() {
        if (IsEmpty()) {
            cout << "Peek rejected: Stack is empty.\n";
        } else {
            cout << "Top element is: " << top->data << endl;
        }
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        node* curr = top;
        cout << "Stack (top to bottom): ";
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void ClearStack() {
        while (!IsEmpty()) {
            node* temp = top;
            top = top->next;
            delete temp;
        }
        cout << "Stack cleared.\n";
    }

    ~LinkedStack() {
        ClearStack();
    }
};

int main() {
    LinkedStack stack;
    int choice, value;

    do {
        cout << "\n--- Linked Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.Push(value);
                break;
            case 2:
                stack.Pop();
                break;
            case 3:
                stack.Peek();
                break;
            case 4:
                stack.Display();
                break;
            case 5:
                cout << "Exiting...\n";
                // Destructor automatically calls ClearStack()
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

/*
 1. Explain LIFO: LIFO stands for Last-In, First-Out. Imagine a stack of plates. 
    The last plate you put on top is the first one you have to remove. In data structures, 
    the newest element added (Push) is the very first one to be removed (Pop).

 2. Compare fixed capacity vs Dynamic Growth:
    - ArrayStack has a hard-coded limit of 5. Once filled, memory is wasted if empty, 
      and it limits the program if we need to store a 6th item.
    - LinkedStack dynamically asks the heap for memory every time we push, and returns 
      it every time we pop. It never gets full unless RAM runs out and scales perfectly to 
      the number of items needed.
*/