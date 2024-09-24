#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main ()
{
    string number;
    cout << "enter number:";
    cin >> number;
    if (number.length() != 5 )
    {
        cout << "error";
        return 1;
    }

    string number2 = number;
    reverse(number2.begin(), number2.end());

    if (number == number2)
    {
        cout << "number is plaindrome";
    }
    else
    {
        cout << "number is not plaindrome";
    }
    
    return 0;
}