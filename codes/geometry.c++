#include <iostream>
using namespace std;

// calculate circle area
int circle(int radius)
{
  cout << "enter raduis:";
  cin >> radius;
  if (radius <= 0)
  {
    cout << "error";
    "enter raduis again";
    cin >> radius;
  }
  cout << "area equal " << 22 / 7 * radius * radius << endl;
  return 0;
}
// calculate triangle area
int triangle(int height, int base)
{
  cout << "enter height: ";
  cin >> height;
  cout << "enter base: ";
  cin >> base;
  if (height <= 0 || base <= 0)
  {
    cout << "error";
    cout << "enter height: ";
    cin >> height;
    cout << "enter base: ";
    cin >> base;
  }
  cout << "area equal " << 0.5 * base * height;
  return 0;
}
// calculate rectangle area
int rectangle(int height, int width)
{
  cout << "enter height: ";
  cin >> height;
  cout << "enter width:  ";
  cin >> width;
  if (height <= 0 || width <= 0)
  {
    cout << "error";
  }
  cout << "area equal " << width * height;
  return 0;
}
int main()
{
  int choice;
  cout << "Geometry calculater" << endl;
  cout << "enter 1 to calculate circle area \n"
       << "enter 2 to calculate rectangle area \n"
       << "enter 3 to calculate triangle area " << endl;
  cin >> choice;

  if (choice <= 4 || choice <= 0)
  {
    cout << "error";
  }

  switch (choice)
  {
  case 1:
    circle(0);
  case 2:
    rectangle(0, 0);
  case 3:
    triangle(0, 0);
  }
};