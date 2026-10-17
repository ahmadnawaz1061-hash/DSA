//Muhammad Ahmad Nawaz
//544090
//BS CS 15D

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* top = nullptr;
void push(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Pushed " << value << "\n";
}
void pop(){
    if(top==nullptr){
        cout << "Pop rejected: Stack is empty!\n";
    }
    else{
        Node* temp = top;
        cout << "Popped: " << temp->data << "\n";
        top = top->next;
        delete temp;
    }
}
void peek(){
    if(top==nullptr){
        cout << "Peek rejected: Stack is empty!\n";
    }
    else{
        cout << "Top element is: " << top->data << "\n";
    }
}
void display(){
    if(top==nullptr){
        cout << "Peek rejected: Stack is empty!\n";
    }
    else{
        cout << "Stack(Top to bottom): ";
        Node* curr = top;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}
int main() {
    push(5);
    push(15);
    push(25);
    display();
    //poping & peeking
    pop();
    peek();
    
    cout << "\n---Testing Empty Pop---\n";
    pop();
    pop();
    pop(); //empty pop test
    
    //cleanup remaining nodes before exit
    while (top != nullptr) {
        pop();
    }
    return 0;
}