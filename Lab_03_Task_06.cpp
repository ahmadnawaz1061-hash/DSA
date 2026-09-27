// Muhammad Ahmad Nawaz
// 544090
// BS CS 15 D

#include<iostream>
#include<string>
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

void updateMarks(Student* s, float newMarks){
    if(s != nullptr){
        s->marks = newMarks;
    }
}

int main(){
    Student* s = nullptr;
    int choice;
    do{
        cout << "---Menu---" << endl;
        cout << "1. Create record" << endl;
        cout << "2. Display record" << endl;
        cout << "3. Update marks" << endl;
        cout << "4. Delete record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                if(s != nullptr){
                    cout << "Error: A record already exists. Delete it before creating a new one.\n";
                }
                else{
                    s = new Student{};
                    cin.ignore(); 
                    cout << "Enter the student name: ";
                    getline(cin, s->name);  
                    cout << "Enter the student roll no: ";
                    cin >> s->rollNo;  
                    cout << "Enter the student marks: ";
                    cin >> s->marks;
                    cout << "Record created successfully.\n";
                }
                break;
            case 2:
                displayIfExist(s);
                break;
            case 3:
                if(s==nullptr){
                    cout << "Error: No record available to update.\n";
                }
                else{
                    float newMarks;
                    cout << "Enter new marks: ";
                    cin >> newMarks;
                    updateMarks(s, newMarks);
                    cout << "Marks updated successfully!\n";
                }
                break;
            case 4:
                if(s == nullptr){
                    cout <<"Error: No record availabel to delete.\n";
                }
                else{
                    delete s;
                    s = nullptr;
                    cout << "Record deleted successfully!\n";
                }
                break;
            case 5:
                if(s!=nullptr){
                    delete s;
                    s = nullptr;
                }
                cout <<"Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please choose an option between 1 and 5.\n";
            
                
        }
    }while(choice != 5);

    return 0;
}