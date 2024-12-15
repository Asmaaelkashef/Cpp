#include <iostream>
#include <string.h>
using namespace std;
class retailItem
{
private:
  string description;
  double price;
  int unitsOnHand;
public:
  retailItem(string d, double p, int u)
  {
    this->description = d;
    this->price = p;
    this->unitsOnHand = u;
  }
  void setData(string d, double p, int u)
  {
    description = d;
    price = p;
    unitsOnHand = u;
  }
  string getDescription() { return description; }
  double getPrice() { return price; }
  int getUnitsOnHand() { return unitsOnHand; }
};
int main ()
{
  retailItem Item1("jacket" , 59.95 , 12);
  retailItem Item2("Designer Jeans" , 34.95 , 40);
  retailItem Item3("Shirt" , 24.95 , 20);
}