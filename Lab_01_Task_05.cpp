#include <iostream>
using namespace std;
void reverseArray(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, start+1, end-1);
}
int main(){
    const int SIZE = 6;
    int array[SIZE];
    cout << "Enter 6 numbers: ";
    for(int i=0; i<SIZE; i++){
        cin >> array[i];
    }
    reverseArray(array, 0, SIZE-1);


    cout << "The reversed array is: ";
    for(int i=0; i<SIZE; i++){
        cout << array[i] << " ";
    }
    return 0;
} 