// Muhammad Ahmad Nawaz
// 544090
// BS CS 15 D

#include <iostream>
using namespace std;
struct Student{
    int rollNo;
    string name;
    float marks;
};
int main(){
    Student s ;
    cout << "Enter the student name: ";
    getline(cin, s.name);
    cout << "Enter the student roll no: ";
    cin >> s.rollNo;
    cout << "Enter the student marks: ";
    cin >> s.marks;

    cout<< "Student details are as :\nName: " << s.name;
    cout<< "\nRoll no: " << s.rollNo;
    cout << "\nMarks: " << s.marks;
    return 0;
}