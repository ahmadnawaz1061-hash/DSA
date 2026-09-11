#include <iostream>
using namespace std;
int main(){
    int array[8];
    
    cout << "Enter 8 numbers: ";
    for(int i=0; i<8; i++){
        cin >> array[i];
    }
    int largest = array[0];
    int smallest = array[0];
    int largest_index = 0;
    int smallest_index = 0;

    for(int i=0; i<8; i++){
        if(array[i] > largest){
            largest = array[i];
            largest_index = i;
        }
        if(array[i] < smallest){
            smallest = array[i];
            smallest_index = i;
        }
    }

    //as we have used < and > in above conditions so it always reports first occurence  
    cout << "The largest value is " << largest << " at index " << largest_index;
    cout << "\nThe smallest value is " << smallest << " at index " << smallest_index;
    return 0;
}