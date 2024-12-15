#include <iostream>
#include <string.h>
using namespace std;
class tempreture
{
  private:
  double ftemp_A;
  public:
  tempreture(double Ft) { ftemp_A = Ft;}
  void setFahrenheit(double ft) { ftemp_A = ft; }
  double getFahrenheit() { return ftemp_A; }
  double getCelsius() { return (ftemp_A - 32) * 5.0/9.0; }
  double getKelvin() { return (ftemp_A + 459.67) * 5.0/9.0; }
};
int main ()
{
  double ftemp_A;
  cout << "Enter temperature in Fahrenheit: ";
  cin >> ftemp_A;
  tempreture temp(ftemp_A);
  cout << "Temperature in Celsius: " << temp.getCelsius() << endl;
  cout << "Temperature in Kelvin: " << temp.getKelvin() << endl;
}