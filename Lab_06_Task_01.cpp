//Muhammad Ahmad Nawaz
//544090
//BS CS 15D

#include <iostream>
using namespace std;

int items[5];
int top = -1;
const int SIZE = 5;
void push(int value) {
    if (top == SIZE - 1){
        cout << "Push rejected: Stack is full!\n";
    }
    else{
        top++;
        items[top] = value;
        cout << "Pushed " << value << "\n";
    }
}
void pop(){
    if (top == -1){
        cout << "Pop rejected: Stack is empty!\n";
    } 
    else{
        cout << "Popped: " << items[top] << "\n";
        top--;
    }
}
void peek(){
    if (top == -1){
        cout << "Peek rejected: Stack is empty!\n";
    }
    else{
        cout << "Top element is: " << items[top] << "\n";
    }
}
void display() {
    if (top == -1) {
        cout << "Stack is empty!\n";
    } 
    else{
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << items[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    //Pushing
    push(10);
    push(20);
    push(30);
    display();
    //Poping
    pop();
    peek();
    //6th insertion
    cout << "\n---Testing Overflow---\n";
    push(30);
    push(40);
    push(50);
    push(60); //6th insertion should fail
    //Testing popping after removing all values
    cout << "\n---Testing Underflow---\n";
    pop();
    pop();
    pop();
    pop();
    pop();
    pop(); //should fail
    
    return 0;
}