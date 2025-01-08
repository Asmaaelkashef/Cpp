#include <iostream>

class two
{
  public:
  int b;
  two(int b)
  {
    this->b = b;
  }
  void jjj(){std::cout<<"hh";}
};
class three : public two 
{
  public:
  int c;
  three(int c , int b , int a) : two(b)
  {
    this->c = c;
  }
};
int main(){
  three obj(1,2,3);
  obj.jjj();
}
