#include "iostream"
using namespace std;

class Area
{
public:
  double height;
  double width;
  double raduis;
  double base;

public:
  double getHeight()
  {
    cout << "Enter height: ";
    cin >> height;
    if (height <= 0)
    {
      cout << "error";
      "enter height again";
      cin >> height;
    }
    return height;
  }
  double getwidth()
  {
    cout << "Enter width: ";
    cin >> width;
    if (width <= 0)
    {
      cout << "error";
      "enter width again";
      cin >> width;
    }
    return width;
  }
  double getraduis()
  {
    cout << "Enter width: ";
    cin >> raduis;
    if (raduis <= 0)
    {
      cout << "error";
      "enter raduis again";
      cin >> raduis;
    }
    return raduis;
  }
  double getbase()
  {
    cout << "Enter base: ";
    cin >> base;
    if (base <= 0)
    {
      cout << "error";
      "enter base again";
      cin >> base;
    }
    return base;
  }
};

int main()
{
  int choice;
  cout << "Geometry calculater" << endl;
  cout << "enter 1 to calculate circle area \n"
       << "enter 2 to calculate rectangle area \n"
       << "enter 3 to calculate triangle area " << endl;
  cin >> choice;

  if (choice >= 4 || choice <= 0)
  {
    cout << "error";
    return 1;
  }

  switch (choice)
  {
  case 1:
  {
    Area circle;
    double r = circle.getraduis();
    cout << "area of the circle is " << r * r * 22 / 7;
    break;
  }
  case 2:
  {
    Area rectangle;
    double h = rectangle.getHeight();
    double w = rectangle.getwidth();
    cout << "Rectangle area is: " << h * w;
    break;
  }
  case 3:
  {
    Area triangle;
    double b = triangle.getbase();
    double height = triangle.getHeight();
    cout << "Triangle area is: " << 0.5 * b * height;
    break;
  }
  }
  return 0;
}