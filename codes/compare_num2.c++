#include<iostream>
#include<string>
using namespace std;

int main() {

    int number = 0, largest = 0;

    for (int i = 0; i < 5; i++) {
        cout << "Enter number : ";
        cin >> number;

        if (number > largest) 
            largest = number;
            }

cout << largest << endl;
    }