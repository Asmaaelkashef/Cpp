#include <iostream>
using namespace std;
class shape
{
protected:
  double perim;

public:
  void setdata( double per)
  {
    perim = per ;
  }
  void showdata();
  double getPerim();
};

class rectangle : public shape
{
private:
  double length, width;

public:
  rectangle()
  {
    length = 0;
    width = 0;
    if (length <= 0 || width <= 0)
    {
      cout << "Invalid input. Length and width must be positive. " << endl;
    }
  }
  void setdata()
  {
    cout << "Enter length and width: ";
    cin >> length >> width;
  }
  void showdata()
  {
    cout << "Length: " << length << endl
         << "Width: " << width << endl;
  }
  double getwidth() { return width; }
  double getlength() { return length; }
  double getPerim()
  {
    return 2 * (length + width);
  }
};

int main()
{
  rectangle r;
  r.setdata();
  r.showdata();
  cout << "Perimeter of rectangle: " << r.getPerim() << endl;
  return 0;
}
