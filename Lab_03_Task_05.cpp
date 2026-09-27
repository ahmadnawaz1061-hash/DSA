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
void displayIfExist(const Student* s){
    if(s != nullptr){
        cout<< "Student details are as :\nName: " << s->name;
        cout<< "\nRoll no: " << s->rollNo;
        cout << "\nMarks: " << s->marks << endl;
    }
    else{
        cout << "No record available." << endl;
    }
}
int main(){
    Student* s = nullptr;
    
    cout << "---Before allocation---" << endl;
    displayIfExist(s);

    s = new Student{};
    cout << "Enter the student name: ";
    getline(cin, s->name);
    cout << "Enter the student roll no: ";
    cin >> s->rollNo;
    cout << "Enter the student marks: ";
    cin >> s->marks;
    cout << "---After allocation---" << endl;
    displayIfExist(s);

    delete s;
    s = nullptr;
    cout << "---After deletion---" << endl;
    displayIfExist(s);

    return 0;
}