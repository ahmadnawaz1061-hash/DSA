#include <iostream>
using namespace std;
int main(){
    int rows;
    int cols;

    //part 1 & 2
    cout << "Enter number of students: " ;
    cin >> rows;
    while(rows<=0){
        cout << "Invalid. Must be greater than 0. Enter again: ";
        cin >> rows;
    }
    cout << "Enter number of subjects: ";
    cin >> cols;
    while(cols<=0){
        cout << "Invalid. Must be greater than 0. Enter again: ";
        cin >> cols;
    }

    int** marks = new int*[rows];
    for(int i=0; i<rows; i++){
        *(marks + i) = new int[cols];
    }

    //part 3
    //reading marks
    cout <<"\nEnter marks(0-100):\n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << "Student "<< i+1 << ", Subect " << j+1 << ": ";
            cin >> *(*(marks + i) + j);
        }
    }
    //displaying marks
    cout << "=== Marks Matrix ===" << endl;
    for (int r = 0; r < rows; r++) {
        cout << "Student " << (r + 1) << ":\t";
        for (int c = 0; c < cols; c++) {
            cout << *(*(marks + r) + c) << "\t";
        }
        cout << endl;
    }

    //step 4
    int bestStudent = 1;
    int highestTotal = 0;
    
    cout << "\n=== Student Totals ===" << endl;
    for (int i = 0; i < rows; i++) {
        int currentTotal = 0;
        for (int j = 0; j < cols; j++) {
            currentTotal += *(*(marks + i) + j);
        }
        cout << "Student " << i + 1 << " Total: " << currentTotal << endl;

        if (i==0 || currentTotal>highestTotal) {
            highestTotal = currentTotal;
            bestStudent = i + 1;
        }
    }
    cout << "\nTop Performer: Student " << bestStudent << " with a total of " << highestTotal << endl;

    //part 5
    for(int i=0; i<rows; i++){
        delete[] *(marks + i);
    }
    delete[] marks;
    marks = nullptr;
    
    return 0;
}