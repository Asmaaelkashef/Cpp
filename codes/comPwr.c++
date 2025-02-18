#include <iostream>

using namespace std;

double calcPwr(double base , double exponent)
{
  double result = 1.00 ;
  for (int i = 0 ; i < exponent ; i++)
  {
    result *= base ;
  }
  return result ;
}

int main ()
{
  double base , exponent ;
  cout << "enter base : " ;
  cin >> base ;
  cout << "enter exponent : ";
  cin >> exponent ;
  cout << "power is : " << calcPwr(base , exponent) ;
  return 0 ;
}