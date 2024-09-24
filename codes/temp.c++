#include <iostream>
using namespace std;

int main ()
{
    double tempreture_f;
    
    cout << "enter tempreture_f:" << endl;
    cin >> tempreture_f;

    double c ;
    c = (5.0 / 9.0)*(tempreture_f - 32.0);
    cin >> c ;

    cout << " tempreture:" << c << endl;
    return 0;

}