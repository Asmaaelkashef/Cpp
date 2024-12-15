#include <iostream>
#include <string>
using namespace std;
class person
{
protected:
  string name;
  int age;
  long nationalId;
public:
  void getinfo(string name, int age, long nationalId)
  {
    cout << "information is" << endl;
    cout << "----------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "National ID: " << nationalId << endl;
  }};
class student : public person
{ private:
  double GPA;
  string grade;
  public:
  student()
  {
    GPA = 0;
    grade = "";
    name = "";
    age = 0;
    nationalId = 0;
  }

  student(string name, int age, long nationalId, double GPA, string grade)
  {
    person :: getinfo(name, age, nationalId);
    cout << "GPA: " << GPA << endl;
    cout << "Grade: " << grade << endl;
}

  void setStudentData(double cgpa, string cgrade, string cname, int cage, long cnationalId)
  {
    this->GPA = cgpa;
    this->grade = cgrade;
    this->name = cname;
    this->age = cage;
    this->nationalId = cnationalId;
  }
  double getGPA()
  {
    return GPA;
  }
  string getGrade()
  {
    return grade;
  }
  string getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }
  long getNationalId()
  {
    return nationalId;
  }
};

class employee : public person
{
private:
  double salary;
  string jobTitle;

public:
  employee()
  {
    salary = 0;
    jobTitle = "";
    name = "";
    age = 0;
    nationalId = 0;
  }

  employee(string name, int age, long nationalId, string jobTitle, double salary)
  {
    cout << "Student information is" << endl;
    cout << "----------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "National ID: " << nationalId << endl;
    cout << "GPA: " << jobTitle << endl;
    cout << "Grade: " << salary << endl;
  }
  void setemployeeData(double csalary, string cjobTitle, string cname, int cage, long cnationalId)
  {
    this->salary = csalary;
    this->jobTitle = cjobTitle;
    this->name = cname;
    this->age = cage;
    this->nationalId = cnationalId;
  }
  double getsalary()
  {
    return salary;
  }
  string getjobTitle()
  {
    return jobTitle;
  }
  string getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }
  long getNationalId()
  {
    return nationalId;
  }
};

int main()
{
  int choice;
  string name;
  int age;
  long nationalId;
  float GPA;
  string jobTitle;
  string grade;
  float salary;
  cout << "student enter 1 , employee enter 2 " << endl;
  cin >> choice;
  if (choice == 1)
  {
    //student s;
    cout << "hello ! enter your information" << endl;
    cout << "----------------------------" << endl;
    cout << "enter student name : " << endl;
    cin >> name;
    cout << "enter student age : " << endl;
    cin >> age;
    cout << "enter student national id : " << endl;
    cin >> nationalId;
    cout << "enter student GPA : " << endl;
    cin >> GPA;
    cout << "enter student grade : " << endl;
    cin >> grade;
    student s(name, age, nationalId, GPA, grade);
  }
  else if (choice == 2)
  {
    //employee e;
    cout << "hello ! enter your information" << endl;
    cout << "----------------------------" << endl;
    cout << "enter student name : " << endl;
    cin >> name;
    cout << "enter student age : " << endl;
    cin >> age;
    cout << "enter student national id : " << endl;
    cin >> nationalId;
    cout << "enter employee job title : " << endl;
    cin >> jobTitle;
    cout << "enter employee salary : " << endl;
    cin >> salary;
    employee e(name, age, nationalId, jobTitle, salary);
  }
  else
  {
    cout << "invalid choice" << endl;
  }
  return 0;
}