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
void displayStudent(const Student* s){
    if(s != nullptr){
        cout<< "Student details are as :\nName: " << s->name;
        cout<< "\nRoll no: " << s->rollNo;
        cout << "\nMarks: " << s->marks;
    }
}
void updateMarks(Student* s, float newMarks){
    if(s != nullptr){
        s->marks = newMarks;
    }
}
int main(){
    Student* s = new Student{};
    cout << "Enter the student name: ";
    getline(cin, s->name);
    cout << "Enter the student roll no: ";
    cin >> s->rollNo;
    cout << "Enter the student marks: ";
    cin >> s->marks;

    
    displayStudent(s);
    float newMarks;
    cout << "\nEnter new marks: ";
    cin >> newMarks;
    updateMarks(s, newMarks);
    displayStudent(s);
    delete s;
    s = nullptr;
    return 0;
}