#include <iostream>
#include <string.h>
using namespace std;
class complex
{
private:
  double real, image;

public:
  complex()
  {
    real = 0.00;
    image = 0.0;
  }
  void setDate(double r, double g)
  {
    real = r;
    image = g;
  }
  float getReal() { return real; }
  float getImage() { return image; }
  complex operator=(complex c)
  {
    real = c.real;
    image = c.image;
    return *this;
  }
  complex operator-(complex c)
  {
    complex x;
    c.real = real * c.real;
    c.image = real * c.image;
    return x;
  }
  complex operator*(complex c)
  {
    complex x;
    c.real = real * c.real - image * c.image;
    c.image = real * c.image + image * c.real;
    return x;
  }
  complex operator/(complex c)
  {
    complex x;
    double denominator = c.real * c.real + c.image * c.image;
    c.real = (real * c.real + image * c.image) / denominator;
    c.image = (image * c.real - real * c.image) / denominator;
    return x;
  }
  void display()
  {
    cout << real << " + " << image << "i" << endl;
  }
};
int main()
{
  complex c1, c2, result;
  c1.setDate(78.0, 4.0);
  c2.setDate(17.0, 2.0);
  result = c1 - c2;
  result.display();
  result = c1 * c2;
  result.display();
  result = c1 / c2;
  result.display();
  return 0;
}