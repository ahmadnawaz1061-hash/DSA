#include<iostream>
using namespace std;
int main(){
  const int SIZE = 5 ;
  int sales[SIZE];
  int* p = sales;

  // part 1
  cout<< "Enter 5 inetegers: " ;
  for(int i=0; i<SIZE; i++){
    cin >> *(p + i);
  }
  int total = 0;
  for(int i=0; i<SIZE; i++){
    cout << *(p + i) << " ";
    total += *(p + i);
  }
  cout << "\nTotal value: " << total << endl;

  // part 2
   *(p+2) += 2;
   cout <<"\nUpdated value: " ;
   total = 0;
   for(int i=0; i<SIZE; i++){
    cout << *(p+i) << " " ;
    total += *(p+i);
   }
   cout << "\nUpdated total: " << total << endl;
   p = nullptr;

  return  0;
}
