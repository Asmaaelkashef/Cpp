#include <iostream>

class myClass 
{
  protected:
  int numbers;

  public:
  void myFunction()
  {
    std::cout << "hello " ;
  }
  void setnum(int n)
  {
    //n = 10;
    numbers = n;
  }
};

class mychild 
{

};

class myGrandChild : public mychild , public myClass
{

};

int main()
{
  myGrandChild obj1;
  obj1.myFunction();
  obj1.setnum(1);
  return 0;
}
