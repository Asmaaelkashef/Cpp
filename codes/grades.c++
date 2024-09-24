#include <iostream>
using namespace std;

int main ()
{
    int degree_1;
    cout << "enter degree 1: ";
    cin >> degree_1;

    int degree_2;
    cout << "enter degree 2: ";
    cin >> degree_2;

    int degree_3;
    cout << "enter degree 3: ";
    cin >> degree_3;

    cout << "your degree is " << (degree_1 * 0.3) + (degree_2 * 0.3) + (degree_3 * 0.4) << endl;

    return 0;
}