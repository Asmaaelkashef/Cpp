#include <iostream>

using namespace std;
int main ()
{
    int num1 , num2 , num3 , num4 , num5 , largest ;
    cout << " enter 5 numbers to compaare :";
    cin >> num1 >> num2 >> num3 >> num4 >> num5 ;

    largest = num1;
    if (num2 > largest)
        largest = num2;
    if (num3 > largest)
        largest = num3;
    if (num4 > largest)
        largest = num4 ;
    if (num5 > largest)
        largest = num5 ;

    cout << "largest is:"  << largest ;

}