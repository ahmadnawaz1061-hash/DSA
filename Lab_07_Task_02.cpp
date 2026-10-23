//Muhammad Ahmad Nawaz
//CMS ID: 544090
//BS CS 15D

#include <iostream>
using namespace std;

class LinkedQueue{
private:
    struct node{
        int data;
        node* next;
    };
    node* front;
    node* rear;

public:
    LinkedQueue(){
        front = nullptr;
        rear = nullptr;
    }
    bool IsEmpty(){
        return front == nullptr;
    }
    void Enqueue(int value){
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;
        if(IsEmpty()){
            front = newNode;
            rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << "\n";
    }
    void Dequeue(){
        if(IsEmpty()){
            cout << "Deletion rejected: Queue is empty.\n";
            return;
        }
        node* temp = front;
        cout << "Dequeued: " << temp->data << "\n";
        front = front->next;
        //reseting rear if the last node is deleted
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
    }
    void Peek(){
        if(IsEmpty()){
            cout << "Peek rejected: Queue is empty.\n";
        }
        else{
            cout << "Front element: " << front->data << "\n";
        }
    }
    void Display(){
        if(IsEmpty()){
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        node* curr = front;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }
    void ClearQueue(){
        while(!IsEmpty()){
            node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }
    ~LinkedQueue() {
        ClearQueue();
    }
};

int main() {
    LinkedQueue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    
    q.Dequeue();
    
    //it should show 20, 30
    q.Display();
    
    //it must show 20
    q.Peek();
    
    cout << "\n--- Testing empty queue mechanics ---\n";
    q.Dequeue(); 
    q.Dequeue(); 
    
    q.Dequeue(); //testing an empty queue deletion
    
    cout << "\n--- Inserting after queue becomes empty ---\n";
    q.Enqueue(40);
    q.Display();

    return 0;
}
