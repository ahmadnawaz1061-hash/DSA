#include <iostream>
using namespace std;
int main(){
    //part 1
    int n;
    
    bool validStudent = true;
    while(validStudent){
        cout << "Enter number of students: " ;
        cin >> n;
        if(n<=0){
            cout<<"Invalid number of studetns.\n";            
        }
        else{
            validStudent = false;
        }
    }
    
    int* marks = new int[n];
    
    for(int i=0; i<n; i++){
        bool validMarks = true;
        while(validMarks){
            cout<< "Enter marks of student " << i+1 << ": ";
            cin >> *(marks + i);
            if(*(marks + i) < 0 || *(marks + i) > 100){
                cout <<"Invalid marks.\n";
            }
            else{
                validMarks = false;
            }
        }
    }

    // part 2
    int total = 0;
    int count =0;
    cout << "Marks of students are: ";
    for(int i =0; i<n; i++){
        cout << *(marks + i) << " ";
        total += *(marks + i);
        if(*(marks + i) > 50){
            count++;
        }
    }
    cout << "\nTotal marks: " << total ;
    float avg = total/ float(n) ;
    cout << "\nAverage marks: " << avg;
    cout << "\nNumber of students having marks greater than 50: " << count;
    
    //part 3
    delete[] marks;
    marks = nullptr;
    return 0;
}
