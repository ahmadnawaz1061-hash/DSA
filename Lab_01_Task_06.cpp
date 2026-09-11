#include <iostream>
using namespace std;
int main(){
    const int SIZE = 10;
    int array[SIZE];
    cout<<"Enter 10 numbers: ";
    for(int i=0; i<SIZE; i++){
        cin >> array[i];
    }
    int uniqueCount = 0;
    for(int i=0; i<SIZE; i++){
        int current = array[i];
        bool isDuplicate = false;
        for(int j=0; j<uniqueCount; j++){
            if(array[j]== current){
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate){
            array[uniqueCount] = current;
            uniqueCount++;
        }
    }

    cout << "\nUnique Values: ";
    for(int i=0; i<uniqueCount; i++){
        cout<< array[i] << " ";
    }
    cout<<"\nCount of unique values: " << uniqueCount << endl;
    
    return 0;
}