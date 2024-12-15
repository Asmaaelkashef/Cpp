#include <iostream>
#include <string.h>
using namespace std;
class circle
{
  private:
  double radius;
  const double Pi = 3.14159;
  public:
  circle(double r)
  {radius = r;} 
  circle()
  {radius = 0;}
  void setRadius(double r)
  {radius = r;}
  double getRadius()
  {return radius;}
  double getArea()
  {return Pi * radius * radius;}
  double getDiameter()
  {return 2 * radius;}
  double getCircumference()
  {return 2 * Pi * radius;}
};
int main()
{ int r;
  cout << "Enter radius of circle: ";
  cin >> r;
  circle c(r);
  cout << "Area: " << c.getArea() << endl;
  cout << "Diameter: " << c.getDiameter() << endl;
  cout << "Circumference: " << c.getCircumference() << endl;
  return 0; }