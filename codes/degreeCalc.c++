#include <iostream>

using namespace std;
int main ()
{
float degrees;

cout << "Enter your degrees: ";
cin >> degrees;

if (degrees > 30  && degrees < 60)
{
    cout << "Your grade is d \n";
}
else if (degrees > 60 && degrees < 90)
{
    cout << "Your grade is c \n";
}
else
{
    cout << "Your grade is A \n";
}
 return 0;
 }
