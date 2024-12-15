#include "iostream"
#include "string.h"
using namespace std;
class vehicle
{
  protected:
  double mileage;
  double price;
};
class car : public vehicle
{
  protected:
  double ownershipCost;
  int warranty;
  int seatingCapacity;
  string fuelType;
};
class bike : public vehicle
{
  protected:
  int cylinders;
  int gears;
  string coolingType;
  string wheelType;
  double fuelTankSize;
};
class audi : public car
{
  private:
  string modelType;
  public:
  void setData(string m ,double cownershipCost , int cwarranty ,int  cseatingCapacity , string cfuelType , double mile , double cprices)
  {
    modelType = m;
    ownershipCost = cownershipCost;
    warranty = cwarranty;
    seatingCapacity = cseatingCapacity;
    fuelType = cfuelType;
    mileage = mile;
    price = cprices;
  }
  void printData()
  {
    cout << "Model Type: " << modelType << endl;
    cout << "Ownership Cost: " << ownershipCost << endl;
    cout << "Warranty: " << warranty << endl;
    cout << "Seating Capacity: " << seatingCapacity << endl;
    cout << "Fuel Type: " << fuelType << endl;
    cout << "Mileage: " << mileage << endl;
    cout << "Price: " << price << endl;
  }
};
class ford : public car
{
  private:
  string modelType;
  public:
  void setData(string m ,double cownershipCost , int cwarranty ,int  cseatingCapacity , string cfuelType , double mile , double cprices)
  {
    modelType = m;
    ownershipCost = cownershipCost;
    warranty = cwarranty;
    seatingCapacity = cseatingCapacity;
    fuelType = cfuelType;
    mileage = mile;
    price = cprices;
  }
  void printData()
  {
    cout << "Model Type: " << modelType << endl;
    cout << "Ownership Cost: " << ownershipCost << endl;
    cout << "Warranty: " << warranty << endl;
    cout << "Seating Capacity: " << seatingCapacity << endl;
    cout << "Fuel Type: " << fuelType << endl;
    cout << "Mileage: " << mileage << endl;
    cout << "Price: " << price << endl;
  }
};
class bajaj : public bike
{
  private:
  string makeType;
  public:
  void setData(string m , int ccylinders , int cgears , string ccoolingType , string cwheelType , double cfuelTankSize , double mile , double cprices)
  {
    makeType = m;
    cylinders = ccylinders;
    gears = cgears;
    coolingType = ccoolingType;
    wheelType = cwheelType;
    fuelTankSize = cfuelTankSize;
    mileage = mile;
    price = cprices;
  }
  void printData()
  {
    cout << "Make Type: " << makeType << endl;
    cout << "Cylinders: " << cylinders << endl;
    cout << "Gears: " << gears << endl;
    cout << "Cooling Type: " << coolingType << endl;
    cout << "Wheel Type: " << wheelType << endl;
    cout << "Fuel Tank Size: " << fuelTankSize << endl;
    cout << "Mileage: " << mileage << endl;
    cout << "Price: " << price << endl;
  }
};
class TVS : public bike
{
  private:
  string makeType;
  public:
  void setData(string m , int ccylinders , int cgears , string ccoolingType , string cwheelType , double cfuelTankSize , double mile , double cprices)
  {
    makeType = m;
    cylinders = ccylinders;
    gears = cgears;
    coolingType = ccoolingType;
    wheelType = cwheelType;
    fuelTankSize = cfuelTankSize;
    mileage = mile;
    price = cprices;
  }
  void printData()
  {
    cout << "Make Type: " << makeType << endl;
    cout << "Cylinders: " << cylinders << endl;
    cout << "Gears: " << gears << endl;
    cout << "Cooling Type: " << coolingType << endl;
    cout << "Wheel Type: " << wheelType << endl;
    cout << "Fuel Tank Size: " << fuelTankSize << endl;
    cout << "Mileage: " << mileage << endl;
    cout << "Price: " << price << endl;
  }
};
