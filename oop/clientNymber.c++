#include "iostream"
#include "string"
using namespace std;

class clientNumber
{
  private:
  string name;
  string number;

  public:
  void setData(string cname , string cnumber)
  {
    name = cname;
    number = cnumber;
  }
  string getName()
  {
    return name;
  }
    string getNumber()
  {
    return number;
  }
    
  string changeName(string cname)
  {
    name = cname;
    return name;
  }
};


  void print(clientNumber& client1)
{
  cout << "Client Name: " << client1.getName() << endl;
  cout << "Client Number: " << client1.getNumber() << endl;
  cout << "name after change : " << client1.changeName("esraa") << endl;
}




int main() {
    clientNumber client1 = clientNumber();
    client1.setData("asmaaelkashef", "123456");
    print(client1);
    return 0;
}