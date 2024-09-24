#include <iostream>

using namespace std;
int main ()
{
    int num_one;
    int num_two;

    cout << "ENTER 2 NUMBERS : ";
    cin >> num_one , num_two ;

    if (num_one % num_two == 0)
    {
        cout << num_one << "is multiple" << num_two;
    }
    else
    {
        cout << num_one << " is  not multiple "<< num_two;
    }

    return 0;
}