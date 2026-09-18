#include <iostream>
using namespace std;
int main(){
    int sales[2][3];
    int (*rowPtr)[3] = sales;
    //Part 1
    //Reading sales
    cout << "Enter sales:";
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            do {
                cout <<"\nBranch " << i+1 << ", Day " << j+1 << ": " ;
                cin >> *(*(rowPtr + i) + j);
                if(*(*rowPtr + i) + j < 0){
                    cout << "Sales cant be negative. Try again: \n";
                }
            } while(*(*rowPtr + i) + j < 0);
        }
    }
    //Displaying results
    cout << "\n===Sales Table===" << endl;
    cout << "\t  Day 1\tDay 2\tDay 3\n";
    for(int i=0; i<2; i++){
        cout << "\nBranch " << i+1 << "\t";
        for(int j=0; j<3; j++){
            cout << *(*(rowPtr + i) + j) << "\t";
        }
        cout << endl;
    }

    //Part 2
    //Branch Total
    for(int i=0; i<2; i++){
        int branchTotal = 0;
        for(int j=0; j<3; j++){
            branchTotal += *(*(rowPtr + i) + j);
        }
        cout << "Total for Branch " << i+1 << ": " << branchTotal << endl;
    }
    //Day total
    for(int j=0; j<3; j++){
        int dayTotal = 0;
        for(int i=0; i<2; i++){
            dayTotal += *(*(rowPtr + i) + j);
        }
        cout << "Total for Day " << j+1 << ": " << dayTotal << endl;

    }
    return 0;
    
}