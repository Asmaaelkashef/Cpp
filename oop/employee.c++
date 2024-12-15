#include <iostream>
#include <string.h>
using namespace std;
class employee
{
  private:
  int idNumber;
  string name;
  string department;
  string position;
  public:
  employee()
  {
    idNumber = 0;
    name = "";
    department = "";
    position = "";
  }
  employee(string name, int idNumber, string department, string position)
  {
    this->idNumber = idNumber;
    this->name = name;
    this->department = department;
    this->position = position;
  }
  employee(int idNumber, string name , string department, string position)
  {
    this->idNumber = idNumber;
    this->name = name;
    this->department = "";
    this->position = "";
  }
  void setData(string cname , int cidNumber, string cdepartment, string cposition)
  {
    this->name = cname;
    this->idNumber = cidNumber;
    this->department = cdepartment;
    this->position = cposition;
  }
  string getName() {return name;}
  int getIdNumber() {return idNumber;}
  string getDepartment() {return department;}
  string getPosition() {return position;}
};
int main()
{
  employee emp1("susan meyers", 47899 , "Accounting", "vice president");
  employee emp2("mark jones", 39119 , "IT", "programmer");
  employee emp3("joy rogers", 81774 , "Manufactoring", "Engineer");
}