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
        if(front == -1){ //first insertion
            front = 0;
        }
        rear++;
        items[rear] = value;
        cout << "Inserted " << value << " to rear.\n";
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
    //testing
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    cout << "\n---Filling the queue---\n";
    enqueue(40);
    enqueue(50);
    cout << "\n---One more insertion---\n";
    enqueue(60); //should print block message
    return 0;
}