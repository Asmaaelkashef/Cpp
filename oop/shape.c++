#include "iostream"
using namespace std;

class shape{
  protected:
    double perim;

  public:
   virtual void setData(double x, double y , double z) = 0;
   virtual void showData() = 0;
   virtual double getPerim() = 0;
};

class rectangle : public shape
{
  protected:
  double length, width;

  public:
   void setData(double x, double y , double z)
   {
     length = x;
     width = y;
   }
   void showData()
   {
     cout << "Length: " << length << endl;
     cout << "Width: " << width << endl;
   }
   double getPerim()
   {
     perim = 2*(length + width);
     return perim;
   }
};

class triangle : public shape
{
  private:
  double side1 ,  side2 , side3 ;

  public:
   void setData(double x, double y, double z)
   {
     side1 = x;
     side2 = y;
     side3 = z;
   }
   void showData()
   {
     cout << "Side 1: " << side1 << endl;
     cout << "Side 2: " << side2 << endl;
     cout << "Side 3: " << side3 << endl;
   }
   double getPerim()
   {
     return side1 + side2 + side3;
   }
};

int main()
{
  shape* ptr[5];
  rectangle obj[5];
  triangle obj2[5];
  double length , width , height;

  for (int i = 0; i < 5; i++)
  {
    cout << "shape is rectangle or triangle , 1 for rectangle, 2 for triangle" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
      ptr[i] = &obj[i];
      cout << "enter length : " << endl;
      cin >> length;
      cout << "enter width : " << endl;
      cin >> width;
      ptr[i] -> setData(length , width , 0);
    }
    if (choice == 2)
    {
      ptr[i] = &obj2[i];
      cout << "enter length : " << endl;
      cin >> length;
      cout << "enter width : " << endl;
      cin >> width;
      cout << "enter height : " << endl;
      cin >> height;
      ptr[i] -> setData(length , width , height);
    }
  }
  cout << "\n Data of all shapes:" << endl;
    for (int i = 0; i < 5; i++) {
            ptr[i]->showData();
            cout << "Perimeter: " << ptr[i]->getPerim() << endl;
    }
}