#include "iostream"
#include "string.h"
using namespace std;

class account {
private:
  long id;
  const float interest = 0.23;
  double balance;
  string bankName;

public:
  account() {
    id = 0;
    balance = 0.00;
    bankName = "";
  }

  account(long cid, double cbalance, string cbankName) {
    id = cid;
    balance = cbalance;
    bankName = cbankName;
  }

  void setId(long cid) {
    id = cid;
  }

  void setBalance(double cbalance) {
    balance = cbalance;
  }

  void setbankName(string cbankName) {
    bankName = cbankName;
  }

  long getId() {
    return id;
  }

  double getBalance() {
    return balance;
  }

  string getbankName() {
    return bankName;
  }

  int WithDraw(double amount) {
    if (amount <= balance) {
      balance -= amount;
    } else {
      cout << "Insufficient balance!" << endl;
    }
    return balance;
  }

  int Deposite(double amount) {
    balance += amount;
    return balance;
  }

  void calcInterest() {
    balance = balance + balance * interest;
  }

  void print() {
    cout << "Bankname is: " << bankName << endl;
    cout << "ID is: " << id << endl;
    cout << "Balance is: " << balance << endl;
  }
};

int main() {
  account a1(178417264912747, 20, "bankAlahly");
  a1.WithDraw(40);
  a1.print();
}
