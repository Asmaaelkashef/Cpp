#include <iostream>

using namespace std;
int main()
{
    int r;
    cout << "enter radius : ";
    cin >> r;

    cout << "diameter : "<< 2*r <<endl ;
    cout << "circumference :"<< 2*3.14*r <<endl ;
    cout << "area :"<< 3.14*r*r <<endl;
    return 0;
}