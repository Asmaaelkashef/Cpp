#include "iostream"
#include "string.h"
using namespace std;

//سؤال مهم جدا في العملي
//امتي بنستدعي الكونستركتور ؟. لحظة انشاء الاوبجكت و مينفعش انادي عالكونستركتور بعد انشاء الاوبجكت ولازم اكون عارفة فين الكونستركتور لازمم

class account {
  private:
  long id;
  const float interest = 0.23;
  double balance;
  string bankName;

  public:
  account()
  {
    id = 0;
    balance = 0.00;
    bankName = "";
  }
  account(long cid ,double  cbalance , string cbankName)
  {
    cid = id;
    cbalance = balance;
    cbankName = bankName;
  } 

  void setId(long cid)
  {
    cid = cid;
  } 
  void setBalance(double cbalance)
  {
    cbalance = balance;
  } 
  void setbankName(string cbankName)
  {
    cbankName = bankName;
  } 
  double getId(long id)
  {
    return id;
  } 
  double getBalance(double balance)
  {
    return balance;
  } 
  string getbankName(string bankName)
  {
    return bankName;
  } 
  int WithDraw(double amount)
  {
    balance -= amount;
    return balance;
  }
  int Deposite(double amount)
  {
    balance += amount;
    return balance;
  }
  void calcInterst()
  {
    balance = balance + balance*interest;
  }
  void print()
  {
    cout << "Bankname is: " << bankName << endl;
    cout << "ID is: " << id << endl;
    cout << "balance is : " << balance << endl;
  }
};

int main(){
  account a1(178417264912747 , 17000 , "bankAlahly");
  a1.WithDraw(457);
  a1.print();
};
