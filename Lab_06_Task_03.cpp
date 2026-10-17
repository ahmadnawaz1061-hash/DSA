//Muhammad Ahmad Nawaz
//544090
//BS CS 15D

#include <iostream>
#include <string>
using namespace std;

char items[20];
int top = -1;
void push(char value){
    if(top == 19){
        cout << "Stack full!\n";
    } 
    else{
        top++;
        items[top] = value;
    }
}
char pop(){
    if(top == -1){
        return '\0'; // Return null char if empty
    } 
    else{
        char val = items[top];
        top--;
        return val;
    }
}
int main(){
    string word;
    cout << "Enter a word (up to 20 characters): ";
    cin >> word;
    if(word.length() > 20){
        cout << "Word is too long. Limiting to 20 characters.\n";
        word = word.substr(0, 20);
    }
    //pushing each character
    for(int i = 0; i < word.length(); i++){
        push(word[i]);
    }
    //poping to reverse
    cout << "Reversed word: ";
    while(top != -1){
        cout << pop();
    }
    cout << endl;
    //testing a one-letter word
    cout << "\n---Testing one letter word---\n";
    string oneLetter = "A";
    push(oneLetter[0]);
    cout << "Original: A | Reversed: " << pop() << "\n";
    return 0;
}