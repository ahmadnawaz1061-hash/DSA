// Muhammad Ahmad Nawaz
// 544090
// BS CS 15 D

#include<iostream>
using namespace std;
struct Student{
    int rollNo;
    string name;
    float marks;
};
int main(){
    Student s ;
    Student* p = &s;
    cout << "Enter the student name: ";
    getline(cin, p->name);
    cout << "Enter the student roll no: ";
    cin >> s.rollNo;
    cout << "Enter the student marks: ";
    cin >> s.marks;

    cout<< "Student details are as :\nName: " << p->name;
    cout<< "\nRoll no: " << p->rollNo;
    cout << "\nMarks: " << p->marks;

    cout << "\nEnter updated marks: ";
    cin >> p->marks;
    cout<< "Updated record are as :\nName: " << p->name;
    cout<< "\nRoll no: " << p->rollNo;
    cout << "\nMarks: " << p->marks;
    return 0;
}