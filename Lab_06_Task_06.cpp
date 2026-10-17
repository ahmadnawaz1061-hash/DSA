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
    int choice;
    int token = 1;
    do {
        cout << "\n---Customer Service Menu---\n";
        cout << "1. Add customer\n";
        cout << "2. Serve next\n";
        cout << "3. View next\n";
        cout << "4. Display queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                enqueue(token);
                if(rear != SIZE - 1 || front == -1){ //increment only if it actually added
                    token++; 
                }
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peekFront();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting system.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 5);
    return 0;
}
// EXPLANATION:
// In a linear array queue, rear index simply moves to right as items are enqueued, and front moves to the right as they are dequeued. 
// If we enqueue until rear hits the end and then dequeue a few items, space opens up at indices 0 and 1. However, because this is a basic linear queue ,
// we cannot reuse those earlier spaces until the ENTIRE queue empties and front and rear both reset to -1. That is why insertion stays blocked even if we have served 2 customers.