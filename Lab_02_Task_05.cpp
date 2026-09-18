#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter number of initial students (1-10): ";
    cin >> n;
    while (n < 1 || n > 10) {
        cout << "Invalid. Must be between 1 and 10. Enter again: ";
        cin >> n;
    }
    int* marks = new int[n];
    cout << "Enter " << n << " marks (0 to 100):\n";
    for (int i = 0; i < n; i++) {
        cin >> *(marks + i);
    }
    int newMark;
    cout << "Enter the new mark to add: ";
    cin >> newMark;

    //part 1
    int* newMarks = new int[n + 1];
    //copying original n values into the new block using pointer notation
    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);
    }
    *(newMarks + n) = newMark;

    //part 2
    delete[] marks;   
    marks = newMarks; 
    n++;          
    // Display all v
    cout << "\nUpdated marks (" << n << " total):\n";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    cout << endl;

    //part 3
    delete[] marks;
    marks = nullptr;

    return 0;
}