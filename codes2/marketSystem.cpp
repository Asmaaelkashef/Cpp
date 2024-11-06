#include "iostream"
#include "string.h"
using namespace std;

class market
{
private:
  long ID;
  string name;
  double price;
  double profit;
  string expireDate;
  double quantity;

public:
  market() // defult constructor
  {
    ID = 0;
    name = "";
    price = 0;
    profit = 0;
    expireDate = "";
    quantity = 0;
  }
  void setData(long cid, double cprice, double cprofit, string cexpireDate, double cquantity, string cname)
  {
    ID = cid;
    price = cprice;
    profit = cprofit;
    expireDate = cexpireDate;
    quantity = cquantity;
    name = cname;
  }

  long getId() { return ID; }
  string getname() { return name; }
  double getprice() { return price; }
  double getProfit() { return profit; }
  string getexpireDate() { return expireDate; }
  double getQuantity() { return quantity; }

  // عشان نحسب السحب ومنطلعش حاجة بالسالب لو السحب اكبر من الكمية الي عندي
  double withdraw(double amount)
  {
    if (quantity >= amount)
    {
      quantity -= amount;
      return amount;
    }
    else
    {
      cout << "Not enough quantity" << endl;
      return 0;
    }
  }
  // عشان احسب الشراء
  double deposite(double amount)
  {
    quantity += amount;
    return amount;
  }
  void calcInterst()
  {
    profit = profit + profit * 0.10;
  }
};

int main()
{
  market m;
  m.setData(12334, 50, 25, "25/7/2025", 100, "cheese");
  cout << "ID: " << m.getId() << endl;
  cout << "Name: " << m.getname() << endl;
  cout << "Price: " << m.getprice() << endl;
  cout << "Profit: " << m.getProfit() << endl;
  cout << "Expire Date: " << m.getexpireDate() << endl;
  cout << "Quantity: " << m.getQuantity() << endl;
}