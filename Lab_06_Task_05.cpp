//Muhammad Ahmad Nawaz
//544090
//BS CS 15D

#include <iostream>
using namespace std;

int items[5];
int front = -1;
int rear = -1;
const int SIZE = 5;
void enqueue(int value){
    if(rear == SIZE - 1){
        cout << "Insertion blocked: Queue is full!\n";
    } 
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        items[rear] = value;
        cout << "Inserted " << value << "\n";
    }
}
void dequeue(){
    if(front == -1){
        cout << "Removal blocked: Queue is empty!\n";
    } 
    else{
        cout << "Removed: " << items[front] << "\n";
        //reset to -1 if last item is removed
        if(front == rear){
            front = -1;
            rear = -1;
            cout << "[Queue empty, indices reset to -1]\n";
        } 
        else{
            front++;
        }
    }
}
void peekFront(){
    if(front == -1){
        cout << "Queue is empty!\n";
    } 
    else{
        cout << "Front item is: " << items[front] << "\n";
    }
}
void display(){
    if(front == -1){
        cout << "Queue is empty!\n";
    } 
    else{
        cout << "Queue (front to rear): ";
        for(int i = front; i <= rear; i++){
            cout << items[i] << " ";
        }
        cout << "\n";
    }
}
int main() {
    //inserting
    enqueue(10);
    enqueue(20);
    enqueue(30);
    //removing once, then peek and display
    dequeue();
    peekFront();
    display();
    //removing all remaining
    cout << "\n---Removing all remaining items---\n";
    dequeue();
    dequeue();
    //trying another removal
    dequeue(); 
    // Inserting 40
    cout << "\n---Inserting after reset---\n";
    enqueue(40);
    display();
    return 0;
}