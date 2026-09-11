#include<iostream>
using namespace std;

class Student{
public:
    int rollNumber;
    int marks;
    void display(){
        cout << "Roll Number: " << rollNumber;
        cout << "\nMarks: " << marks;
    }
};

int main(){
    Student s1, s2;
    s1.rollNumber = 1;
    s1.marks = 75;
    s2.rollNumber = 2;
    s2.marks = 90;

    cout<< "Student 1: \n";
    s1.display();
    cout<< "\n\nStudent 2: \n";
    s2.display();
    //Expected Output:
    //Student 1:
    //Roll Number: 1
    //Marks: 75
    //Student 2:
    //Roll Number: 2
    //Marks: 90

    s1.marks = 80;
    cout<< "\n\nStudent 1: \n";
    s1.display();
    cout<< "\n\nStudent 2: \n";
    s2.display();

    //s2's marks will not change bcz each object is independent of other. if we modify an object it doesnt affect any other object.

    return 0;
}