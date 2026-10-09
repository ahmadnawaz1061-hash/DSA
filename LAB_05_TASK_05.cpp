//Muhammad Ahmad Nawaz
//CMS ID: 544090
//BS CS 15D


#include <iostream>
using namespace std;

class ArrayStack {
private:
    int items[5];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    bool IsEmpty() {
        return top == -1;
    }

    bool IsFull() {
        return top == 4;
    }

    void Push(int value) {
        if (IsFull()) {
            cout << "Push rejected: Stack Overflow (Full).\n";
        } else {
            top++;
            items[top] = value;
            cout << "Pushed " << value << ".\n";
        }
    }

    void Pop() {
        if (IsEmpty()) {
            cout << "Pop rejected: Stack Underflow (Empty).\n";
        } else {
            cout << "Popped: " << items[top] << endl;
            top--;
        }
    }

    void Peek() {
        if (IsEmpty()) {
            cout << "Peek rejected: Stack is empty.\n";
        } else {
            cout << "Top element is: " << items[top] << endl;
        }
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayStack stack;

    // Test filling the stack
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);
    
    cout << "\nRejecting 6th push:\n";
    stack.Push(60);

    cout << "\nDisplaying stack:\n";
    stack.Display();

    cout << "\nPopping 50:\n";
    stack.Pop();
    
    cout << "Peeking (should be 40):\n";
    stack.Peek();

    cout << "\nEmptying the stack:\n";
    stack.Pop(); // 40
    stack.Pop(); // 30
    stack.Pop(); // 20
    stack.Pop(); // 10

    cout << "\nTesting one further pop on empty stack:\n";
    stack.Pop();

    return 0;
}