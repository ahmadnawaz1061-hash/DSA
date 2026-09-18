#include <iostream>
using namespace std;
int main() {
    int n = 3;
    int* values = new int[n];

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) { // < instead of <= 
        cin >> values[i];
    }
    cout << "\nYou entered:\n";
    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
    delete[] values;
    values = nullptr;
    return 0;
}